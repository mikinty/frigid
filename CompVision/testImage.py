########### Python 3.6 #############
import http.client, urllib.request, urllib.parse, urllib.error, base64, json
import subprocess

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
def identifyImage():
    req_body = open(filename, 'rb').read()
    try:
        conn = http.client.HTTPSConnection('westcentralus.api.cognitive.microsoft.com')
        conn.request("POST", "/vision/v1.0/analyze?%s" % params, req_body, headers)
        response = conn.getresponse()
        data = response.read()
        parsed = json.loads(data.decode())
    
        print(parsed["description"]["tags"][0])
        conn.close()

    except Exception as e:
        print('Error:')
        print(e)

def m():
    subprocess.check_output(["raspistill", "-o", "img.jpg"])
    identifyImage()


m()