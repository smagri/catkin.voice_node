#ifndef VOICE_NODE_SIMPLESUB_H
#define VOICE_NODE_SIMPLESUB_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"

// Custom message includes. Auto-generated from msg/ directory.
// //#include "voice_node/voice_node.h"

#include "std_msgs/String.h"
#include <sstream>


namespace voice_node{


  class voiceSimpleSub{
  
  public:
    // Constructor.
    voiceSimpleSub(ros::NodeHandle nh);
    
    void txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg);
    void voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg);


  private:
    
    // Message Subscriber
    ros::Subscriber txt4TTSsubObj;
    ros::Subscriber voiceNameSubObj;
  };


} // namespace voice_node

#endif // VOICE_NODE_SIMPLESUB_H
