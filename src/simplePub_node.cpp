// This program is  a node called simplePub.  A  node is an executable
// connected  to  the  ROS  network.  This  node  demonstrates  simple
// sending  of  messages over  the  ROS  system,  or publishing  on  a
// specific topic.


#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>



int main(int argc, char **argv){

  // Initialise ROS, nodeName = simplePub.
  ros::init(argc, argv, "simplePub");

  ros::NodeHandle n; // nodeHandle = n

  // Send messages:
  // publish to the txt4TTStopic:
  // Publisher Object = txt4TTSpubObj
  // Topic Name = txt4TTStopic
  // Message Buffer size = 1000 messages
  // Message Type is std_msgs/String
  //
  int nodeBufSize = 1000;
  ros::Publisher txt4TTSpubObj
    = n.advertise<std_msgs::String>("txt4TTStopic", nodeBufSize);
  ros::Publisher voiceNamePubObj
    = n.advertise<std_msgs::String>("voiceNameTopic", nodeBufSize);

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
    std_msgs::String txt4TTS;
    std::stringstream ss1;
    ss1 << "Hi there simone";
    txt4TTS.data = ss1.str();

    std_msgs::String voiceName;
    std::stringstream ss2;
    ss2 << "nitech_us_slt_arctic_hts";
    voiceName.data = ss2.str();

    
    // Broadcast to the world, rosout and other subscribers to the topic.
    // ROS_INFO..etc replaces printf/cout.
    //
    ROS_INFO( "%s", txt4TTS.data.c_str() );
    ROS_INFO( "%s", voiceName.data.c_str() );
    

    //  Send standard string message, object type must be as in advertise().
    txt4TTSpubObj.publish(txt4TTS);
    voiceNamePubObj.publish(voiceName);

    // So you can get callbacks.
    ros::spinOnce();

    // Sleep for time remaining, to achive 10Hz publish rate.
    loop_rate.sleep();

    ++count;
  }


  return 0;
}

