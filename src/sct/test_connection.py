import pytest
import shlex, subprocess
import time
from connect_calculator import connect_with_post_to_calculator

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
    connect_with_post_to_calculator("1")
    connect_with_post_to_calculator("=")

def test_connection2(calculator_app):
    print("test_connection2")
    connect_with_post_to_calculator("+")

def test_connection3(calculator_app):
    print("test_connection2")
    connect_with_post_to_calculator("asdasd")
