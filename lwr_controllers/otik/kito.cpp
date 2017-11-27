
#include "ros/ros.h"
#include "lwr_controllers/PoseRPY.h"
#include <qualisys/Subject.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"

#include <sstream>


void qualisysCallback(const qualisys::Subject& submsg)
{

  std::cout<< "X ="<< submsg.position.x ;
  std::cout<< "Y ="<< submsg.position.y ;
  std::cout<< "Z ="<< submsg.position.z ;
  std::cout<< "R ="<< submsg.orientation.x ;
  std::cout<< "P ="<< submsg.orientation.y ;
  std::cout<< "Y ="<< submsg.orientation.z ;

}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "qualisysSub");


  ros::NodeHandle nh;

  
  ros::Subscriber sub = nh.subscribe("/qualisys/head2", 1000, qualisysCallback);

  ros::spin();


  return 0;
}

