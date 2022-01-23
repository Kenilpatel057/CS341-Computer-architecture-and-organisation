const int pingPin = 5;
int d;
int DELTA_T = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  d = ping(pingPin);
  Serial.println(d);
  delay(DELTA_T);
}

/*returns the distance in centimeters to where 
* the wave hit something and turned around
*/
int ping(int pingPin) {
  int duration;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  return duration / 29 / 2;
}