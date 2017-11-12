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

dic = ["bottle", "apple", "orange", "banana", "chips", "carton", "meat"]

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
            if tags[i] in dic:
                print(tags[i])
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
