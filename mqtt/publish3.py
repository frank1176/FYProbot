import paho.mqtt.client as mqtt

def on_log(client, userdata, level, buf):
    print("log: ",buf)
    


def send_mqtt(objectname, track_id,point):
    print("sending mqtt")
    # Create a MQTT client object
    client = mqtt.Client()

    # Enable logging
    client.on_log = on_log

    # Set your username and password
    client.username_pw_set("engineer", "anakperantau")

    try:
        # Connect to the MQTT broker
        client.connect("c2.kynoci.com", 1883, 60)
    except Exception as e:
        print("Error connecting to MQTT Broker: ", e)
        exit(1)

    try:
        # Publish a message
        res = client.publish(point, objectname)
        
        if res.rc != mqtt.MQTT_ERR_SUCCESS:
            print(f"Error publishing message: {mqtt.error_string(res.rc)}")
    except Exception as e:
        print("Error publishing message: ", e)

    # Disconnect from the broker
    # client.disconnect()

send_mqtt('plasticrotation',1.0,'Point_1')



# sent_objects = set()
# def tograb():
#     print("tograb:")
#     try:
#         objectname='plasticrotation'
#         track_id=1.0
#         point='Point_1'
       
#         if (track_id, point) not in sent_objects:
#             send_mqtt(objectname, track_id, point)
#             # Add the track_id and point to the sent_objects
#             sent_objects.add((track_id, point))
#         else:
#             print(f"MQTT message for track_id: {track_id} and point: {point} was already sent.")
#     except IndexError:
#         print("The list is empty")

