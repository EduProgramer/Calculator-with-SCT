import http.client
import urllib
import time
import json

def asert_result_flags(result):
    assert result["unknownInput"] == False
    assert result["badServerInput"] == False

def input_to_calculator(payload):
    headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
    conn = http.client.HTTPConnection("localhost:34568")
    conn.request("POST", "/SctServer/Action", payload, headers)
    response = conn.getresponse()
    data = response.read()
    conn.close()
    time.sleep(0.1)
    result = json.loads(data)
    asert_result_flags(result)
    return result

def serial_input_to_calculator(inputs):
    for input in inputs:
        result = input_to_calculator(input)
    return result
