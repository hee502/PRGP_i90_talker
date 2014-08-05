#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");//Create node called "talker"

  ros::NodeHandle n;//Create nodehandler to modify features of the node

  geometry_msgs::Twist cmdvel_;//commands to be sent to i90
  ros::Duration d = ros::Duration(2,0);

  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("drrobot_cmd_vel", 1);
  ros::Rate loop_rate(2);

  while (ros::ok())
  {
  cmdvel_.linear.x = 0.1;
  ROS_INFO("Speed: %f", cmdvel_.linear.x);
  pub.publish(cmdvel_);
//  d.sleep();

    ros::spinOnce();

    loop_rate.sleep();

  }

  return 0;
}

