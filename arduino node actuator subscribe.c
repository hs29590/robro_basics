#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <Servo.h>

ros::NodeHandle nh;
Servo myservo;
//int flag=0;
void extendfull()
{
  myservo.writeMicroseconds(2000);
  delay(12000);
}
void retractfull()
{
  myservo.writeMicroseconds(1000);
  delay(12000);
}
void extend_distance( int mm)
{
  if (mm <= 140)
  {
    int pulse_sec = (1000 + ((50 * mm) / 7));
    int act_delay = ((12000 * mm) / 140);
    myservo.writeMicroseconds(pulse_sec);
    delay(act_delay);
    //myservo.writeMicroseconds(1000);
    //delay(act_delay);
  }
}
void extendCb( const std_msgs::String& msg)
{

  extendfull();
}
void retractCb( const std_msgs::String& msg)
{

  retractfull();
}
void extendDistanceCb( const std_msgs::Int32& msg_distance)
{
  extend_distance(msg_distance.data);
}

ros::Subscriber<std_msgs::String> sub_extend("extend_actuator", &extendCb );
ros::Subscriber<std_msgs::String> sub_retract("retract_actuator", &retractCb);
ros::Subscriber<std_msgs::Int32> sub_extend_distance("extenddistance_actuator", &extendDistanceCb);
void setup()
{
  //pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub_extend);
  nh.subscribe(sub_retract);
  nh.subscribe(sub_extend_distance);
  pinMode(9, OUTPUT);
  myservo.attach(9);
  myservo.writeMicroseconds(1000);
  delay(10000);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}

