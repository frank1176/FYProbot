#define RXD2 16
#define TXD2 17

int num;
int input;
char out[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
  Serial.println("Serial Txd is on pin"+String(TXD2));
  Serial.println("Serial Rxd is on pin"+String(RXD2));
  reset();
}


void reset(){
  int delayreset=2000;
  Serial.println("Resting....");
  // Serial2.print("#1P0000T0000\r\n"); //start
  Serial2.print("#10P0000T1000\r\n");
  Serial2.print("#1P1500#2P1500#3P800#4P2000#5P1500#6P1700T1500\r\n");
  delay(delayreset);
  // Serial2.print("#1P1500T0500\r\n");
  Serial.print("Rest end \n");
 
}

void stop(){
  Serial2.print("#STOP\r\n");
}

void point1_stand(){
  int delay1=2000;
  Serial.println("Point1....");

  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1750#2P1700#3P500#4P800T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2200T1000\r\n"); 
  delay(delay1);
  Serial2.print("#3P600T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1220T1000\r\n"); 
  delay(delay1);
  Serial.println("Point1 finish");
  stop();
}
void point2_stand(){
  int delay1=2000;
  Serial.println("Point2....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1500#2P1700#3P500#4P800T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2200T1000\r\n"); 
  delay(delay1);
  Serial2.print("#3P600T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1220T1000\r\n"); 
  delay(delay1);
  Serial.println("Point2 finish");
  stop();
}

void point3_stand(){
  int delay1=2000;
  Serial.println("Point3....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1250#2P1800#3P500#4P800T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2200T1000\r\n"); 
  delay(delay1);
  Serial2.print("#3P800#4P1000T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1220T1000\r\n"); 
  delay(delay1);
  Serial.println("Point3 finish");
  stop();
}


void point1_laydown_90(){
  int delay1=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1700#2P1700#3P1100#4P1900T1000\r\n"); 
  delay(delay1);
  Serial2.print("#5P1800#2P2100T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1200T1000\r\n");  
  Serial.println("Point1 finish");
  stop();
}
void point2_laydown_90(){
  int delay1=2000;
  Serial.println("Point2....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1500#2P1700#3P1100#4P1900T1000\r\n"); 
  delay(delay1);
  Serial2.print("#5P1500#2P2100T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1250T1000\r\n");  
  Serial.println("Point2 finish");
  stop();
}
void point3_laydown_90(){
  int delay1=2000;
  Serial.println("Point3....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1300#2P2100#3P1400#4P2000T1000\r\n"); 
  delay(delay1);
  Serial2.print("#5P1300#2P2300T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1250T1000\r\n");  
  Serial.println("Point3 finish");
  stop();

}

void point1_laydown_0(){
  int delay1=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1750#2P1700#3P1100#4P2000T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2100#5P500T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1250T1000\r\n"); 
  delay(delay1);
  Serial.println("Point1 finish");
  stop();
}

void point2_laydown_0(){
  int delay1=2000;
  Serial.println("Point2....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1500#2P1700#3P1100#4P2000T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2100#5P500T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1250T1000\r\n"); 
  delay(delay1);
  Serial.println("Point2 finish");
  stop();
}
void point3_laydown_0(){
  int delay1=2000;
  Serial.println("Point3....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1250#2P1700#3P1100#4P1900T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2100#5P500T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1250T1000\r\n"); 
  delay(delay1);
  Serial.println("Point3 finish");
  stop();
}

void plastic(){
  int delayp=2000;
  Serial.println("plastic start");
  Serial2.print("#2P1500#1P1500#3P2000#4P1500#5P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#3P1500#2P750T1000\r\n"); 
  delay(delayp);
  Serial2.print("#6P1700T1000\r\n"); 
  Serial.println("plastic finish");
}

void metal(){
  int delaym=2000;
  Serial.println("metal start");
  Serial2.print("#2P1500#1P1800#3P2000#4P1500#5P1500T1000\r\n"); 
  delay(delaym);
  Serial2.print("#3P1500#2P800T1000\r\n"); 
  delay(delaym); 
  Serial2.print("#6P1700T1000\r\n"); 
  Serial.println("metal finish");
}

void paper(){
  int delayp=2000;
  Serial.println("paper start");
  Serial2.print("#2P1500#1P1250#3P2000#4P1500#5P1500T1000\r\n"); 
  delay(delayp);
  Serial2.print("#3P1500#2P750T1000\r\n"); 
  delay(delayp);
  Serial2.print("#6P1700T1000\r\n"); 
  Serial.println("paper finish");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter your selection:");
  Serial.println("1. reset()");
  Serial.println("2. stop()");
  Serial.println("3. Plastic()");
  Serial.println("4. Metal()");
  Serial.println("5. Paper()");
  Serial.println("6. point1_stand()");
  Serial.println("7. point2_stand()");
  Serial.println("8. point3_stand()");
  Serial.println("9. point1_laydown_90()");
  Serial.println("10. point2_laydown_90()");
  Serial.println("11. point3_laydown_90()");
  Serial.println("12. point1_laydown_0()");
  Serial.println("13. point2_laydown_0()");
  Serial.println("14. point3_laydown_0()");
  while (Serial.available() == 0) {}
  input = Serial.parseInt();
  Serial.read();

  switch (input) {
    case 1:
      reset();
      break;
    case 2:
      stop();
      break;
    case 3:
      plastic();
      break;
    case 4:
      metal();
      break;
    case 5:
      paper();
      break;
    case 6:
      point1_stand();
      break;
    case 7:
      point2_stand();
      break;
    case 8:
      point3_stand();
      break;
    case 9:
      point1_laydown_90();
      break;
    case 10:
      point2_laydown_90();
      break;
    case 11:
      point3_laydown_90();
      break;
    case 12:
      point1_laydown_0();
      break;
    case 13:
      point2_laydown_0();
      break;
    case 14:
      point3_laydown_0();
      break;
    default:
      Serial.println("Invalid selection. Please enter 1-14.");
      break;
  }
  delay(1000); // Delay for 1 second
}
