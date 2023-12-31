
#define RXD2 16
#define TXD2 17

int num;
int pinnum;
int feedback_position = 0;
char out[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
  Serial.println("Serial Txd is on pin"+String(TXD2));
  Serial.println("Serial Rxd is on pin"+String(RXD2));
  reset();
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0; i < 2; i++) { // Loop twice
    if (i == 0) { // First input
      Serial.println("Enter Pin Number:");
      while(Serial.available()==0){}
      pinnum = Serial.parseInt();
      Serial.println(pinnum);
      Serial.read();      
      // Serial.println("Enter value1:");
      // num = Serial.parseInt();
    }
    else if (i == 1) { // Second input
      Serial.println("Enter value2:");

      while(Serial.available()==0){}
      num = Serial.parseInt();
      Serial.println(num);
    }
    delay(1000); // Delay for 1 second
  }
  
  Serial.print("Hello ");
  Serial.print("Your Pin Number is:");
  Serial.println(pinnum);
  Serial.print("Your input value is:");
  Serial.println(num);
  Serial.read();
  Serial.print("start\n");
  sprintf(out, "#%dP%dT1000\r\n", pinnum,num);
  Serial.println(out);
  Serial2.println(out);
  Serial.println("end\n");

  
}


void reset(){
  int delayreset=2000;
  Serial.println("Resting....");
  // Serial2.print("#1P0000T0000\r\n"); //start
  Serial2.print("#10P0000T1000\r\n");
  Serial2.print("#1P1500#2P1500#3P800#4P2000#5P1500#6P1700T1000\r\n");
  delay(delayreset);
  // Serial2.print("#1P1500T0500\r\n");
  Serial.print("Rest end \n");
 
}

// void reset(){
//   int delayreset=2000;
//   Serial.println("Resting....");
//   // Serial2.print("#1P0000T0000\r\n"); //start
//   Serial2.print("#10P0000T1000\r\n");
//   Serial2.print("#1P1500T0500\r\n");
//   delay(delayreset);
//   Serial2.print("#2P1500T0500\r\n");
//   delay(delayreset);
//   Serial2.print("#3P1500T0500\r\n");
//   delay(delayreset);
//   Serial2.print("#4P1500T0500\r\n");
//   delay(delayreset);
//   Serial2.print("#5P1500T0500\r\n");
//   delay(delayreset);
//   Serial2.print("#6P1500T0500\r\n");
//   delay(delayreset);
//   // Serial2.print("#1P1500T0500\r\n");
//   Serial.print("Rest end \n");
 
// }
