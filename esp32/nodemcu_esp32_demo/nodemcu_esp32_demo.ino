#include <WiFi.h>
#include <PubSubClient.h>
#include <Stepper.h>
#include <string>

const int indicator_WiFi    = 25;
const int indicator_MQTT    = 33;
const int indicator_ComExe  = 32;

const int indicator_led1    = 15;
const int indicator_led2    = 2;
const int indicator_led3    = 4;
const int indicator_led4    = 5;
const int indicator_led5    = 18;
const int indicator_led6    = 19;
const int indicator_led7    = 21;
const int indicator_led8    = 22;
const int indicator_led9    = 23;

const int sensor_contact    = 34;
const int sensor_vibration  = 35;
const int sensor_button     = 26;

const int motor1 = 13;
const int motor3 = 12;
const int motor2 = 14;
const int motor4 = 27;

const char* ssid           = "Yiqi_dlink"; //YOUR WIFI SSID
const char* password       = "password1234567"; //YOUR WIFI PASSWORD
const char* mqtt_server    = "broker.hivemq.com"; // MQTT BROKER
const char* mqtt_topic     = "TARUC/BAIT2123/DEMO"; // TOPIC (MUST BE UNIQUE)
int         mqtt_port      = 1883;
const char* mqtt_username  = NULL;
const char* mqtt_password  = NULL;

WiFiClient wifiClient;
PubSubClient mqttclient(wifiClient);
int runMOTOR = 0;
bool runSENSOR = 0;
bool runLED = 0;

boolean stepperDirection = false;
int     stepperStep = 1;
int     stepperStepCount = 0;
boolean stepperMove = true;
long    prevMillisStepper = 0;
int     intervalStepper = 2; // Minimum is 2, increase for lower speed
#define STEPS_PER_MOTOR_REVOLUTION 32
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048 
#define STEPS_PER_ROUND_OVER_3600 182 // 32 * 64 * 3.2 / 360 * 10
Stepper myStepper(STEPS_PER_MOTOR_REVOLUTION, motor1, motor2, motor3, motor4);
int     Steps2Take;

void setup() {
  Serial.begin(115200);
  initialize();
  setup_wifi();
  mqttclient.setServer(mqtt_server, mqtt_port);
  mqttclient.setCallback(callback);
  mqttclient.subscribe(mqtt_topic);
  mqttclient.publish(mqtt_topic, "Demo (Motor) is connected to MQTT.");
}

// the loop function runs over and over again forever
void loop() {
  if(!mqttclient.connected()){
    reconnect();
  }
  mqttclient.loop();
  if (runLED) {
    runningLED();
  }

  if (runSENSOR){
    if (digitalRead(sensor_contact) == 0) {
      mqttclient.publish(mqtt_topic, "Contact Sensor = 0");
      delay(1000);
    }
    if (digitalRead(sensor_vibration) == 0) {
      mqttclient.publish(mqtt_topic, "Vibration Sensor = 0");
      delay(1000);
    }
  }

  if (runMOTOR != 0){
    if (runMOTOR <= 360 && runMOTOR >= -360){
      runStepperMotor(runMOTOR);
    }
    runMOTOR = 0;
  }
}

void runStepperMotor(int degstep) {
  Steps2Take  =  STEPS_PER_ROUND_OVER_3600 * degstep / 10;  
  myStepper.setSpeed(1000);
  myStepper.step(Steps2Take);
  delay(1000);
}

void initialize() {
  pinMode(sensor_contact, INPUT); // Contact Sensor
  pinMode(sensor_vibration, INPUT); // Vibration Sensor
  pinMode(sensor_button, INPUT); // Button

  pinMode(indicator_WiFi, OUTPUT); // WIFI indicator
  pinMode(indicator_MQTT, OUTPUT); // MQTT indicator
  pinMode(indicator_ComExe, OUTPUT); // Command executed

  pinMode(motor1, OUTPUT); // motor control
  pinMode(motor2, OUTPUT); // motor control
  pinMode(motor3, OUTPUT); // motor control
  pinMode(motor4, OUTPUT); // motor control

  pinMode(indicator_led1, OUTPUT);
  pinMode(indicator_led2, OUTPUT);
  pinMode(indicator_led3, OUTPUT);
  pinMode(indicator_led4, OUTPUT);
  pinMode(indicator_led5, OUTPUT);
  pinMode(indicator_led6, OUTPUT);
  pinMode(indicator_led7, OUTPUT);
  pinMode(indicator_led8, OUTPUT);
  pinMode(indicator_led9, OUTPUT);
  Serial.println("Initialization done.");
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(indicator_WiFi, !digitalRead(indicator_WiFi));
    delay(500);
  }
  digitalWrite(indicator_WiFi, 1);
  Serial.println("Set up WiFi done");
}

void reconnect() {
  while (!mqttclient.connected()) {
    Serial.println("Reconnecting to MQTT Broker..");
    if (mqttclient.connect("", mqtt_username, mqtt_password)) {
      digitalWrite(indicator_MQTT, 1);
      mqttclient.subscribe(mqtt_topic);
    }else{
      digitalWrite(indicator_MQTT, 0);
      Serial.print(mqttclient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.println("MQTT Received");
  digitalWrite(indicator_ComExe, !digitalRead(indicator_ComExe));
  String messageTemp = "";
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  if (messageTemp == "led=0") {
    runLED = 0;
  }
  if (messageTemp == "led=1") {
    runLED = 1;
  }
  if (messageTemp.indexOf("motor=") != -1) {
    Serial.print("no space no motor:");
    messageTemp.replace("motor=","");
    messageTemp.replace(" ","");
    Serial.println(messageTemp);
    runMOTOR = messageTemp.toInt();
  }
  if (messageTemp == "sensor=1") {
    runSENSOR = 1;
  }
  if (messageTemp == "sensor=0") {
    runSENSOR = 0;
  }
}

void runningLED() {
  toggle(indicator_led2, indicator_led1);
  toggle(indicator_led3, indicator_led2);
  toggle(indicator_led4, indicator_led3);
  toggle(indicator_led5, indicator_led4);
  toggle(indicator_led6, indicator_led5);
  toggle(indicator_led7, indicator_led6);
  toggle(indicator_led8, indicator_led7);
  toggle(indicator_led9, indicator_led8);
  toggle(indicator_led8, indicator_led9);
  toggle(indicator_led7, indicator_led8);
  toggle(indicator_led6, indicator_led7);
  toggle(indicator_led5, indicator_led6);
  toggle(indicator_led4, indicator_led5);
  toggle(indicator_led3, indicator_led4);
  toggle(indicator_led2, indicator_led3);
  toggle(indicator_led1, indicator_led2);
}

void toggle(byte on_pin, byte off_pin) {
  digitalWrite(on_pin, 1);
  digitalWrite(off_pin, 0);
  delay(25);
}
