import pika
credentials = pika.PlainCredentials('engineer', 'anakperantau')
connection = pika.BlockingConnection(pika.ConnectionParameters(host='seafood.tuvbo.com',credentials=credentials,virtual_host='qa1'))
channel = connection.channel()

queue='test'

##create new queue
channel.queue_declare(queue=queue, durable=True)

message = 'Hello RabbitMQ!111'
channel.basic_publish(exchange='', routing_key=queue, body=message)


print(f"[x] Sent {message}")

# Close connection
connection.close()