/*
  Memory Mapped I/O Exploration
 */

/* Figure out what bits control pin 13. make use of the provided functions
*  to do this. 
*/
void setup() { 
  // Setup for Serial output
  Serial.begin(9600);  
  
}

/*once you know which bit can be used to turn pin 13 on and off, 
* try to blink an led in loop without using digitalWrite().
*/ 
void loop() {

}

/* example call displayRAM((char *) 0x8E0, (char *) 0x8FF, true);
* if hex is false, letters and numbers will be printed, and all other values will be represented as '.'  */
void displayRAM(char *start, char *endd, bool hex) {
  char *array;
  for(array = start; array < endd; array += 0x10) {
    //create row number
    if (array < (char *)0x10)
      Serial.print('0');
    if (array < (char *)0x100)
      Serial.print('0');
    Serial.print((int)array, HEX);
    Serial.print(": ");
    //for each index (0 through 15 inclusive)
    for(int i = 0; i < 0x10; i++) {
      if(hex) {
        if (array[i] >= 0x00 && array[i] < 0x10)
          Serial.print('0');
        Serial.print(array[i] & 0xFF, HEX); //0xFF is our bitmask
      } else {
        Serial.print((array[i] >= ' ' && array[i] <= 'z') ? array[i] : '.');
      }
      Serial.write(' ');
    }
    Serial.println();
  }
  Serial.println();
}

//Example call displayBits((char *) 0x100);
//pretty prints an address in binary
void displayBits(char *address) {
  Serial.print("0x");
  Serial.print((int) address, HEX);
  Serial.print(": ");
  Serial.println(address[0], BIN);
}