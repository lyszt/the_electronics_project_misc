#include <Arduino.h>

int buttonStatus = 0;
int currentState = 0;
int buttonPin = 9;

int redPin = 2;
int bluePin = 3;
int greenPin = 4;

void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int pinValue = digitalRead(buttonPin);
    if (pinValue != buttonStatus)
    {
        if (pinValue == 0)
        {
            currentState = (currentState + 1) % 3;
        }

        if(currentState == 0) {
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
        }
        else if(currentState == 1) {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
        }
        else {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
        }
        delay(50);
        buttonStatus = pinValue;
        Serial.println(currentState);
    }
}
// useless state machine which taught me states