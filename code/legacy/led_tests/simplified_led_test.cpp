#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    const unsigned long serialWaitStart = millis();

    while (!Serial && millis() - serialWaitStart < 3000)
    {
        delay(10);
    }

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.println();
    Serial.println("Pico 2 W LED diagnostic started");

    Serial.print("LED_BUILTIN pin value: ");
    Serial.println(LED_BUILTIN);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED command: ON");
    delay(2000);

    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED command: OFF");
    delay(2000);
}