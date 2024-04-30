import random 

from paho.mqtt import client as mqtt_client


broker = 'broker.emqx.io'
port = 1883
topic = "Node Red IOT 71220924 Giovanka/Coba Node Red dengan MQTT."
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'qwerty'
password = 'public'


def connect_mqtt() -> mqtt_client:
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


def subscribe(client: mqtt_client):
    def on_message(client, userdata, msg):
        with open("test.txt", "a") as f:
            f.write(f"{msg.payload.decode()} {msg.topic}\n")
        print(f"{msg.payload.decode()}{msg.topic}")
    print("\n")
        

    client.subscribe(topic)
    client.on_message = on_message


def run():
    client = connect_mqtt()
    subscribe(client)
    client.loop_forever()


if __name__ == '__main__':
    run()