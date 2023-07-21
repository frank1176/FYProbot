
#define RXD2 16
#define TXD2 17

int num;
int pinnum;
char out[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  sprintf(out, "#%dP%dT0500\r\n", pinnum,num);
  Serial.println(out);
  Serial2.println(out);
  Serial.println("end\n");
}

void reset(){

  Serial.println("Resting....");

  Serial2.print("#1P0000T0000\r\n"); //start
  
  Serial2.print("#1P1500T0500\r\n");
  
  delay(2000);
  Serial2.print("#2P1600T0500\r\n");
  delay(2000);
  Serial2.print("#3P2000T0500\r\n");
  delay(2000);
  Serial2.print("#4P800T0500\r\n");
  delay(2000);
  Serial2.print("#5P1500T0500\r\n");
  delay(2000);
  Serial2.print("#6P1500T0500\r\n");
  

  delay(2000);
  // Serial2.print("#1P1500T0500\r\n");
  Serial.print("Rest end \n");
 
}
