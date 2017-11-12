########### Python 3.6 #############
import http.client, urllib.request, urllib.parse, urllib.error, base64, json
import subprocess
import serial

subscription_key = 'e282ecca3c86426eb5b416f9a5775f12'

uri_base = 'westcentralus.api.cognitive.microsoft.com'
filename = 'img.jpg'

headers = {
    'Content-Type': 'application/octet-stream',
    'Ocp-Apim-Subscription-Key': subscription_key,
}

params = urllib.parse.urlencode({
    'visualFeatures': 'Categories,Description,Color',
    'language': 'en',
})

arduinoSerialData = serial.Serial('/dev/ttyACM2', 9600)
arduinoMainMovement = serial.Serial('/dev/ttyACM1', 9600)

dic = ["bottle", "apple", "orange", "banana", "chips", "carton", "meat"]
boxes = [None, None, None, None]

front = 0
back = 100
left = 0
right = 100

def dropItem(box):

    if(box==1):
        arduinoMainMovement.write(b'1')
    elif(box==2):
       arduinoMainMovement.write(b'2')
    elif box==3:
        arduinoMainMovement.write(b'3')
    elif box==4:
       arduinoMainMovement.write(b'4')
    #drop box 

def identifyImage():
    req_body = open(filename, 'rb').read()
    try:
        conn = http.client.HTTPSConnection('westcentralus.api.cognitive.microsoft.com')
        conn.request("POST", "/vision/v1.0/analyze?%s" % params, req_body, headers)
        response = conn.getresponse()
        data = response.read()
        parsed = json.loads(data.decode())

        tags = parsed["description"]["tags"]
        for i in range(len(tags)):
            #print(tags[i])
            if tags[i] in dici:
                print(tags[i])
                for j in range(4):
                    if boxes[j]==None:
                        boxes[j]=tags[i]
                        #TODO: set color of box j to right color
                        dropItem(j)
                break
        else:
            print("Couldn't identify image. Closest match: ", tags[0])
        conn.close()

    except Exception as e:
        print('Error:')
        print(e)

def m():
    while(1):
        if (arduinoSerialData.inWaiting() > 0):
            arduinoSerialData.readline()
            subprocess.check_output(["raspistill", "-o", "img.jpg"])
            identifyImage()


m()
