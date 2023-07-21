// #include <Servo.h>
#define RXD2 16
#define TXD2 17

void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
  Serial.println("Serial Txd is on pin"+String(TXD2));
  Serial.println("Serial Rxd is on pin"+String(RXD2));
  
}
void loop() 
{
  while(1)
  {
    Serial.print("start\r\n");
    
    /*
    Data 1 refers to the servo’s channel
    Data 1500 Refers to the servo’s location, in
    the range 500-2500
    Data 1000 refers to the time of execution
    and represents the speed, in the range
    100-9999
    Data 800 refers to the Instruction interval of
    delay time, in the range 100-9999

    */
    Serial2.print("#1P501T1000\r\n");  // S1号舵机旋转到脉宽为800的位置，使用时间1000ms
    delay(1000);  // 延时1000ms，舵机刚好执行完上一条命令
    Serial2.print("#1P2499T1000\r\n");  // S1号舵机旋转到脉宽为1800的位置，使用时间1000ms
    delay(1000);  // 延时1000ms，舵机刚好执行完上一条命令
    Serial.print("end\r\n");
  }

  
}