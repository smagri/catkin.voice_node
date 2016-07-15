// ROS node  that subscribes to the txt4TTStopic.   The simplePub node
// publishes  on  the  txt4TTStopic.   This node  demonstrates  simple
// recipt  of  messages over  the  ROS  system,  or subscribing  on  a
// specific topic.
// 

#include "ros/ros.h"

#include "std_msgs/String.h"


#include "voice_node/simpleSub.h"
// Register  callback function  to  be used  in  main.  This  callback
// function  will get called  when a  new message  has arrived  on the
// txt4TTStopic.
//



namespace voice_node{
  
  voiceSimpleSub::voiceSimpleSub(ros::NodeHandle nh){
  
  // Recive messages, subscribe, on the txt4TTStopic topic:
  // Subscriber Object = txt4TTSsubObj
  // Topic Name = txt4TTStopic
  // Message Buffer Size = 1000 messages
  int nodeBufSize = 1000;
  txt4TTSsubObj
    = nh.subscribe("txt4TTStopic", nodeBufSize, txt4TTStopicCallback);
  voiceNameSubObj
    = nh.subscribe("voiceNameTopic", nodeBufSize, voiceNameTopicCallback);

  }

  void voiceSimpleSub::txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
  }
  
  void voiceSimpleSub::voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
  }


} // namespace voice_node
