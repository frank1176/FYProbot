#include <WiFi.h>
#include <PubSubClient.h>

#define RXD2 16
#define TXD2 17

int input;

const char *ssid = "siewseng@unifi"; // Enter your WiFi name
const char *password = "69983155";  // Enter WiFi password
const char* mqtt_server = "c2.kynoci.com";
const char* mqtt_topic     = "hi2"; // TOPIC (MUST BE UNIQUE)
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

    String receivedString;
    for (int i = 0; i < length; i++) {
        receivedString += (char)payload[i];
    }
    Serial.println("-----------------------");
    Serial.println(receivedString);

    // Map topics to respective functions
    if (String(topic).equals("Point1")) {
        handlePoint1(receivedString);
    } else if (String(topic).equals("Point2")) {
        handlePoint2(receivedString);
    } else if (String(topic).equals("Point3")) {
        handlePoint3(receivedString);
    } else if (String(topic).equals("Stop")) {
        stop();
    } else if (String(topic).equals("Reset")) {
        reset();
    }
}

void handlePoint1(String &receivedString) {
    if (receivedString == "plastic_standrotation") {
        point1_stand();
        // delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_0rotation") {
        point1_laydown_0();
        delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_90rotation") {
        point1_laydown_90();
        delay(2000);
        plastic();
    } else if (receivedString == "paperrotation") {
        point1_laydown_0();
        delay(2000);
        paper();
    } else if (receivedString == "metal_standrotation") {
        point1_stand();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_0rotation") {
        point1_laydown_0();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_90rotation") {
        point1_laydown_90();
        delay(2000);
        metal();
    }
    delay(2000);
}

void handlePoint2(String &receivedString) {
    if (receivedString == "plastic_standrotation") {
        point2_stand();
        delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_0rotation") {
        point2_laydown_0();
        delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_90rotation") {
        point2_laydown_90();
        delay(2000);
        plastic();
    } else if (receivedString == "paperrotation") {
        point2_laydown_0();
        delay(2000);
        paper();
    } else if (receivedString == "metal_standrotation") {
        point2_stand();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_0rotation") {
        point2_laydown_0();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_90rotation") {
        point2_laydown_90();
        delay(2000);
        metal();
    }
    delay(2000);
}

void handlePoint3(String &receivedString) {
    if (receivedString == "plastic_standrotation") {
        point3_stand();
        delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_0rotation") {
        point3_laydown_0();
        delay(2000);
        plastic();
    } else if (receivedString == "plastic_laydown_90rotation") {
        point3_laydown_90();
        delay(2000);
        plastic();
    } else if (receivedString == "paperrotation") {
        point3_laydown_0();
        delay(2000);
        paper();
    } else if (receivedString == "metal_standrotation") {
        point3_stand();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_0rotation") {
        point3_laydown_0();
        delay(2000);
        metal();
    } else if (receivedString == "metal_laydown_90rotation") {
        point3_laydown_90();
        delay(2000);
        metal();
    }
    delay(2000);
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
  Serial2.print("#3P1500#2P700T1000\r\n"); 
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
  
void stop(){
  Serial2.print("#STOP\r\n");
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
void loop() {
  // put your main code here, to run repeatedly:
   if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
}

