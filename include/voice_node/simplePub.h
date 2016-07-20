#ifndef VOICE_NODE_SIMPLEPUB_H
#define VOICE_NODE_SIMPLEPUB_H

// ROS includes.
#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/String.h"

// Custom message includes. Auto-generated from msg/ directory.
// #include "voice_node/voice_node.h"

using namespace std;


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

    // The actual message strings.
    //
    // Could I alternatively use std::string or txt4TTS[100]...
    // std::string txt4TTS;
    // char txt4TTS[100];
    std_msgs::String txt4TTS;
    std_msgs::String voiceName;
    std_msgs::String voiceName1;
  };


}

#endif // VOICE_NODE_SIMPLEPUB_H
