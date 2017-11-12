import serial
import time

arduinoSerialData = serial.Serial('/dev/ttyACM2', 9600)

while 1:
    if (arduinoSerialData.inWaiting() > 0):
        # do something
        
        # myData = arduinoSerialData.readline()
        print('asdf')
        time.sleep(1)
        