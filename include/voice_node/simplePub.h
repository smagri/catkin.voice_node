#ifndef VOICE_NODE_SIMPLEPUB_H
#define VOICE_NODE_SIMPLEPUB_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"

// Custom message includes. Auto-generated from msg/ directory.
#include "voice_node/voice_node.h"


namespace voice_node{


  class voiceSimplePub{
  
  public:
    // Constructor.
    voiceSimplePub(ros::NodeHandle nh);
    
    // Timer callback for publishing message.
    void timerCallback(const ros::TimerEvent& event);
    
  private:
    // The timer variable used to go to callback function at specified rate.
    ros::Timer timerObj;
    
    // Message publisher.
    ros::Publisher txt4TTSpubObj;
    ros::Publisher voiceNamePubObj;

    // The actual message.
    //std::string message_;
    //std::string message_;
};


}

#endif // VOICE_NODE_SIMPLEPUB_H
