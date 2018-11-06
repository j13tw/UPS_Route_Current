#!/usr/bin/python3.6
# -*- coding: UTF-8 -*-

import serial, time
import json
import datetime
from serial import SerialException
import paho.mqtt.client as mqtt

# MQTT setup data
MQTT_SERVER = "10.20.0.19"
MQTT_PORT = 1883
MQTT_TOPIC = "cabinet_A"

power = serial.Serial()

while(1):
	if(power.is_open):
		send_status = 0
		response = power.readline()
		response = response.decode('ascii')
		print(response)
		try:
			data = json.loads(str(response))
			IN_V110_A = data['IN_V110_A']
			IN_V110_B = data['IN_V110_B']
			OUT_V110_A = data['OUT_V110_A']
			OUT_V110_B = data['OUT_V110_B']
			OUT_V110_C = data['OUT_V110_C']
			OUT_V110_D = data['OUT_V110_D']
			OUT_V110_E = data['OUT_V110_E']
#			print(Temperature, type(Temperature), Humidity, type(Humidity))
			send_status = 1
		except:
			send_status = 0
		if (send_status == 1):
			print('------------------------------------------------------')
			try:
				# MQTT connection
				mqtt_conn = mqtt.Client()
				mqtt_conn.connect(MQTT_SERVER, MQTT_PORT)
				mqtt_conn.publish(MQTT_TOPIC, response)
				now = datetime.datetime.now()
				print('MQTT To Server OK ! -->' , now)
			except:
				print('MQTT To Server Error !')
			print('------------------------------------------------------')
	else:
		try:
			power = serial.Serial('COM30', 9600, timeout=1)
			time.sleep(2.5)
		except:
			power = serial.Serial()
			time.sleep(1)
