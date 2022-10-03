// Weather station and wi-fi libraries
#include <U8glib.h>                                         // Bitmap graphics library
#include <ESP8266WiFi.h>                                    // Wifi library
#include <Wire.h>                                           // I2C library                                
#include <Adafruit_SSD1306.h>                               // OLED driver
#include "ArduinoJson-v5.13.5.h"                            // Json library

// TM1638 Libraries
#include <InvertedTM1638.h>
#include <TM1638.h>
#include <TM1638QYF.h>
#include <TM1640.h>
#include <TM16XX.h>
#include <TM16XXFonts.h>

// RTC Libraries
#include <DS3231.h>
#include <Streaming.h>
#include <SPI.h>


/**
 * Made with Marlin Bitmap Converter
 * http://marlinfw.org/tools/u8glib/converter.html
 *
 * 
 * Comments for this bitmap comply with the comments for the rest of the bitmaps
 * PROGMEM is used to store the data in flash memory instead of SRAM
 */

#pragma once                         // Loads only once
#define CLOUD_BMPWIDTH  64           // Width size in pixels
#define CLOUD_BMPHEIGHT 23           // Height size in pixels
const unsigned char bitmap_cloud[] PROGMEM = {  // Saves the value as a constant char in flash memory
  B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000001,B11111111,B10000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00011111,B11111111,B11110000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B11111111,B11111111,B11111110,B00000000,B00000000,
  B00000000,B00000000,B00000001,B11111110,B00000000,B01111111,B10000000,B00000000,
  B00000000,B00000000,B11111111,B11110000,B00000000,B00001111,B11100000,B00000000,
  B00000000,B00000111,B11111111,B11000000,B00000000,B00000011,B11110000,B00000000,
  B00000000,B00011111,B11111111,B00000000,B00000000,B00000001,B11111000,B00000000,
  B00000000,B01111111,B00000000,B00000000,B00000000,B00000001,B11111000,B00000000,
  B00000000,B11111110,B00000000,B00000000,B00000000,B00000001,B11111100,B00000000,
  B00000011,B11111100,B00000000,B00000000,B00000000,B00000001,B11111111,B11100000,
  B00011111,B11111100,B00000000,B00000000,B00000000,B00000001,B11111111,B11111000,
  B01111111,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,
  B11111110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111111,
  B11111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,
  B11111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,
  B11111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,
  B11111100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,
  B11111111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,
  B00111111,B11000000,B00000000,B00000000,B00000000,B00000000,B00000011,B11111110,
  B00001111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11110000,
  B00000001,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11000000,
  B00000000,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B00000000
};


#pragma once
#define CLOSUN_BMPWIDTH  64
#define CLOSUN_BMPHEIGHT 23
const unsigned char bitmap_clo_sun[] PROGMEM = {
  B00000000,B00000000,B00000000,B00000000,B00000011,B10000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000011,B10000000,B00011000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01110000,B00000000,
  B00000000,B00000000,B00000000,B00111100,B00001111,B11111111,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000110,B01111000,B00000011,B11100000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B11100000,B00000000,B01110000,B00000000,
  B00000000,B00000000,B00000111,B11111111,B11000000,B00000000,B00111000,B11111000,
  B00000000,B00000000,B00011110,B00000000,B11111000,B00000000,B00011000,B11100000,
  B00000000,B00000000,B01110000,B00000000,B00001110,B00000000,B00011000,B00000000,
  B00000000,B00000001,B11000000,B00000000,B00000111,B00000000,B00011000,B00000000,
  B00000000,B00000011,B10000000,B00000000,B00000011,B10000000,B00110000,B00000000,
  B00000000,B00000011,B10000000,B00000000,B00000001,B11111111,B11100000,B00000000,
  B00000000,B00000011,B00000000,B00000000,B00000000,B00000000,B11100111,B10000000,
  B00000000,B11111111,B00000000,B00000000,B00000000,B00000000,B01110001,B10000000,
  B00000111,B10000000,B00000000,B00000000,B00000000,B00000000,B01110000,B00000000,
  B00001110,B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,B00000000,
  B00001100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11000000,
  B00011100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11100000,
  B00001100,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01100000,
  B00001110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01100000,
  B00000111,B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11000000,
  B00000001,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B10000000,
  B00000000,B00011111,B11111111,B11111111,B11111111,B11111111,B11111000,B00000000 
};


#pragma once
#define RAIN_BMPWIDTH  64
#define RAIN_BMPHEIGHT 23
const unsigned char bitmap_rain[] PROGMEM = {

  B00000000,B00000000,B00000111,B11100000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000001,B11111111,B11111111,B10000000,B00000000,B00000000,B00000000,
  B00000000,B00001111,B11110000,B00001111,B11110000,B00000000,B00000000,B00000000,
  B00000000,B00111111,B00000000,B00000000,B11111100,B00000000,B00000000,B00000000,
  B00000000,B01111000,B00000000,B00000000,B00111111,B11111110,B00000000,B00000000,
  B00000001,B11110000,B00000000,B00000000,B00001111,B11111111,B11100000,B00000000,
  B00000001,B11100000,B00000000,B00000000,B00000110,B00000001,B11111000,B00000000,
  B00000011,B11000000,B00000000,B00000000,B00000000,B00000000,B00111110,B00000000,
  B00000011,B11000000,B00000000,B00000000,B00000000,B00000000,B00011111,B10000000,
  B00011111,B11000000,B00000000,B00000000,B00000000,B00000000,B00001111,B11111000,
  B00111110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111100,
  B01111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011110,
  B11110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001111,
  B11110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001111,
  B11110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001111,
  B01111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011110,
  B00111110,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111100,
  B00001111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11110000,
  B00000001,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B10000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000011,B11000000,B00000011,B11000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000000,B00000011,B11000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000011,B11000011,B11000011,B11000011,B11000000,B00000000,


};


#pragma once
#define CLEAR_BMPWIDTH  40
#define CLEAR_BMPHEIGHT 23
const unsigned char bitmap_clear[] PROGMEM = {
  B00000000,B00000000,B00011000,B00000000,B00000000,
  B00000000,B00000000,B00011000,B00000000,B00000000,
  B00000000,B00000000,B00011000,B00000000,B10000000,
  B00000001,B11000000,B00000000,B00000011,B10000000,
  B00000000,B11100000,B00000000,B00000111,B00000000,
  B00000000,B00110000,B11111111,B10000100,B00000000,
  B00000000,B00000111,B11111111,B11100000,B00000000,
  B00000000,B00001111,B11111111,B11110000,B00000000,
  B00000000,B00011111,B11111111,B11111000,B00000000,
  B00000000,B00011111,B11111111,B11111000,B00000000,
  B00000000,B00111111,B11111111,B11111100,B00000000,
  B00011111,B00111111,B11111111,B11111100,B11111000,
  B00001010,B00111111,B11111111,B11111100,B01010000,
  B00000000,B00011111,B11111111,B11111100,B00000000,
  B00000000,B00011111,B11111111,B11111000,B00000000,
  B00000000,B00001111,B11111111,B11110000,B00000000,
  B00000000,B00000111,B11111111,B11100000,B00000000,
  B00000000,B00110011,B11111111,B11000000,B00000000,
  B00000000,B01110000,B01111110,B00001110,B00000000,
  B00000000,B11100000,B00000000,B00000111,B00000000,
  B00000000,B00000000,B00000000,B00000001,B00000000,
  B00000000,B00000000,B00011000,B00000000,B00000000,
  B00000000,B00000000,B00011000,B00000000,B00000000
};


#pragma once
#define THUND_BMPWIDTH  64
#define THUND_BMPHEIGHT 23
const unsigned char bitmap_thund[] PROGMEM = {
  B00000000,B00000000,B00000111,B11111111,B11111000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00011111,B11111111,B11111111,B00000000,B00000000,B00000000,
  B00000000,B00000000,B01111111,B11000000,B01111111,B11000000,B00000000,B00000000,
  B00000000,B00000001,B11111100,B00000000,B00001111,B11111111,B11111111,B10000000,
  B00000000,B00000011,B11111000,B00000000,B00000011,B11111111,B11111111,B11100000,
  B00000000,B00000011,B11110000,B00000000,B00000001,B11111111,B11111111,B11111000,
  B00000000,B00001111,B11100000,B00000000,B00000001,B11110000,B00000000,B11111110,
  B00000000,B11111111,B11100000,B00000000,B00000000,B11000000,B00000000,B01111111,
  B00000011,B11111111,B11110000,B00000000,B00000000,B00000000,B00000000,B00111111,
  B00001111,B11110000,B00000000,B00000000,B00000000,B00000000,B00000000,B00011111,
  B00111111,B11000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111111,
  B11111111,B11000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111111,
  B11111000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111110,
  B11111100,B00000000,B00000000,B00000000,B00000000,B00000000,B00001111,B11111100,
  B01111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11110000,
  B00111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B10000000,
  B00000000,B00000000,B00000000,B11111111,B11100000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000001,B11111111,B11111100,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000011,B11111111,B11111100,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B01111111,B11000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B11111110,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000011,B11110000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000111,B10000000,B00000000,B00000000,B00000000,B00000000
};


#pragma once
#define MIST_BMPWIDTH  64
#define MIST_BMPHEIGHT 19
const unsigned char bitmap_mist[] PROGMEM = {
  B00000000,B00000000,B01110000,B11111111,B11111111,B11110000,B01110000,B00000000,
  B00000000,B00000000,B11110000,B11111111,B11111111,B11111000,B11110000,B00000000,
  B00000000,B00000000,B01100000,B01111111,B11111111,B11100000,B01100000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000011,B11000001,B11111111,B11111111,B11000011,B11000001,B11111111,B11110000,
  B00000011,B11000001,B11111111,B11111111,B11000011,B11000001,B11111111,B11110000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000011,B11111111,B11110000,B11110000,B11111111,B11111111,B11110000,B11110000,
  B00000011,B11111111,B11110000,B11110000,B11111111,B11111111,B11110000,B11110000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00100000,B00011111,B11111111,B11100000,B00100000,B00000000,
  B00000000,B00000000,B11110000,B01111111,B11111111,B11111000,B11110000,B00000000,
  B00000000,B00000000,B01110000,B01111111,B11111111,B11110000,B11110000,B00000000 
};


#pragma once
#define SNOW_BMPWIDTH  35
#define SNOW_BMPHEIGHT 23
const unsigned char bitmap_snow[] PROGMEM = {
  B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B01000000,B00000000,
  B00000000,B00000110,B11101100,B00000000,
  B00000000,B00000111,B11111100,B00000000,
  B00000000,B00000000,B11110000,B00000000,
  B00000001,B10000000,B11100000,B00110000,
  B00001101,B10001110,B11101110,B00110110,
  B00000111,B10001111,B11111110,B00111100,
  B00000111,B11111100,B11100111,B11111100,
  B00001100,B00111100,B11100111,B10000110,
  B00000000,B00111111,B11111111,B11000000,
  B00000001,B11100011,B11111000,B11110000,
  B00000000,B01111111,B11111111,B11000000,
  B00001100,B00111100,B11100111,B10000110,
  B00000111,B11111100,B11100111,B11111100,
  B00000111,B10001111,B11111110,B00111100,
  B00001101,B10001110,B11101110,B00110110,
  B00000001,B10000000,B11100000,B00110000,
  B00000000,B00000000,B11100000,B00000000,
  B00000000,B00000111,B11111100,B00000000,
  B00000000,B00000110,B11101100,B00000000,
  B00000000,B00000000,B01000000,B00000000,
  B00000000,B00000000,B00000000,B00000000 
};

// TM1638 Macros
#define TM1638_STB 14 // D5 pin 
#define TM1638_CLK 12 // D6 pin
#define TM1638_DIO 13 // D7 pin
TM1638 module(TM1638_DIO, TM1638_CLK, TM1638_STB); 


// RTC globals
DS3231 rtc;
int hour;
int minute;
int second;
bool h12;
bool PM;
RifTime t;
char buffer[24];

int low = 50;         // Low light value
int low_medium = 100; // Low-medium light value
int medium = 180;     // Medium light value
int high = 255;       // High light value
int Clear_LED = 0;    // D3 pin
int Yellow_LED = 2;   // D4 pin

Adafruit_SSD1306 display(LED_BUILTIN);                      // Create instance of SSD1306 called display

 // Wi-Fi login values and API. Values were removed for security reasons.
const char* ssid     = "SSID_Name";                         // SSID of local network
const char* password = "Network_Pass";                      // Password on network
String APIKEY = "Forecast_API_Key";                         // Openweathermap.org api key
String CityID = "2650752";                                  // City's ID
 
 
 
WiFiClient client;                                          // Start wifi client
char servername[]="api.openweathermap.org";                 // Specify server name

String result;                                              // String var to hold result
 
int  counter = 60;                                          // Counter var

String weatherMain ="";
String weatherDescription ="";                              // Empty string to hold descrip
String weatherLocation = "";                                // Empty string to hold location            
String Country;                                             // Download var for country
float Temperature;                                          // Download var for temp
float Humidity;                                             // Download var for humidity
float Pressure;                                             // Download var for pressure
 
 
void setup() {

  // Set-up the 7-segement display
  module.clearDisplay();
  module.setupDisplay(true, 2);

  pinMode(Clear_LED, OUTPUT);                                 // Setting up the clear LED
  pinMode(Yellow_LED, OUTPUT);                                // Setting up the yellow LED
  Wire.begin(); 
  
  Serial.begin(38400);                                        // Start serial comms for debug
  Serial.println(F("\nDS3231 Hi Precision Real Time Clock")); //Print message in serial monitor

  // RTC Set-up
  int seconds, minutes, hours, dayofweek, dayofmonth, month, year;
  hours = 14;
  minutes = 05;
  seconds = 0;

  dayofweek = 6; // Day of week, any day can be first, counts 1...7

  year = 2019;     // Year
  month = 12;      // Month 1...12
  dayofmonth = 1; // Day of month, 1...31
  rtc.setClock(year,month,dayofmonth,hours,minutes,seconds);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);                // Start the OLED @ Hex addy 0x3C
  display.display();                                        // Show the Adafruit Logo
  delay(2);                                                 // For 2 milli seconds
  display.clearDisplay();                                   // Clear display @ beginning of each loop
  display.setTextSize(1);                                   // Set smallest text size
  display.setTextColor(WHITE);                              // Set text color to WHITE
  display.setCursor(0,0);                                   // Cursor to upper left
  display.print("Connecting");                              // Setup info
  Serial.println("Connecting");                             // Setup info
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {                   // While loop that checks wi-fi status and prints in the serial monitor
     delay(500);
     Serial.print("*");
  }
 
 
  display.display();                                        // Show display
  delay(1000);                                              // Wait
  display.clearDisplay();                                   // Clear display
  display.print("Connected!");                              // Show info
  Serial.println("Connected");                              // Show info
  delay(1000);                                              // Wait
  display.display();                                        // Show display
  delay(1000);                                              // Wait
  display.clearDisplay();                                   // Clear display
 
}
 
void loop() {
 
  rtc.getTime(t);
  Serial << rtc.toString(buffer) << endl;
  Serial << "Timestamp: " << rtc.getTimestamp() << endl;
 
    if(counter == 60) {                                     // Get new data every 10 minutes
      counter = 0;                                          // Reset counter
      displayGettingData();                                 // Call function
      delay(1000);                                          // Wait
      getWeatherData();                                     // Call function
    }
    else {                                                  // Otherwise
      counter++;                                            // Increment counter
 
      if(weatherMain == "Clear"){                               // Check if main matches
        displayWeatherClear(Temperature, weatherDescription);   // Call function
        digitalWrite(Yellow_LED, HIGH); //Set yellow LED to high
        digitalWrite(Clear_LED, LOW);   //Stop clear LED
      }
      
       else if (weatherDescription == "few clouds"){            // Check if description matches
        displayWeatherCloSun(Temperature, weatherDescription);  // Call function
        analogWrite(Clear_LED, low);   //Set clear LED to dim light
        digitalWrite(Yellow_LED, LOW); //Stop yellow LED
      }
      
      else if (weatherMain == "Clouds"){                         // Check if main matches
        displayWeatherCloud(Temperature, weatherDescription);    // Call function
        analogWrite(Clear_LED, low_medium);  // Set clear LED to brighter light
        digitalWrite(Yellow_LED, LOW);       // Stop yellow LED
      }
      
      else if (weatherMain == "Rain" || weatherMain == "Drizzle"){  // Check if main matches
        displayWeatherRain(Temperature, weatherDescription);        // Call function
        analogWrite(Clear_LED, medium);  // Set clear LED to medium brightness
        digitalWrite(Yellow_LED, LOW);  // Stop yellow LED
      }
      
      else if (weatherMain == "Thunder"){                          // Check if main matches
        displayWeatherThund(Temperature, weatherDescription);      // Call function
        analogWrite(Clear_LED, high);   // Set clear LED to highest brightness
        digitalWrite(Yellow_LED, LOW);  // Stop yellow LED
      }
      
      else if (weatherMain == "Mist" || weatherMain == "Smoke" || weatherMain == "Haze" || weatherMain == "Dust" || weatherMain == "Fog" || weatherMain == "Squall"){     // Check if main matches
      displayWeatherMist(Temperature, weatherDescription);                                                                                                                // Call function
        analogWrite(Clear_LED, medium);   // Set clear LED to medium brightness
        digitalWrite(Yellow_LED, LOW);    // Stop yellow LED
      }
      
      else if (weatherMain == "Snow"){                        // Check if main matches
        displayWeatherSnow(Temperature, weatherDescription);  // Call function
        analogWrite(Clear_LED, high);   // Set clear LED to highest brightness
        digitalWrite(Yellow_LED, LOW);  // Stop yellow LED
      };
 
        for (int i = 0; i <=5; i++) {                 //For loop for 7 segmet display
          module.setDisplayToDecNumber(i,0,false);
          delay(1000);
        }
        
      digitalWrite(Clear_LED, LOW);   // Sets clear LED to low during second screen
      digitalWrite(Yellow_LED, LOW);  // Sets yellow LED to low during second screen
      
      displayConditions( weatherLocation, Humidity, Pressure); // Call function for second screen
      delay(100);
          for (int i = 0; i <=5; i++) {              //For loop for 7 segment display
            module.setDisplayToDecNumber(i,0,false);
            delay(1000);
          }
    }
}
 
void getWeatherData() {                                       // Client function to send/receive GET request data.
  if (client.connect(servername, 80)) {                     // Starts client connection, checks for connection
    client.println("GET /data/2.5/weather?id="+CityID+"&units=metric&APPID="+APIKEY);     // API request
    client.println("Host: api.openweathermap.org");                                       // Host 
    client.println("User-Agent: ArduinoWiFi/1.1");                                        // User who receive the data
    client.println("Connection: close");                                                  // Closes connection after data transfer
    client.println();                                                                     // Empty line
  }
  
  else {
    Serial.println("connection failed");                    // Error message if client does not connect
    Serial.println();                                       // Empty line
  }
 
  while(client.connected() && !client.available()) delay(1); // Waits for data
  
  while (client.connected() || client.available()) {         // Connected or data available
    char c = client.read();                                  // Gets byte from ethernet buffer
      result = result+c;
    }
 
  client.stop();                                             // Stops client
  result.replace('[', ' ');                                  // Lines bellow print the data in the serial monitor 
  result.replace(']', ' ');
  Serial.println(result);
 
Serial.println(result);
StaticJsonBuffer<1024> json_buf;                             // Sets Json Buffer size to 1024
JsonObject &root = json_buf.parseObject(result);             // Takes data and parses it into objects

if (!root.success()){                                         // If parsing is not successful print following line in serial monitor
  Serial.println("parseObject() failed");
}
 
String location = root["name"];                              // String for parsed city
String country = root["sys"]["country"];                     // String for parsed country
float temperature = root["main"]["temp"];                    // Float for parsed temperature
float humidity = root["main"]["humidity"];                   // Float for parsed humidity
String weather = root["weather"]["main"];                    // String for parsed main weather condition
String description = root["weather"]["description"];         // String for parsed weather description
float pressure = root["main"]["pressure"];                   // Float for parsed pressure

// Assigning parsed data to variables for easier use

weatherMain = weather;
weatherDescription = description;
weatherLocation = location;
Country = country;
Temperature = temperature;
Humidity = humidity;
Pressure = pressure;
}
 
void displayWeatherCloud(float Temperature, String description){ // Show location & weather function
  display.clearDisplay();                                     // Clear display
  display.drawBitmap(0, 0, bitmap_cloud, 64, 23, WHITE);      // Print bitmap image
  display.display();                                          // Display
  display.setCursor(70,0);                                    // Set cursor to specific location
  display.setTextSize(2);                                     // Set text size for function bellow
  display.print(Temperature,1);                               // Print temperature
  display.println("C");                                       // Add C for Celsius
  display.display();                                          // Display
  display.setTextSize(0.5);                                   // Set text size to smallest
  display.setCursor(0,25);                                    // Set cursor
  display.println(description);                               // Print weather description
  display.display();                                          // Display
  delay(2000);                                                // Two seconds delay
}

// Comments above comply for the displayWeather"" functions below

 void displayWeatherCloSun(float Temperature, String description) {         
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_clo_sun, 64, 23, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayWeatherRain(float Temperature, String description) {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_rain, 64, 23, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayWeatherThund(float Temperature, String description) {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_thund, 64, 23, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayWeatherMist(float Temperature, String description) {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_mist, 64, 19, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayWeatherClear(float Temperature, String description) {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_rain, 40, 23, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayWeatherSnow(float Temperature, String description) {
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_snow, 35, 23, WHITE);
  display.display();
  display.setCursor(70,0);
  display.setTextSize(2);
  display.print(Temperature,1);
  //display.print((char)223);
  display.println("C");
  display.display();
  display.setTextSize(0.5);
  display.setCursor(0,25);
  display.println(description);
  display.display();
  delay(2000);
}

void displayConditions(String location, float Humidity, float Pressure) { // Function for showing the location and conditions
  display.clearDisplay();                                                 // Clears display
  display.setCursor(35,0);                                                // Set cursor
  display.print(location);                                                // Printing location
  display.print(", ");                                                    // Display comma between city and country
  display.println(Country);                                               // Printing country
  display.setCursor(25,10);                                               // Set cursor
  
 
                                                                          // Printing Humidity
 display.print("Humidity :");
 display.print(Humidity,0);
 display.println(" %");
 
                                                                          // Printing Pressure
 display.print("Pressure :");
 display.print(Pressure,1);
 display.println(" hPa");
 delay(5000);
 display.display();
}
 
void displayGettingData() {                                               // Screen for getting data
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Getting data");
  display.display();
  delay(1000);
}
