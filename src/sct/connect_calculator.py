import http.client
import urllib
import time
import json

def input_to_calculator(payload):
    headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
    conn = http.client.HTTPConnection("localhost:34568")
    conn.request("POST", "/SctServer/Action", payload, headers)
    response = conn.getresponse()
    #print (response.status, response.reason)
    data = response.read()
    conn.close()
    time.sleep(0.1)
    return json.loads(data)

def serial_input_to_calculator(inputs):
    for input in inputs:
        result = input_to_calculator(input)
    return result
