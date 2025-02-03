#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from threading import Lock

# Import messages
from sensor_msgs.msg import Joy
from std_msgs.msg import String

class JoystickBase(Node):
    """ This is a base class required to transform the joy messages
    that come from a joystick to be defined to the messages required
    by the teleoperation node.

    The joy message for the teleoperation node always has the same
    structure. The axis field contains the values for pose and twist:
    --> axis: [x][y][z][roll][pitch][yaw][u][v][w][p][q][r]
    While the buttons decide if an axis is controlled in pose or in twist:
    --> buttons: [x][y][z][roll][pitch][yaw][u][v][w][p][q][r]
    """

    # 12 AXIS OUTPUT DEFINITION
    AXIS_POSE_X = 0
    AXIS_POSE_Y = 1
    AXIS_POSE_Z = 2
    AXIS_POSE_ROLL = 3
    AXIS_POSE_PITCH = 4
    AXIS_POSE_YAW = 5
    AXIS_TWIST_U = 6
    AXIS_TWIST_V = 7
    AXIS_TWIST_W = 8
    AXIS_TWIST_P = 9
    AXIS_TWIST_Q = 10
    AXIS_TWIST_R = 11

    # 12 BUTTON OUTPUT DEFINITION
    BUTTON_POSE_X = 0
    BUTTON_POSE_Y = 1
    BUTTON_POSE_Z = 2
    BUTTON_POSE_ROLL = 3
    BUTTON_POSE_PITCH = 4
    BUTTON_POSE_YAW = 5
    BUTTON_TWIST_U = 6
    BUTTON_TWIST_V = 7
    BUTTON_TWIST_W = 8
    BUTTON_TWIST_P = 9
    BUTTON_TWIST_Q = 10
    BUTTON_TWIST_R = 11

    def __init__(self, name):
        """ Constructor """
        super().__init__(name)
        self.name = name
        self.joy_msg = Joy()
        self.joy_msg.axes = [0.0] * 12  # 6 pose + 6 twist
        self.joy_msg.buttons = [0] * 12  # 6 pose + 6 twist
        self.mutual_exclusion = Lock()

        namespace = self.get_namespace()

        # Create publishers
        self.pub_map_ack_data = self.create_publisher(Joy, "input_to_teleoperation/output", 10)
        self.pub_map_ack_ack_teleop = self.create_publisher(String, "input_to_teleoperation/ack", 10)

        # Create subscribers
        self.create_subscription(String, "teleoperation/ack", self.update_ack, 10)
        self.create_subscription(Joy, "joy", self.update_joy, 10)

        # Timer to periodically call the iterate function
        self.create_timer(0.1, self.iterate)

    def update_ack(self, ack: String):
        """ Ack safety method """
        ack_list = ack.data.split()
        if len(ack_list) == 2 and ack_list[1] == 'ok':
            seq = int(ack_list[0]) + 1
            self.pub_map_ack_ack_teleop.publish(String(data=f"{seq} ack"))
        else:
            self.get_logger().error(f"{self.name}: Received invalid teleoperation heart beat!")

    def update_joy(self, joy: Joy):
        """ This method must be overloaded!"""
        self.mutual_exclusion.acquire()
        self.get_logger().info(f"{self.name}: Method update_joy must be overloaded")
        self.mutual_exclusion.release()

    def iterate(self):
        """ This method is a callback for the timer. It is used to publish the
            output joy message """
        self.mutual_exclusion.acquire()
        # Publish message
        self.pub_map_ack_data.publish(self.joy_msg)
        self.mutual_exclusion.release()

def main():
    """Initialize the JoystickBase node."""
    rclpy.init()
    node = JoystickBase('joystick_base')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
