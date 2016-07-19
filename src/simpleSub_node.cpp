#include "voice_node/simpleSub.h"

int main(int argc, char **argv){

  // Set up ROS.
  ros::init(argc, argv, "simpleSub");
  ros::NodeHandle nh;


  // Create a new node_example::Talker object.
  voice_node::voiceSimpleSub node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
} // end main()
