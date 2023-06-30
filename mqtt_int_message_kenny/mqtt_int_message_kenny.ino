#include <WiFi.h>
#include <PubSubClient.h>
int LED_BUILTIN=2;
int delaywaimin;
// const char *ssid = "siewseng@unifi"; // Enter your WiFi name
// const char *password = "69983155";  // Enter WiFi password
const char *ssid = "Kynoci@2.4"; // Enter your WiFi name
const char *password = "Malaysia";  // Enter WiFi password
// const char* mqtt_server = "broker.hivemq.com";
// const char* mqtt_topic     = "waimin/fyp/"; // TOPIC (MUST BE UNIQUE)
const char* mqtt_server = "seafood.tuvbo.com";
const char* mqtt_topic     = "hi"; // TOPIC (MUST BE UNIQUE)
int         mqtt_port      = 1883;
// const char* mqtt_username  = NULL;
// const char* mqtt_password  = NULL;
const char* mqtt_username  = "babi";
const char* mqtt_password  = "chu";
WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  wifi_setup();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  client.subscribe(mqtt_topic);
  client.publish(mqtt_topic, "hi fyp waimin");
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (!client.connected()) {
    reconnect();
  }
  client.loop();
  digitalWrite(LED_BUILTIN,HIGH);
  delay(delaywaimin);
  digitalWrite(LED_BUILTIN,LOW);
  delay(delaywaimin);
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

    // Convert string to integer and assign it to delay
    delaywaimin = receivedString.toInt();

    Serial.print("New delay value: ");
    Serial.println(delaywaimin);
}