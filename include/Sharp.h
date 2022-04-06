#pragma once

#include <Arduino.h>

class Sharp
{
private:
	
	uint8_t pin;
	unsigned int theoric_min_distance;
	unsigned int theoric_max_distance;
	unsigned int r1, r2; // Known reading-distance values to calculate this sharp sensor curve
	long d1, d2; // Known reading-distance values to calculate this sharp sensor curve
	long a;			// Curve parameters
	int b;			// Curve parameters
	int lastReading = 0;

public:
	// Dafault values were taken for my SHARP Sensor 2Y0A21
	Sharp(uint8_t sensorPin, unsigned int minD = 0, unsigned int maxD = 1500, unsigned int r1 = 479, long d1 = 100, unsigned int r2 = 102, long d2 = 600);
	int getRawReading(bool newReading = true);
	int getDistance();
	long getA();
	int getB();
};
