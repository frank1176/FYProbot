#define RXD2 16
#define TXD2 17

int num;
int input;
char out[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  Serial2.print("#1P1500T1000\r\n");
  delay(delayreset);
  Serial2.print("#2P1500T1000\r\n");
  delay(delayreset);
  Serial2.print("#3P800T1000\r\n");
  delay(delayreset);
  Serial2.print("#4P2000T1000\r\n");
  delay(delayreset);
  Serial2.print("#5P1500T1000\r\n");
  delay(delayreset);
  Serial2.print("#6P1700T1000\r\n");
  delay(delayreset);
  // Serial2.print("#1P1500T0500\r\n");
  Serial.print("Rest end \n");
 
}

void stop(){
  Serial2.print("#STOP\r\n");
}

void grab1(){

  Serial.println("Grabing1....");

  Serial2.print("#1P0000T0000\r\n"); //start

  Serial2.print("#1P2100T0500\r\n");  
  delay(2000);
  Serial2.print("#4P700T0500\r\n");  
  delay(2000);
  Serial2.print("#5P500T0500\r\n");  
  delay(2000);
  Serial2.print("#2P1350T0500\r\n");  
  delay(2000);
  Serial2.print("#6P950T0500\r\n");  
  delay(2000);
  Serial2.print("#2P1500T0500\r\n");  
  delay(2000);
  Serial2.print("#1P700T0500\r\n");  
  delay(2000);
  Serial2.print("#6P1500T0500\r\n");  
  delay(2000);
  Serial2.print("#5P1500T0500\r\n");  
  delay(2000);
  Serial2.print("#1P1500T0500\r\n");  
  delay(2000);

  Serial.print("Grab end \n");
}


void grab2(){
  Serial.println("Grabing2....");

  Serial2.print("#1P0000T0000\r\n"); //start

  Serial2.print("#2P1700T0500\r\n"); //start
  delay(2000);
  Serial2.print("#1P2100T0500\r\n"); //start
  delay(2000);
  Serial2.print("#4P600T0500\r\n"); //start
  delay(2000);
  Serial2.print("#2P1500T0500\r\n"); //start
  delay(2000);
  Serial2.print("#5P1800T0500\r\n"); //start
  delay(2000);
  Serial2.print("#2P1350T0500\r\n"); //start
  delay(2000);
  Serial2.print("#6P1300T0500\r\n"); //start
  delay(2000);
  Serial2.print("#2P1700T0500\r\n"); //start
  delay(2000);
  Serial2.print("#1P700T0500\r\n"); //start
  delay(2000);
  Serial2.print("#5P500T0500\r\n"); //start
  delay(2000);
  Serial2.print("#2P1350T0500\r\n"); //start
  delay(2000);
  Serial2.print("#6P1500T0500\r\n"); //start
  delay(2000);
  Serial2.print("#2P1700T0500\r\n"); //start
  delay(2000);
  Serial2.print("#1P1500T0500\r\n"); //start
  delay(2000);
  Serial2.print("#5P1500T0500\r\n"); //start

}

void point1(){
  int delay1=2000;
  Serial.println("Point1....");

  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1750T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P1700T1000\r\n"); 
  delay(delay1);
  Serial2.print("#3P1100T1000\r\n"); 
  delay(delay1);
  Serial2.print("#4P1900T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2000T1000\r\n"); 
  delay(delay1);
  Serial2.print("#5P1800T1000\r\n"); 
  delay(delay1);
  Serial2.print("#2P2100T1000\r\n"); 
  delay(delay1);
  Serial2.print("#6P1300T1000\r\n"); 
  
  Serial.println("Point1 finish");

}

void point2(){
  int delay2=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1500T1000\r\n"); 
  delay(delay2);
  Serial2.print("#2P1700T1000\r\n"); 
  delay(delay2);
  Serial2.print("#3P1100T1000\r\n"); 
  delay(delay2);
  Serial2.print("#2P1900T1000\r\n"); 
  delay(delay2);
  Serial2.print("#4P1800T1000\r\n"); 
  delay(delay2);
  Serial2.print("#2P2100T1000\r\n"); 
  delay(delay2);
  Serial2.print("#4P1900T1000\r\n"); 
  delay(delay2);
  Serial2.print("#6P1300T1000\r\n"); 
  delay(delay2);
  Serial.println("Point2 finish");
}
void point3(){
  int delay3=2000;

}
void plastic(){
  int delayp=2000;
  Serial.println("plastic start");
  Serial2.print("#2P1500T1000\r\n"); 
  delay(delayp);
  Serial2.print("#1P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#3P2000T1000\r\n");
  delay(delayp);
  Serial2.print("#4P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#5P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#3P1500T1000\r\n"); 
  delay(delayp);
  Serial2.print("#2P700T1000\r\n"); 
  delay(delayp);
  Serial2.print("#6P1700T1000\r\n"); 

  Serial.println("plastic finish");
}

void metal(){
  int delaym=2000;
  Serial.println("metal start");
  Serial2.print("#2P1500T1000\r\n"); 
  delay(delaym);
  Serial2.print("#1P1700T1000\r\n");
  delay(delaym);
  Serial2.print("#3P2000T1000\r\n");
  delay(delaym);
  Serial2.print("#4P1500T1000\r\n");
  delay(delaym);
  Serial2.print("#5P1500T1000\r\n");
  delay(delaym);
  Serial2.print("#3P1500T1000\r\n"); 
  delay(delaym);
  Serial2.print("#2P700T1000\r\n"); 
  delay(delaym);
  Serial2.print("#6P1700T1000\r\n"); 
  Serial.println("metal finish");
}

void paper(){
  int delayp=2000;
  Serial.println("metal start");
  Serial2.print("#2P1500T1000\r\n"); 
  delay(delayp);
  Serial2.print("#1P1200T1000\r\n");
  delay(delayp);
  Serial2.print("#3P2000T1000\r\n");
  delay(delayp);
  Serial2.print("#4P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#5P1500T1000\r\n");
  delay(delayp);
  Serial2.print("#3P1500T1000\r\n"); 
  delay(delayp);
  Serial2.print("#2P700T1000\r\n"); 
  delay(delayp);
  Serial2.print("#6P1700T1000\r\n"); 
  Serial.println("paper finish");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter your selection:");
  Serial.println("1. reset()");
  Serial.println("2. stop()");
  Serial.println("3. Grab1()");
  Serial.println("4. Grab2()");
  Serial.println("5. Point1()");
  Serial.println("6. Point2()");
  Serial.println("7. Point3()");
  Serial.println("8. Plastic()");
  Serial.println("9. Metal()");
  Serial.println("10. Paper()");
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
      grab1();
      break;
    case 4:
      grab2();
      break;
    case 5:
      point1();
      break;
    case 6:
      point2();
      break;
    case 7:
      point3();
      break;
    case 8:
      plastic();
      break;
    case 9:
      metal();
      break;
    case 10:
      paper();
      break; 
    default:
      Serial.println("Invalid selection. Please enter 1-8.");
      break;
  }
  delay(1000); // Delay for 1 second
}
