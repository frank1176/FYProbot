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

void point1_stand(){
  int delay1=2000;
  Serial.println("Point1....");

  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1700T1000\r\n"); 
  delay(delay1);
  Serial.println("Point1 finish");

}
void point1_laydown_0(){
  int delay1=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1700T1000\r\n"); 
  delay(delay1);
  Serial.println("Point1 finish");
}
void point1_laydown_90(){
  int delay1=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1700T1000\r\n"); 
  delay(delay1);
  Serial.println("Point1 finish");
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
  Serial.println("3. Plastic()");
  Serial.println("4. Metal()");
  Serial.println("5. Paper()");
  Serial.println("6. ()");
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
     
      break;
    case 7:
      
      break;
    case 8:
      
      break;
    default:
      Serial.println("Invalid selection. Please enter 1-8.");
      break;
  }
  delay(1000); // Delay for 1 second
}
