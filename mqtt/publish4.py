import paho.mqtt.client as mqtt

def on_log(client, userdata, level, buf):
    print("log: ", buf)

def send_mqtt(topic, message):
    # Create a MQTT client object
    client = mqtt.Client()

    # Enable logging
    client.on_log = on_log

    # Set your username and password
    client.username_pw_set("engineer", "anakperantau")

    try:
        # Connect to the MQTT broker
        client.connect("seafood.tuvbo.com", 1883, 60)
    except Exception as e:
        print("Error connecting to MQTT Broker: ", e)
        exit(1)

    try:
        # Publish a message
        res = client.publish(topic, message)
    
        if res.rc != mqtt.MQTT_ERR_SUCCESS:
            print(f"Error publishing message: {mqtt.error_string(res.rc)}")
    except Exception as e:
        print("Error publishing message: ", e)

# Use the function
send_mqtt("hi2", "publish4")
