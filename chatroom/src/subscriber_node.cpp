/*

#include <ros/ros.h>
#include <std_msgs/String.h>

ros::Publisher pub;

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "chatroom_node");
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::String>("chatroom_topic", 1000);
    ros::Subscriber sub = nh.subscribe("chatroom_topic", 1000, messageCallback);
    ros::spin();
    return 0;
}
*/

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <chatroom/ChatMessage.h>

ros::Publisher pub;

void messageCallback(const chatroom::ChatMessage::ConstPtr& msg) {
    //ROS_INFO("I heard: [%s]", msg->data.c_str());
    ROS_INFO("%s : %s ", msg->username.c_str() , msg->message.c_str());}


int main(int argc, char **argv) {
    ros::init(argc, argv, "chatroom_node");
    ros::NodeHandle nh;
    pub = nh.advertise<chatroom::ChatMessage>("chatroom_topic", 1000);
    ros::Subscriber sub = nh.subscribe("chatroom_topic", 1000, messageCallback);
    ros::spin();
    return 0;
}