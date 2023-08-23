#include <WiFi.h>
#include <PubSubClient.h>

#define RXD2 16
#define TXD2 17

int input;

const char *ssid = "siewseng@unifi"; // Enter your WiFi name
const char *password = "69983155";  // Enter WiFi password
const char* mqtt_server = "seafood.tuvbo.com";
const char* mqtt_topic     = "hi"; // TOPIC (MUST BE UNIQUE)
int         mqtt_port      = 1883;
const char* mqtt_username  = "engineer";
const char* mqtt_password  = "anakperantau";
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
  client.subscribe("Point1");
  client.subscribe("Point2");
  client.subscribe("Point3");
  client.publish(mqtt_topic, "hi fyp waimin");
  
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
      client.subscribe("Point1");
      client.subscribe("Point2");
      client.subscribe("Point3");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    
    String receivedString;
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
        receivedString += (char)payload[i];
    }
    Serial.println();
    Serial.println("-----------------------");
    Serial.println(receivedString);
    
    if(String(topic).equals("Point1")){
      point1();
      delay(2000);
      if(receivedString == "plasticrotation"){
          plastic();
      } else if(receivedString == "metalrotation"){
          metal();
      } else if(receivedString == "paperrotation"){
          paper();
      }
    }
    else if(String(topic).equals("Point2")){
      point2();
      delay(2000);
      if(receivedString == "plasticrotation"){
          plastic();
      } else if(receivedString == "metalrotation"){
          metal();
      } else if(receivedString == "paperrotation"){
          paper();
      }
    }
    else if(String(topic).equals("Point3")){
      point3();
      delay(2000);
      if(receivedString == "plasticrotation"){
          plastic();
      } else if(receivedString == "metalrotation"){
          metal();
      } else if(receivedString == "paperrotation"){
          paper();
      }
    }
    else if(String(topic).equals("Stop")){
      stop();
    }
    else if(String(topic).equals("Reset")){
      reset();
    }

}


void point1(){
  int delay1=2000;
  Serial.println("Point1....");
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1700T1000\r\n"); 
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
  Serial.println("Point2....");
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
  Serial2.print("#10P0000T0000\r\n"); //start
  Serial2.print("#1P1250T1000\r\n"); 
  delay(delay3);
  Serial2.print("#3P1500T1000\r\n"); 
  delay(delay3);
  Serial2.print("#2P2000T1000\r\n"); 
  delay(delay3);
  Serial2.print("#5P1400T1000\r\n"); 
  delay(delay3);
  Serial2.print("#4P2100T1000\r\n"); 
  delay(delay3);
  Serial2.print("#2P2200T1000\r\n"); 
  delay(delay3);
  Serial2.print("#1P1200T1000\r\n"); 
  delay(delay3);
  Serial2.print("#3P1300T1000\r\n"); 
  delay(delay3);
  Serial2.print("#6P1300T1000\r\n"); 
  delay(delay3);
  Serial.println("Point3 finish");
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
   if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}

