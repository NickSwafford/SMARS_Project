/* This is a simple Arduino code that blinks the onboard LED and prints status messages */


// Make the Arduino library available to the source file
#include <Arduino.h>

// Create constants to be fixed at compile time
constexpr unsigned long LED_INTERVAL_MS = 500; // Interval at which to blink the LED (milliseconds)
constexpr unsigned long STATUS_INTERVAL_MS = 1000; // Interval at which to print the status (milliseconds)

// State variables to keep track of the last time the LED was toggled and the last time the status was printed
unsigned long previousLedTime = 0; // Last time the LED was toggled
unsigned long previousStatusTime = 0; // Last time the status was printed

// Keep track of the state of the LED
bool ledIsOn = false; // State of the LED (on or off), false means off, true means on. Default state is off

//
void setup()
{
    // Configure the onboard LED and begin in the off state
    pinMode(LED_BUILTIN, OUTPUT); // Set the LED pin as an output
    digitalWrite(LED_BUILTIN, LOW); // Ensure the LED is off at startup

    // Start communication between the Pico and the computer
    Serial.begin(115200); // Initialize serial communication at 115200 baud rate

    // Give the USB serial connection a brief moment to establish itself
    delay(1500); // Wait for 1.5 seconds to ensure the serial connection is ready

    Serial.println(); // Print a blank line to the serial monitor
    Serial.println("SMARS Arduino/C++ baseline started"); // Print a message indicating that the baseline has started

}

void loop()
{
    // Get the current time in milliseconds since the program started
    const unsigned long currentTime = millis();

    //Toggle the LED every 500 milliseconds
    if (currentTime - previousLedTime >= LED_INTERVAL_MS) // Check if it's time to toggle the LED
    {
        previousLedTime = currentTime; // Update the last time the LED was toggled
        ledIsOn = !ledIsOn; // Toggle the state of the LED

        // Update the LED state based on the ledIsOn variable
        digitalWrite(
            LED_BUILTIN,
            ledIsOn ? HIGH : LOW
        );
    }

    // Print a status message every 1000 milliseconds
    if (currentTime - previousStatusTime >= STATUS_INTERVAL_MS) // Check if it's time to print the status
    {
        previousStatusTime = currentTime; // Update the last time the status was printed

        // Print the current state of the LED to the serial monitor
        Serial.print("STATUS,uptime_ms=");
        Serial.println(currentTime); // Print the current uptime in milliseconds
    }
}