#include <Sharp.h>
#include <Arduino.h>

Sharp::Sharp(uint8_t sensorPin, unsigned int minD, unsigned int maxD, unsigned int r1, long d1, unsigned int r2, long d2)
{
	this->pin = sensorPin;
	this->theoric_min_distance = minD;
	this->theoric_max_distance = maxD;
	this->r1 = r1;
	this->r2 = r2;
	this->d1 = d1;
	this->d2 = d2;

	this->b = (r2 * d2 - r1 * d1) / (d2 - d1);
	this->a = (r1 - this->b) * d1;
	this->lastReading = this->getRawReading(true);
}

int Sharp::getRawReading(bool newReading)
{
	if (newReading)
	{
		this->lastReading = analogRead(this->pin);
	}

	return this->lastReading;
}

int Sharp::getDistance()
{
	unsigned int distance = this->a / (this->getRawReading() - this->b);
	if (distance <= this->theoric_min_distance)
		return this->theoric_min_distance;
	if (distance >= this->theoric_max_distance)
		return this->theoric_max_distance;
	return distance;
}

long Sharp::getA(){return this->a;}
int Sharp::getB(){return this->b;}
