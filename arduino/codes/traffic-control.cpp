#include <Arduino.h>

int buttonStatus = 0;
int currentState = 0;
int buttonPin = 9;

int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int buzzerPin = 7;

int countBeforeSwitch = 0;

void responsiveDelay(int milliseconds)
{
    for (int i = 0; i < milliseconds; i += 50)
    {
        int pinValue = digitalRead(buttonPin);
        if (pinValue == 0)
        {
            currentState = 2;
            return;
        }
        delay(50);
    }
}

// Traffic signal
void setup()
{
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int pinValue = digitalRead(buttonPin);
    if (pinValue != buttonStatus)
    {
        if (pinValue == 0)
        {
            delay(500);
            currentState = 2;
        }
        buttonStatus = pinValue;
    }

    if (currentState == 0)
    {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        ++countBeforeSwitch;
        if (countBeforeSwitch == 2)
        {
            currentState = (currentState + 1) % 3;
            countBeforeSwitch = 0;
        }
        responsiveDelay(5000);
        ;
    }
    else if (currentState == 1)
    {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        ++countBeforeSwitch;
        if (countBeforeSwitch >= 1)
        {
            digitalWrite(buzzerPin, HIGH);
            delay(2000);
            digitalWrite(buzzerPin, LOW);
        }
        if (countBeforeSwitch == 2)
        {
            currentState = (currentState + 1) % 3;
            countBeforeSwitch = 0;
        }
        delay(2000);
    }
    else
    {
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        ++countBeforeSwitch;
        if (countBeforeSwitch == 2)
        {
            currentState = (currentState + 1) % 3;
            countBeforeSwitch = 0;
        }
        responsiveDelay(5000);
    }
}