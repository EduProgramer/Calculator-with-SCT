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

def test_single_add_operation(calculator_app):
    result = serial_input_to_calculator("5234+2346=")
    assert result["screenState"] == "7580"

def test_single_subtract_operation(calculator_app):
    result = serial_input_to_calculator("123-234=")
    assert result["screenState"] == "-111"

def test_single_multply_operation(calculator_app):
    result = serial_input_to_calculator("5234*23=")
    assert result["screenState"] == "120382"

def test_single_divide_operation(calculator_app):
    result = serial_input_to_calculator("3450/46=")
    assert result["screenState"] == "75"

def test_add_operations(calculator_app):
    result = serial_input_to_calculator("5234+2346=")
    assert result["screenState"] == "7580"
    result = serial_input_to_calculator("5+5=")
    assert result["screenState"] == "10"
    result = serial_input_to_calculator("5+5=")
    assert result["screenState"] == "10"

def test_multply_operations(calculator_app):
    result = serial_input_to_calculator("5234*23=")
    assert result["screenState"] == "120382"
    result = serial_input_to_calculator("5234*23=")
    assert result["screenState"] == "120382"
    result = serial_input_to_calculator("524*223=")
    assert result["screenState"] == "116852"
