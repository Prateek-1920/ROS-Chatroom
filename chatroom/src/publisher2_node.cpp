#include <ros/ros.h>
#include <std_msgs/String.h>
#include <chatroom/ChatMessage.h>

ros::Publisher pub;

void messageCallback(const chatroom::ChatMessage::ConstPtr& msg) {
   //std::cout<<msg->username<<":"<<msg->message<<std::endl; }

  ROS_INFO("%s : %s ", msg->username.c_str() , msg->message.c_str());}

int main(int argc, char **argv) {
    ros::init(argc, argv, "user2_node");
    ros::NodeHandle nh;

    ros::AsyncSpinner spinner(2);
    spinner.start();

    ros::Subscriber sub = nh.subscribe("chatroom_topic", 1000, messageCallback);
    pub = nh.advertise<chatroom::ChatMessage>("chatroom_topic", 1000);

    std::string username;
    std::cout<<"Enter user name :";
    std::getline(std::cin, username);
    

    while(ros::ok())
    {

        chatroom::ChatMessage msg;
        std::cout<<"ENTER MESSAGE: ";
        std::getline(std::cin,msg.message);

        msg.username = username;
        //msg.message = input;

       // std::string input;
    
        pub.publish(msg);

    }

    return 0;
}
