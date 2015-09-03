#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); 			  // RX, TX
#define BLYNK_PRINT SwSerial
#include <BlynkSimpleSerial.h> 			  // Blynk Serial USB library. This can be replaced with both Ethernet and Wifi
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 			  // i2C converter compatible library

LiquidCrystal_I2C lcd(0x27, 16, 2);               // set the LCD address to 0x27 for a 16 chars and 2 line display

int pinState;  					  // initialize pinState variable

char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxk"; // Blynk Authnetication Token

void setup()
{
	SwSerial.begin(9600);
	Blynk.begin(auth);

	pinMode(2, OUTPUT);    		 	  // Set D2 pin to OUTPUT mode
	lcd.init();                     	  // Initialize the LCD
	lcd.backlight();
}

void loop()
{

	pinState = digitalRead(2); 	          // Assign D2 pin state value to pinState variable

	// ** Start condition to Print D2 pin state in LCD **

	if (pinState == 1) 			  // Check the pinState variable value
	{
		lcd.clear();			  // Clear previously printed values in the LCD
		lcd.print("Blynk D2 : ON");       // Print The Message on LCD
		lcd.setCursor(0, 1);		  // Set the cursor position in LCD to print the Message
		delay(200);		          // Set delay (time interval) for the loop
	}
	else
	{
		lcd.clear();
		lcd.print("Blynk D2 : OFF");
		lcd.setCursor(0, 1);
		delay(200);
	}

	// ** End condition **

	Blynk.run();

}
