// This program is  a node called simplePub.  A  node is an executable
// connected  to  the  ROS  network.  This  node  demonstrates  simple
// sending  of  messages over  the  ROS  system,  or publishing  on  a
// specific topic.

// package = rosVoiceNode
// source directory name = src

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


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
  // Initialise ROS
  // nodeName = simplePub
  ros::init(argc, argv, "simplePub");

  // NodeHandle is  the main access  point to communications  with the
  // ROS  system.    The  first  NodeHandle   constructed  will  fully
  // initialize  this node,  and the  last NodeHandle  destructed will
  // close down the node.
  //
  // nodeHandle = n
  ros::NodeHandle n;


  // The advertise()  function is  how you tell  ROS that you  want to
  // publish on  a given topic  name. This invokes  a call to  the ROS
  // master node, which keeps a  registry of who is publishing and who
  // is subscribing.  After this advertise() call is  made, the master
  // node will notify anyone who  is trying to subscribe to this topic
  // name, and  they will in turn negotiate  a peer-to-peer connection
  // with  this node.   
  //
  // advertise()  returns  a  Publisher  object which  allows  you  to
  // publish messages on that topic through a call to publish().  Once
  // all copies  of the returned  Publisher object are  destroyed, the
  // topic will be automatically unadvertised.
  //
  // The second  parameter to advertise()  is the size of  the message
  // queue used  for publishing  messages.  If messages  are published
  // more quickly than we can send them, the number here specifies how
  // many messages to buffer up before throwing some away.
  //
  // Send messages, publish, to the txt4TTStopic:
  // Publisher Object = txt4TTSpubObj
  // Topic Name = txt4TTStopic
  // Message Buffer size = 1000 messages
  // Message Type is std_msgs/String
  int nodeBufSize = 1000;
  ros::Publisher txt4TTSpubObj
    = n.advertise<std_msgs::String>("txt4TTStopic", nodeBufSize);

  // Specifies the frequency that you  would like to loop at.  It will
  // keep  track of  how  long it  has  been since  the  last call  to
  // Rate::sleep().
  //
  // So  loop 1/10sec  after the  last sleep  call, that  is, 10Hz(ten
  // cycles per second).
  ros::Rate loop_rate(10);

  // A  count of  how many  messages we  have sent.   This is  used to
  // create a unique string for each message.
  int count = 0;

  // roscpp installs a SIGINT handler to handle control-C.
  while (ros::ok()){

    // This is a message object. You stuff it with data, and then publish it.
    //
    // ???Here I should put any custom messages???
    std_msgs::String msg;
    
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    
    // Broadcast to the world, rosout and other subscribers to the topic.
    // ROS_INFO..etc replace printf/cout.
    ROS_INFO("%s", msg.data.c_str());
    
    // The publish() function is  how you send messages. The parameter
    // is the message object. The  type of this object must agree with
    // the  type given as  a template  parameter to  the advertise<>()
    // call, as was done in the constructor above.
    //
    //  Send standard string message,  msg object, object type must be
    //  the same as in advertise().
    txt4TTSpubObj.publish(msg);

    // So you can get callbacks.
    ros::spinOnce();

    // Sleep for time remaining, to achive 10Hz publish rate.
    loop_rate.sleep();

    ++count;
  }


  return 0;
}

