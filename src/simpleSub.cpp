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

static std::string voice = "voice_kal_diphone";

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

    // Default voice and text to say.
    voice = "voice_kal_diphone";
    //voice = "voice_nitech_us_slt_arctic_hts";
    //sayText = "hello world";

  }

  void voiceSimpleSub::
  txt4TTStopicCallback(const std_msgs::String::ConstPtr& msg){

    //   const std::string voice = "voice_nitech_us_slt_arctic_hts";
    //const std::string voice = "voice_nitech_us_awb_arctic_hts";
    //const std::string voice = "voice_nitech_us_bdl_arctic_hts";
    //const std::string voice = "voice_nitech_us_clb_arctic_hts";
    //const std::string voice = "voice_nitech_us_rms_arctic_hts";
    //const std::string voice = "voice_nitech_us_jmk_arctic_hts";

    ROS_INFO("txt4TTStcbk: I heard: [%s]", msg->data.c_str());
//    ROS_INFO("I heard voice: [%s]", voice);
//    printf("voice = %s", voice);
    cout << "txt4TTStcbk: dbg: I heard: voice = " << voice << "\n";
    
    sayText = msg->data.c_str();

    // broadcasts on the robotsound topic
    sndClient.say(sayText, voice);
    //sndClient.say(sayText, "voice_nitech_us_slt_arctic_hts");
    sleep(5); // value 5-10 seconds is optimal
    // sndClient.stopSaying(sayText);
    // sndClient.stopAll();
}
  
  void voiceSimpleSub::
  voiceNameTopicCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("voiceNameTcbk: with voice: [%s]", msg->data.c_str());

    voice = msg->data.c_str();
    cout << "voiceNameTcbk: dbg: voice = " << voice << "\n";

    // broadcasts on the robotsound topic
//    sndClient.say(sayText, voice);
//    sleep(5);
  }



} // namespace voice_node
