#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);
  
  // for test purposes only
  // EEPROM.write(0, 'h');  // overwrite something to simulate data corruption
  
  // print initial state of EEPROM
  Serial.println("initial check");
  printEEPROM();
  
  // if checksum is not OK, reinitialize EEPROM to default values
  if((checkSum() & 0xff) != EEPROM.read(0x08)) {
	initialize();
    Serial.println("EEPROM has been reinitialized");
  }
  else {
  	Serial.println("EEPROM checksum is OK");
  }
  
  printEEPROM();
}

void loop() {}

void printEEPROM() {
  for(int address = 0; address < 0x09; address++) {
    // read a byte from the current address of the EEPROM
    char value = EEPROM.read(address);
  
    if (address < 0x10)
      Serial.print("00");
    else if (address < 0x100)
      Serial.print("0");
    Serial.print(address, HEX);
    Serial.print("\t");
    Serial.print(value);
    Serial.println();
  }
  Serial.println();
}

void initialize() {
	//put some initial values in addresses 0x0 through 0x7
    //Example: EEPROM.write(0, 'B'); //store character B at address 0x0
    int twobytes = 14200; // For part 2
	

     /*  For part 2 
      EEPROM.write(7, twobytes); 
     */

    EEPROM.write(8, checkSum()); //recalculate checksum and store it at 0x8
}

char checkSum() {
  //implement a checksum algorithm
  
  return '0'; //just a default value so the code compiles
}