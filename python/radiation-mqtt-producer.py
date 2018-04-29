import paho.mqtt.client as paho
import serial
import sys


MQTT_BROKER="192.168.1.13"
MQTT_PORT=32333
MQTT_RADIATION_CLIENT = "MQTT_RADIATION_CLIENT"
MQTT_RADIATION_TOPIC = "mqtt/radiation/ticks"
RADIATION_SERIAL_PORT = "/dev/ttyACM0"
SERIAL_BAUD_RATE=9600
SERIAL_TIMEOUT=5000
SERIAL_BUFFER_SIZE=50

def debug(data):
    sys.stdout.write(json_data)
    sys.stdout.flush()

#On publish callback
def on_publish(client, userdata, result):
    pass


radiation_client = paho.Client(MQTT_RADIATION_CLIENT)
radiation_client.on_publish = on_publish
radiation_client.connect(MQTT_BROKER,MQTT_PORT)

serial_client = serial.Serial(
    port=RADIATION_SERIAL_PORT,
    baudrate=SERIAL_BAUD_RATE,
    parity=serial.PARITY_ODD,
	stopbits=serial.STOPBITS_TWO,
	bytesize=serial.SEVENBITS
    )

while True:
    json_data = serial_client.readline()
    debug(json_data)
    radiation_client.publish(MQTT_RADIATION_TOPIC,payload=json_data)
    
