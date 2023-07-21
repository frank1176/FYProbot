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

  Serial.println("Resting....");

  Serial2.print("#1P0000T0000\r\n"); //start
  
  Serial2.print("#1P1500T0500\r\n");
  
  delay(2000);
  Serial2.print("#2P1500T0500\r\n");
  delay(2000);
  Serial2.print("#3P2400T0500\r\n");
  delay(2000);
  Serial2.print("#4P1100T0500\r\n");
  delay(2000);
  Serial2.print("#5P1500T0500\r\n");
  delay(2000);
  Serial2.print("#6P1500T0500\r\n");
  

  delay(2000);
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
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter your selection:");
  Serial.println("1. reset()");
  Serial.println("2. stop()");
  Serial.println("3. Grab1()");
  Serial.println("4. Grab2()");
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
    default:
      Serial.println("Invalid selection. Please enter 1-3.");
      break;
  }
  delay(1000); // Delay for 1 second
}
