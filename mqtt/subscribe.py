import pika

credentials = pika.PlainCredentials('engineer', 'anakperantau')
connection = pika.BlockingConnection(pika.ConnectionParameters(host='seafood.tuvbo.com',credentials=credentials,virtual_host='qa1'))
channel = connection.channel()


queue='test'
channel.queue_declare(queue=queue,durable=True)

def callback(ch, method, properties, body):
    print(f" [x] Received {body}")

# Start consuming
channel.basic_consume(queue=queue, on_message_callback=callback, auto_ack=True)

print(' [*] Waiting for messages. To exit press CTRL+C')
channel.start_consuming()
