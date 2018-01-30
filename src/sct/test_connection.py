import pytest
import shlex, subprocess
import time
from connect_calculator import input_to_calculator, serial_input_to_calculator

@pytest.fixture
def calculator_app():
# setup
    proc = subprocess.Popen("./build/Calculator")
    time.sleep(1)
# yeld fixture to test
    yield proc

# teardown
    proc.kill()

def test_connection1(calculator_app):
    print("test_connection1")
    serial_input_to_calculator("1+2352+45234*234=*141+2352+45234*234=*141+2352+45234*234=*14")
    result = input_to_calculator("6")
    assert result["screenState"] == "621+"

def test_connection2(calculator_app):
    print("test_connection2")
    input_to_calculator("+")

def test_connection3(calculator_app):
    print("test_connection2")
    input_to_calculator("asdasd")
