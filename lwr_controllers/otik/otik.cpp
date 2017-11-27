
#include "ros/ros.h"
#include "lwr_controllers/PoseRPY.h"

#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "otikPub");

  ros::NodeHandle n;

  ros::Publisher otikPub_pub = n.advertise<lwr_controllers::PoseRPY>("/lwr/one_task_inverse_kinematics/command", 1000);

  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {

    lwr_controllers::PoseRPY msg;

    msg.id = 0;
    msg.position.x = -0.4;
    msg.position.y = 0.3;
    msg.position.z = 1.5;
    msg.orientation.roll = 0.1;
    msg.orientation.pitch = 0.2;
    msg.orientation.yaw = 0.0;
    
	

    otikPub_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    
  }


  return 0;
}

