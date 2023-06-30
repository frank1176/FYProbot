#include <WiFi.h>
#include <PubSubClient.h>

#define RXD2 16
#define TXD2 17

int num;
int pinnum;
char out[20];

//WIFI setup
// WiFi
//kenny////
// const char *ssid = "Kynoci@2.4"; // Enter your WiFi name
// const char *password = "Malaysia";  // Enter WiFi password
///////////
const char *ssid = "siewseng@unifi"; // Enter your WiFi name
const char *password = "69983155";  // Enter WiFi password

// MQTT Broker
const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic     = "waimin/fyp/"; // TOPIC (MUST BE UNIQUE)
int         mqtt_port      = 1883;
const char* mqtt_username  = NULL;
const char* mqtt_password  = NULL;


WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
  Serial.println("Serial Txd is on pin"+String(TXD2));
  Serial.println("Serial Rxd is on pin"+String(RXD2));
  reset();
  wifi_setup();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  client.subscribe(mqtt_topic);
  client.publish(mqtt_topic, "hi fyp waimin");
}

void loop() {
   if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // put your main code here, to run repeatedly:
// for (int i = 0; i < 2; i++) { // Loop twice
//     if (i == 0) { // First input
//       Serial.println("Enter Pin Number:");
//       while(Serial.available()==0){}
//       pinnum = Serial.parseInt();
//       Serial.println(pinnum);
//       Serial.read();      
//       // Serial.println("Enter value1:");
//       // num = Serial.parseInt();
//     }
//     else if (i == 1) { // Second input
//       Serial.println("Enter value2:");

//       while(Serial.available()==0){}
//       num = Serial.parseInt();
//       Serial.println(num);
//     }
//     delay(1000); // Delay for 1 second
//   }
  
//   Serial.print("Hello ");
//   Serial.print("Your Pin Number is:");
//   Serial.println(pinnum);
//   Serial.print("Your input value is:");
//   Serial.println(num);
//   Serial.read();
//   Serial.print("start\n");
//   sprintf(out, "#%dP%dT0500\r\n", pinnum,num);
//   Serial.println(out);
//   Serial2.println(out);
//   Serial.println("end\n");
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

void wifi_setup(){
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the Wi-Fi network");
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("",mqtt_username,mqtt_password)) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // client.publish("outTopic","hello world");
      client.publish(mqtt_topic, "hi fyp waimin");
      // ... and resubscribe
      // client.subscribe("inTopic");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// void moverobot(pinnum,num){
//   for (int i = 0; i < 2; i++) { // Loop twice
//     if (i == 0) { // First input
//       Serial.println("Enter Pin Number:");
//       while(Serial.available()==0){}
//       pinnum = Serial.parseInt();
//       Serial.println(pinnum);
//       Serial.read();      
//       // Serial.println("Enter value1:");
//       // num = Serial.parseInt();
//     }
//     else if (i == 1) { // Second input
//       Serial.println("Enter value2:");

//       while(Serial.available()==0){}
//       num = Serial.parseInt();
//       Serial.println(num);
//     }
//     delay(1000); // Delay for 1 second
//   }
  
//   Serial.print("Hello ");
//   Serial.print("Your Pin Number is:");
//   Serial.println(pinnum);
//   Serial.print("Your input value is:");
//   Serial.println(num);
//   Serial.read();
//   Serial.print("start\n");
//   sprintf(out, "#%dP%dT0500\r\n", pinnum,num);
//   Serial.println(out);
//   Serial2.println(out);
//   Serial.println("end\n");
// }
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

