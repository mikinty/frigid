from nanpy import Arduino as A

# setup
A.pinMode(1, A.OUTPUT)

while True:
    A.digitalWrite(1, HIGH)
    A.delay(400)
    A.digitalWrite(1, LOW)
    A.delay(400)