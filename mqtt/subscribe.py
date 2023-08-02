import pika

credentials = pika.PlainCredentials('engineer', 'anakperantau')
connection = pika.BlockingConnection(pika.ConnectionParameters(host='seafood.tuvbo.com',credentials=credentials))
# connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()


