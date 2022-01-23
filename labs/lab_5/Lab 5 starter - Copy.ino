// Program to simulate a ticker tape display
#include <LiquidCrystal.h>
#define DISPLAY_LEN 16  // LCD display width
#define LINE_1 0        // LCD LINE 1 
#define LINE_2 1        // LCD LINE 2

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 8;        // I/O pin for controlling the buzzer
char p[] = "Welcome CS341 Students! ";
int string_length = 24;
char data[DISPLAY_LEN+1];
int position=0;

 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(DISPLAY_LEN, 2);
}

void loop() {
  int start, j;
  
  // print the number of seconds on line 2 
  // starting at the middle:
  lcd.setCursor(8, LINE_2);
  lcd.print(millis() / 1000);
  
  // turn on the buzzer for a tone =1500 hz
  tone(buzzer,1500);
  delay(10);
  
  // turn the buzzer off
  noTone(buzzer);
  
 
    for (j=0; j < DISPLAY_LEN; j++)
    {
      data[j] = p[j];
    }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, LINE_1);
    lcd.print(data);
     
    delay(400);
  
    position =(position +1)% DISPLAY_LEN;
}