#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from std_srvs.srv import Trigger
from sensor_msgs.msg import Joy
from cola2_control.joystickbase import JoystickBase
# from cola2_lib_ros import param_loader
from threading import Lock
import time


class LogitechFX10(JoystickBase):
    """
    LogitechFX10 controller node.

    This class inherits from JoystickBase. It overloads the method update_joy(self, joy) that receives a
    sensor_msgs/Joy message and fills the var self.joy_msg as described in the class JoystickBase.

    From this class, it is also possible to call services or anything else reading the buttons in the update_joy method.
    """

    # JOYSTICK  DEFINITION:
    LEFT_JOY_HORIZONTAL = 0  # LEFT+, RIGHT-
    LEFT_JOY_VERTICAL = 1  # UP+, DOWN-
    LEFT_TRIGGER = 2  # NOT PRESS 1, PRESS -1
    RIGHT_JOY_HORIZONTAL = 3  # LEFT+, RIGHT-
    RIGHT_JOY_VERTICAL = 4  # UP+, DOWN-
    RIGHT_TRIGGER = 5  # NOT PRESS 1, PRESS -1
    CROSS_HORIZONTAL = 6  # LEFT+, RIGHT-
    CROSS_VERTICAL = 7  # UP+, DOWN-
    BUTTON_A = 0
    BUTTON_B = 1
    BUTTON_X = 2
    BUTTON_Y = 3
    BUTTON_LEFT = 4
    BUTTON_RIGHT = 5
    BUTTON_BACK = 6
    BUTTON_START = 7
    BUTTON_LOGITECH = 8
    BUTTON_LEFT_JOY = 9
    BUTTON_RIGHT_JOY = 10
    MOVE_UP = 1
    MOVE_DOWN = -1
    MOVE_LEFT = 1
    MOVE_RIGHT = -1

    def __init__(self, name: str):
        """Class constructor."""
        super().__init__(name)

        self.up_down = 0.0
        self.left_right = 0.0
        self.start_service = ""
        self.stop_service = ""

        self.pressed_action = 0

        # Create client to services:
        self.enable_keep_pose = None
        self.disable_keep_pose = None
        self.enable_thrusters = None
        self.disable_thrusters = None

        # Read parameters
        # self.get_logger().info(f'String start_service value: {self.get_namespace().strip('/')}')
        self.get_config()

        # Create service clients:
        if self.start_service != "":
            done = False
            while not done and rclpy.ok():
                try:
                    self.enable_keep_pose = self.create_client(Trigger, self.start_service)
                    done = True
                except Exception as e:
                    self.get_logger().warn(f"{self.name}: Service call failed: {e}")
                    time.sleep(1.0)

        if self.stop_service != '':
            self.disable_keep_pose = self.create_client(Trigger, self.stop_service)

        # Enable thrusters service
        self.enable_thrusters = self.create_client(Trigger, 'teleoperation/enable_thrusters')
        self.disable_thrusters = self.create_client(Trigger, 'teleoperation/disable_thrusters')

        # Declare the subscription to joystick messages
        self.joy_subscription = self.create_subscription(
            Joy,
            'joy',  # Modify this to the correct joystick topic
            self.update_joy,
            10
        )

        self.mutual_exclusion = Lock()

    def update_joy(self, joy: Joy):
        """Receive joystick raw data."""
        self.mutual_exclusion.acquire()

        self.joy_msg.header = joy.header

        # Transform discrete axis (cross) to two 'analog' axis to control
        # depth and yaw in position.
        if joy.axes[self.CROSS_VERTICAL] == self.MOVE_DOWN:
            self.up_down = min(self.up_down + 0.05, 1.0)
        elif joy.axes[self.CROSS_VERTICAL] == self.MOVE_UP:
            self.up_down = max(self.up_down - 0.05, -1.0)

        if joy.axes[self.CROSS_HORIZONTAL] == self.MOVE_RIGHT:
            self.left_right = min(self.left_right + 0.05, 1.0)
        elif joy.axes[self.CROSS_HORIZONTAL] == self.MOVE_LEFT:
            self.left_right = max(self.left_right - 0.05, -1.0)

        self.joy_msg.axes[JoystickBase.AXIS_POSE_Z] = self.up_down
        self.joy_msg.axes[JoystickBase.AXIS_POSE_YAW] = self.left_right
        self.joy_msg.axes[JoystickBase.AXIS_TWIST_U] = joy.axes[self.RIGHT_JOY_VERTICAL]
        self.joy_msg.axes[JoystickBase.AXIS_TWIST_V] = -joy.axes[self.RIGHT_JOY_HORIZONTAL]
        self.joy_msg.axes[JoystickBase.AXIS_TWIST_W] = -joy.axes[self.LEFT_JOY_VERTICAL]
        self.joy_msg.axes[JoystickBase.AXIS_TWIST_R] = -joy.axes[self.LEFT_JOY_HORIZONTAL]

        # Enable/disable z control position
        self.joy_msg.buttons[JoystickBase.BUTTON_POSE_Z] = joy.buttons[self.BUTTON_A]
        self.joy_msg.buttons[JoystickBase.BUTTON_TWIST_W] = joy.buttons[self.BUTTON_Y]
        if joy.buttons[self.BUTTON_A] == 1.0:
            self.up_down = 0.0
            self.get_logger().info(f"{self.name}: Reset up_down counter")

        # Enable/disable yaw control position
        self.joy_msg.buttons[JoystickBase.BUTTON_POSE_YAW] = joy.buttons[self.BUTTON_B]
        self.joy_msg.buttons[JoystickBase.BUTTON_TWIST_R] = joy.buttons[self.BUTTON_X]
        if joy.buttons[self.BUTTON_B] == 1.0:
            self.left_right = 0.0
            self.get_logger().info(f"{self.name}: Reset left_right counter")

        # Enable/disable keep position
        if joy.buttons[self.BUTTON_START] == 1.0 and self.pressed_action == 0:
            # self.get_logger().info(f"{self.name}: Keep position service called")
            future = self.enable_keep_pose.call_async(Trigger.Request())
            future.add_done_callback(self.action_finished_callback)
            self.pressed_action = 1
            # if not res.result():
            #     self.get_logger().warn(f"{self.name}: Impossible to enable keep position")
        if joy.buttons[self.BUTTON_BACK] == 1.0 and self.pressed_action == 0:
            # self.get_logger().info(f"{self.name}: Disable keep position service called")
            # self.keep_position_enabled = 0
            future = self.disable_keep_pose.call_async(Trigger.Request())
            future.add_done_callback(self.action_finished_callback)
            self.pressed_action = 1
            # if not res.result():
            #     self.get_logger().warn(f"{self.name}: Impossible to disable keep position")

        # Enable/disable thrusters
        if joy.axes[self.LEFT_TRIGGER] < -0.9 and joy.axes[self.RIGHT_TRIGGER] < -0.9 and self.pressed_action == 0:
            # self.get_logger().info(f"{self.name}: DISABLE THRUSTERS!")
            future = self.disable_thrusters.call_async(Trigger.Request())
            future.add_done_callback(self.action_finished_callback)
            self.pressed_action = 1

        if joy.buttons[self.BUTTON_LEFT] == 1.0 and joy.buttons[self.BUTTON_RIGHT] == 1.0 and self.pressed_action == 0:
            # self.get_logger().info(f"{self.name}: ENABLE THRUSTERS!")
            future = self.enable_thrusters.call_async(Trigger.Request())
            future.add_done_callback(self.action_finished_callback)
            self.pressed_action = 1
        
        self.mutual_exclusion.release()

    def action_finished_callback(self, future):
        try:
            self.pressed_action = 0
            # response = future.result()
            # self.get_logger().info(f'Response: {response.success}, {response.message}')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

    def get_config(self):
        """Read parameters from ROS 2 Parameter Server."""
        ns = self.get_namespace()[1:]
        # params = self.get_parameters_by_prefix('')
        
        # Iterate through parameters and log their name and value
        # for param in params:
        #     self.get_logger().info(f'Parameter: {param}')

        self.declare_parameter('start_service', '')
        self.declare_parameter('stop_service', '')

        self.start_service = self.get_parameter('start_service').get_parameter_value().string_value
        self.stop_service = self.get_parameter('stop_service').get_parameter_value().string_value

        self.get_logger().info(f'String start_service value: {self.start_service}')
        self.get_logger().info(f'String stop_service value: {self.stop_service}')


        # param_loader.get_ros_params(self, param_dict)

def main():
    """Initialize the LogitechFX10 node."""
    rclpy.init()
    node = LogitechFX10('logitech_fx10_to_teleoperation')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
