
# Pico 2W Blink Example
from machine import Pin
import time

# Create an LED object referencing the Pico 2W wireless LED
led = Pin("LED", Pin.OUT)

print("Starting Pico 2W Blink Loop!")

while True:
    led.toggle()       # Turn LED on if off, or off if on
    time.sleep(0.5)    # Wait half a second
