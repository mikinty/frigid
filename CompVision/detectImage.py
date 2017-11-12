import http.client, urllib.request, urllib.parse, urllib.error, base64, json
import requests

region = "westus"
subscriptionKey = 'e282ecca3c86426eb5b416f9a5775f12'

pathToFile = "/Users/christophermorris/Downloads/IMG_0113.jpg"

with open(pathToFile, "rb") as f:
	data = f.read()

headers = {

    'Content-Type': 'application/json',
    'Ocp-Apim-Subscription-Key': subscriptionKey,
}

params = urllib.parse.urlencode({

    'visualFeatures': 'Categories,Description,Color',
    'language': 'en',
})

response = requests.request('post', "https://{}.api.cognitive.microsoft.com/vision/v1.0/analyze".format(region), data=data, headers=headers, params=params)
print(response)

j = response.json()
print(j)
#receivedData = response.read()
#decoded = receivedData.decode()
#print(parsed["description"]["tags"][0])
