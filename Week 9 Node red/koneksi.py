import paho.mqtt.publish as publish


import time
array_kosong = list()

for i in range(2,1001):
    array_kosong.append(i)
    # print (array_kosong)


for i in array_kosong:
    publish.single("NodeRed/71220924", i , hostname = "test.mosquitto.org")
    time.sleep(1)   




print("Koneksi ke MQTT berhasil!")

