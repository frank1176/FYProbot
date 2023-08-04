import paho.mqtt.client as mqtt

# The callback for when the client receives a CONNECT response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe("point1")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))



######Authentication############
client = mqtt.Client()
username = "engineer"
password = "anakperantau"
client.username_pw_set(username, password)
#######################################
client.on_connect = on_connect
client.on_message = on_message

client.connect("seafood.tuvbo.com", 1883, 60)  # replace "mqtt.example.com" with your broker address

# Blocking call that processes network traffic, dispatches callbacks and
# handles reconnecting.
# Other loop*() functions are available that give a threaded interface and a
# manual interface.
client.loop_forever()