#include <Arduino.h>
#include <movingAverage.h>

//moving average
const int numReadings = 10;
float readings[numReadings]; // the readings from the analog input
int readIndex = 0;			 // the index of the current reading
float total = 0;			 // the running total
float average = 0;

void prepareMovingAverage()
{
	for (int thisReading = 0; thisReading < numReadings; thisReading++)
	{
		readings[thisReading] = 0;
	}
}
//used: https://www.arduino.cc/en/Tutorial/Smoothing 
float calcMovingAverage(float value)
{
	total = total - readings[readIndex];
	readings[readIndex] = value;
	total = total + readings[readIndex];
	readIndex = readIndex + 1;
	if (readIndex >= numReadings)
	{
		average = total / numReadings;
		readIndex = 0;
		return average;
	}
	delay(1); // delay in between reads for stability
	return -1;
}