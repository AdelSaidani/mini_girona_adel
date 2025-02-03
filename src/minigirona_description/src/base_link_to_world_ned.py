import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import tf2_ros
import geometry_msgs.msg

class OdomToTf(Node):
    def __init__(self):
        super().__init__('odom_to_tf')
        self.odom_subscriber = self.create_subscription(
            Odometry,
            'odom',  # Make sure this matches your odometry topic
            self.odom_callback,
            10
        )
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

    def odom_callback(self, msg):
        transform = geometry_msgs.msg.TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = 'world_ned'  # Set the frame_id to 'world'
        transform.child_frame_id = 'girona500/base_link'  # Set this to your robot's base frame

        # Translation from odometry
        transform.transform.translation.x = msg.pose.pose.position.x
        transform.transform.translation.y = msg.pose.pose.position.y
        transform.transform.translation.z = msg.pose.pose.position.z

        # Orientation from odometry (assumes quaternion)
        transform.transform.rotation = msg.pose.pose.orientation

        self.tf_broadcaster.sendTransform(transform)

def main(args=None):
    rclpy.init(args=args)
    odom_to_tf = OdomToTf()
    rclpy.spin(odom_to_tf)
    odom_to_tf.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
