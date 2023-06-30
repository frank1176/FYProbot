// #include <Servo.h>
#define RXD2 16
#define TXD2 17
int num;
char arr[20];
char dot[]="\"";
char c[] = "#2P";
char c2[] = "T1000\\r\\n";
char out[20];

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
    
    // input();
    Serial.println("Enter value:");
    while(Serial.available()==0){}
    num = Serial.parseInt();
    
    Serial.print("Hello ");
    Serial.print("Your input value is:");
    Serial.println(num);
    Serial.read(); // if no put will loop 2 times
    Serial.print("start\n");

    sprintf(out, "#1P%dT0500\r\n", num);
    Serial.println(out);
    Serial2.println(out);
    Serial.println("end\n");


/////////////////////////////////////////////////////////////////    
///fail
    // Serial.print("start\r\n");
    
    // sprintf(arr, "%d", num);
    
    // // strcpy(out, dot);  
    // strcpy(out, c);
    // strcat(out, arr);  
    // strcat(out, c2);  
    // // strcat(out, "\"");  
    // // char move[]=out;
    // Serial.print(out);
    // Serial2.print(out);
    // // Serial.print(move);
    
    // Serial.println("\n end\r\n");
/////////////////////////////////////////////////////////////////    
   
   

    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//working//////////////////////////////////////////////////////////////////////////////////////////////////
    // Serial.print("start\r\n");
    // char move[]="#1P500T1000\r\n";
    // Serial.print(move);
    // Serial2.print(move);
    // // Serial2.print("#1P500T1000\r\n");
    // delay(3000); 
    // Serial.println("\n end\r\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }
  
}
void input()
{
  // Serial.println("Enter value:");
  // while(Serial.available()==0){}
  // num = Serial.parseInt();
  
  // Serial.print("Hello ");
  // Serial.print("Your input value is:");
  // Serial.println(num);
  // Serial.read(); // if no put will loop 2 times
  // sprintf(arr, "%d", num);
  // strcpy(out, c);
  // strcat(out, arr);  
  // strcat(out, c2);  
  // Serial.print("start\r\n");
  // Serial.print(out);
  // Serial2.print(out);
  // Serial.println("\n end\r\n");
}
