#include <Arduino.h>
#include <Sharp.h>

/*
You need to initialize your sensor:

Sharp(sensorPin,  <- The analog pin of your sharp sensor
		minD,  <- The minimum accepted distance of your sensor
		maxD, <- The maximum accepted distance of your sensor
		reading1, <- These readings and thei correspondant distances are for you to calibrate. More on this later
		distance1, 
		reading2, 
		distance2)

NOW IS LATER
The only mandatory parameter is the sensorPin
If you want to calibrate your sensor you must use the getRawReading() method and take notes on the results you see
You only need 2 points
Check the  reading value for any two distances and then you can pass this data as parameters to the constructor
This will create a function that suits your sensor
*/


Sharp sharp = Sharp(0, 100, 800, 102, 1300, 512, 200);

void setup()
{
	Serial.begin(9600);
	Serial.println(sharp.getA()); // Gets one parameter of the function
	Serial.println(sharp.getB()); // Gets the other parameter of the function
	Serial.println(sharp.getRawReading()); // It's just an analogRead of the sensor without any calculations made
	Serial.println(sharp.getDistance()); // Prints the distance in whatever units you used in your constructor (In my case were mm)
	delay(20); //Optional
}

void loop()
{
	// For you to plot in the Arduino plotter:
	Serial.print("SHARP:");
	Serial.print(sharp.getDistance());
	Serial.println();
	delay(20); // You can play with the delay
}