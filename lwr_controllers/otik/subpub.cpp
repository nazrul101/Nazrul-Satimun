
#include "ros/ros.h"
#include "lwr_controllers/PoseRPY.h"
#include <qualisys/Subject.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"

#include <sstream>

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<lwr_controllers::PoseRPY>("/lwr/one_task_inverse_kinematics/command", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/qualisys/head2", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(const qualisys::Subject& submsg)
  {
    lwr_controllers::PoseRPY msg;
    //.... do something with the input and generate the output...
    msg.id = 0;
    msg.position.x = submsg.position.x;
    msg.position.y = submsg.position.y;
    msg.position.z = submsg.position.z;
    msg.orientation.roll = submsg.orientation.x;
    msg.orientation.pitch = submsg.orientation.y;
    msg.orientation.yaw = submsg.orientation.z;
    
    pub_.publish(msg);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subpub");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
