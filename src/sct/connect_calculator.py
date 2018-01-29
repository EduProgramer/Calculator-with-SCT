import errno, time
import requests, json

def connect_with_post_to_calculator(payload):
    calculator_address = "http://localhost:34568/SctServer/Action/"

    s = requests.Session()

    # TODO uniform data format for communication
    r = requests.post(calculator_address, data=payload)
    print(r.status_code)
    print(r.text)
