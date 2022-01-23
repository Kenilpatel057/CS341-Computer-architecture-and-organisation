/*
  Program to measure the pulse duration of a pulse generator.
 */


// Define function for Pins:
int wave = 10;/* pulse generator input pin */

// the setup routine runs once when you press reset:
void setup() {                
	// initialize the digital pins
	pinMode(wave, INPUT);   
	
	// Add a line printed to the serial monitor
	Serial.begin(9600);
	Serial.println("Hello world.  Watch me measure the frequency.");  
}

// the loop routine runs over and over again forever:
void loop() {
	
	while (digitalRead(wave)) {	} //skip the first positive level
	while (!digitalRead(wave)){	} //wait until the next positive level
	
	long count = 0;  //count how many times it polls 
	//Note: this variable is just to see how many times we poll, it shouldn't be used in calculations
	                 
	unsigned long start_time = micros();  //measure the current time in usec
	
/* Your code should look something like this:
	 * 
	 * while (wave_still_high)
	 *	  increment count
	 * read_time
	 * while (wave_still_low)
	 *	  increment count
	 * read_time_again
	 *
	 * calculate the period in seconds
	 * calculate the frequency in seconds
	 */	
	 
	 //Serial.println(frequency, 5); //the second argument shows more decimal places
	
	delay(5000); //wait 5 seconds and do the test again
	
}