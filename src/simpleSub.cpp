// ROS node  that subscribes to the txt4TTStopic.   The simplePub node
// publishes  on  the  txt4TTStopic.   This node  demonstrates  simple
// recipt  of  messages over  the  ROS  system,  or subscribing  on  a
// specific topic.
// 

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
    txt4TTSsubObj =
      nh.subscribe("txt4TTStopic", nodeBufSize,
		   &voiceSimpleSub::txt4TTStopicCallback, this);
    voiceNameSubObj =
      nh.subscribe("voiceNameTopic", nodeBufSize,
		   &voiceSimpleSub::voiceNameTopicCallback, this);
    //  old way =>
    //voiceNameSubObj=
    //nh.subscribe("voiceNameTopic", nodeBufSize, voiceNameTopicCallback);
    
    // allocate storage for sound client class instance .
    sound_play::SoundClient sndClient;

    // voiceName = "voice_nitech_us_slt_arctic_hts";

  }

  void voiceSimpleSub::
  txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg){

    //   const std::string voice = "voice_nitech_us_slt_arctic_hts";
    //const std::string voice = "voice_nitech_us_awb_arctic_hts";
    //const std::string voice = "voice_nitech_us_bdl_arctic_hts";
    //const std::string voice = "voice_nitech_us_clb_arctic_hts";
    //const std::string voice = "voice_nitech_us_rms_arctic_hts";
    //const std::string voice = "voice_nitech_us_jmk_arctic_hts";

    ROS_INFO("I heard: [%s]", msg->data.c_str());
    sayText = msg->data.c_str();
    // broadcasts on the robotsound topic
    // sndClient.say("hello world", voice);
    // sndClient.say( (msg->data.c_str()), voice );
//    sndClient.say( (msg->data.c_str()), voice );
    sndClient.say(sayText, voiceName);
    sleep(5);
}
  
  void voiceSimpleSub::
  voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("with voice: [%s]", msg->data.c_str());

    voiceName = msg->data.c_str();

    // broadcasts on the robotsound topic
    sndClient.say(sayText, voiceName);
    sleep(5);
  }



} // namespace voice_node
