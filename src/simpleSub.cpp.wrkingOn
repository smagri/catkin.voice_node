// ROS node  that subscribes to the txt4TTStopic.   The simplePub node
// publishes  on  the  txt4TTStopic.   This node  demonstrates  simple
// recipt  of  messages over  the  ROS  system,  or subscribing  on  a
// specific topic.
// 

#include "ros/ros.h"

#include "std_msgs/String.h"


// Register  callback function  to  be used  in  main.  This  callback
// function  will get called  when a  new message  has arrived  on the
// txt4TTStopic.
//
void txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg){
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
void voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg){
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

 
int main(int argc, char **argv){

  // The ros::init()  function needs to see  argc and argv  so that it
  // can  perform  any ROS  arguments  and  name  remapping that  were
  // provided at  the command  line.  For programmatic  remappings you
  // can  use a  different version  of init()  which  takes remappings
  // directly, but  for most  command-line programs, passing  argc and
  // argv is the  easiest way to do it.  The  third argument to init()
  // is the  name of the node.  You  must call one of  the versions of
  // ros::init() before using any other part of the ROS system.
  //
  // Initialise ROS.
  // nodeName = simpleSub
  ros::init(argc, argv, "simpleSub");

  // NodeHandle is  the main access point to  communications with the
  // ROS  system.   The   first  NodeHandle  constructed  will  fully
  // initialize this  node, and  the last NodeHandle  destructed will
  // close down the node.
  //
  // nodeHandle = n
  ros::NodeHandle n;
  

  // The subscribe() call is how you tell ROS that you want to receive
  // messages  on a  given topic.   This invokes  a call  to  the ROS
  // master node, which keeps a registry of who is publishing and who
  // subscribing.
  //
  // Messages  are   passed  to  a  callback   function,  here  called
  // txt4TTStopicCallback.   subscribe() returns a  Subscriber object
  // that you  must hold on to  until you want  to unsubscribe.  When
  // all  copies of  the  Subscriber  object go  out  of scope,  this
  // callback will automatically be unsubscribed from this topic.
  //
  // The second parameter  to the subscribe() function is  the size of
  // the message queue.  If messages are arriving faster than they are
  // being  processed, this  is the  number of  messages that  will be
  // buffered up before beginning to throw away the oldest ones.
  //
  // Recive messages, subscribe, on the txt4TTStopic topic:
  // Subscriber Object = txt4TTSsubObj
  // Topic Name = txt4TTStopic
  // Message Buffer Size = 1000 messages
  int nodeBufSize = 1000;
  ros::Subscriber txt4TTSsubObj
    = n.subscribe("txt4TTStopic", nodeBufSize, txt4TTStopicCallback);
  ros::Subscriber voiceNameSubObj
    = n.subscribe("voiceNameTopic", nodeBufSize, voiceNameTopicCallback);

  // ros::spin()  will enter  a  loop, pumping  callbacks.  With  this
  // version,  all callbacks will  be called  from within  this thread
  // (the main one).  ros::spin() will exit when Ctrl-C is pressed, or
  // the node is shutdown by the master.
  //
  // Spins continuously, apparently at low cpu load???, till a message
  // arrives, then the txt4TTStopicCallback callback function is called.
  ros::spin();

  // control-C or ros::shutdown()
 
  return 0;
}
