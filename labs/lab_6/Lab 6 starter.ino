int lightPin = A0;   // Analog pin for CdS Photoresistor (light sensor)
int motionPin = 7;  // Pin for input from PIR Sensor (motion sensor)
int nightLight = 13;    // Pin for output to light bulb
int waitTime = 2000;// How long should the light stay on once motion has been detected?

void setup() {
  Serial.begin(9600);
  
  pinMode(nightLight, OUTPUT);
  pinMode(lightPin, INPUT);
  pinMode(motionPin, INPUT);
  
  digitalWrite(nightLight, LOW); //make sure the light is off
}
   
void loop() {
	/* look at lab instructions for logic
	*
	* be sure to make use of analogRead()
	*/
	
}

