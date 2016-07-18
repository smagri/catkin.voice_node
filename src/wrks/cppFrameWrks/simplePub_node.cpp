#include "voice_node/simplePub.h"


int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "simplePub");
  ros::NodeHandle nh;

  // Create a new node_example::Talker object.
  //
  //node_example::ExampleTalker node(nh);
  //
  voice_node::voiceSimplePub node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} // end main()
