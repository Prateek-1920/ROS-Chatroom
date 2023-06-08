## DESCRIPTION OF THE TASK
A chatroom is to be made where 3 users can publish messages and all of them could see the message published.

## APPROACH UNDERTAKEN
1. 3 different cpp files are made for 3 users which act as both publisher and subscriber.
2. Custom messages are defined which take username and message as inputs.
3. Asyncspinner is used to process multiple callbacks concurrently. The spinner runs all of the registered callback threads simultaneously in the same thread instead of the nodes having their own thread and avoids multi-tasking.
4. A subscriber was made to track the messages sent by all the users.

## ROS TOPICS PUBLISHED
```
/chatroom_topic
/rosout
/rosout_agg
```

## MESSAGES USED
![CUSTOM MESG](https://user-images.githubusercontent.com/117933472/215258760-b5d696ca-bb62-45a7-abae-85c435b47719.png)

## RQT GRAPH
![RQT graph](https://user-images.githubusercontent.com/117933472/215258773-903fd3b4-d973-411d-9be3-b6b8cf462b1a.png)

## YOUTUBE VIDEO LINK
https://youtu.be/8_mrtiAVEXk
