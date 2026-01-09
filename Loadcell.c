///////////////////////// loadcell eVgxy4 /////////////////////////////////////////////////

#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}


/////////////////////////////////////////////////////////////////////////////////////////////////
// Calibrating the load cell
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() 
{

  if (scale.is_ready()) 
  {
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(5000);
    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(5000);
    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
  } 
  else 
  {
    Serial.println("HX711 not found.");
  }
  delay(1000);
}

//calibration factor will be the (reading)/(known weight)


//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////



/**
 * Complete project details at https://RandomNerdTutorials.com/arduino-load-cell-hx711/
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/

#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;

HX711 scale;

void setup() 
{
  Serial.begin(115200);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight (not set yet)

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided
            // by the SCALE parameter (not set yet)
            
  scale.set_scale(23.435);
  //scale.set_scale(-471.497);      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                 // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight, set with tare()

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided
            // by the SCALE parameter set with set_scale

  Serial.println("Readings:");
}

void loop() 
{
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);

  delay(5000);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////





#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin();
	lcd.backlight();
	lcd.print("Hello (^__^)");
  	lcd.setCursor(0, 1);
  	lcd.print("Sawaddee");
}

void loop()
{
	// Do nothing here...
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////




#include <Arduino.h>
#include "HX711.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;

HX711 scale;

void setup() 
{
  Serial.begin(115200);
  lcd.begin();  //lcd.init();
	lcd.print("Weight Scale");
  lcd.setCursor(0, 1);
  lcd.print("Initializing..");
  
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
            
  scale.set_scale(239.407);
  
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");
  lcd.setCursor(0, 0);
  lcd.print("Weight:        g");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() 
{
  float avr=0;
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  avr=scale.get_units(10);
  Serial.println(avr, 5);
  lcd.setCursor(8, 0);
  lcd.print("       ");
  lcd.setCursor(8, 0);
  lcd.print(avr,2);
  delay(2000);
}


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//// no block tare 
#include <Arduino.h>
#include "myBounce.h"
#include "HX711.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;
unsigned long delayTime1;

#define sw1 34
#define sw4 33

myBounce SW1(sw1);
myBounce SW4(sw4);

HX711 scale;

void setup() 
{
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  lcd.print("Weight Scale");
  lcd.setCursor(0, 1);
  lcd.print("Initializing..");
  Serial.println("Initializing the scale");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(444.2995); 
  // this value is obtained by calibrating the scale with known weights; 
  scale.tare();               // reset the scale to 0
  Serial.println("After setting up the scale:");
  lcd.setCursor(0, 0);
  lcd.print("Weight:        g");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() 
{
  if(SW1.update()==1)
  { 
    scale.tare();  
    lcd.setCursor(0, 1);
    lcd.print("Tare           ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  if ((millis() - delayTime1) > 1000)
  {
    float avr=0;
    Serial.print("one reading:\t");
    Serial.print(scale.get_units(), 1);
    Serial.print("\t| average:\t");
    avr=scale.get_units(10);
    Serial.println(avr, 5);
    lcd.setCursor(8, 0);
    lcd.print("       ");
    lcd.setCursor(8, 0);
    lcd.print(avr,2);
    delayTime1=millis();
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////   mybounce.h  /////////////////////////////////////////////////////////////
/*
 * myBounce.h
 */
#ifndef MYBOUNCE_H
#define MYBOUNCE_H
#include <Arduino.h>

    
class myBounce
{
  public:
   myBounce(byte pin);
   bool update();
  private:
   byte _pin;
   bool _sw_state;
   bool _last_sw_state;
   bool _change;
   unsigned long _time; 
};

#endif


///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// mybounce.cpp /////////////////////////////////////////////////////////
 /*
 * myBounce.cpp
 */

#include "myBounce.h"

myBounce::myBounce(byte pin)
{
   pinMode(pin, INPUT_PULLUP);
  _pin = pin;
}

bool myBounce::update()
{
  bool ret=0;
  _sw_state=digitalRead(_pin);
  if((_sw_state==0)&&(_last_sw_state==1))
  {
    _time=millis();
    _change=1;
  }
  _last_sw_state=_sw_state;

  if(((millis()-_time)>50)&&(_change==1))
  {
    _sw_state=digitalRead(_pin);
    if(_sw_state==0)
    {
      ret=1;
    }else
    {
      ret=0;
    }
    _change=0;
  }

 return ret;


}

/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

//// no block tare   cal -> EEPROM
#include <EEPROM.h>
#include "myBounce.h"
#include "HX711.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;
unsigned long delayTime1;
float refWeight=638.9;
float calFactor=44.2995;

#define sw1 34
#define sw3 32
myBounce SW1(sw1);
myBounce SW3(sw3);
HX711 scale;

void setup() 
{
  Serial.begin(115200);
  EEPROM.begin(8);
  calFactor= EEPROM.readFloat(0);
  lcd.begin();
  lcd.backlight();
  lcd.print("Weight Scale");
  lcd.setCursor(0, 1);
  lcd.print("Initializing..");
  Serial.println("Initializing the scale");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calFactor); 
  // this value is obtained by calibrating the scale with known weights; 
  scale.tare();               // reset the scale to 0
  Serial.println("After setting up the scale:");
  lcd.setCursor(0, 0);
  lcd.print("Weight:        g");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void loop() 
{
  if(SW1.update()==1)
  { 
    scale.tare();  
    lcd.setCursor(0, 1);
    lcd.print("Tare           ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  if(SW3.update()==1)
  { 
    lcd.setCursor(0, 1);
    lcd.print("pls remove weight");
    delay(5000);
    scale.tare();  
    lcd.setCursor(0, 1);
    lcd.print("place ref weight ");
    delay(5000);
    calFactor=scale.get_value(5)/refWeight;
    scale.set_scale(calFactor);
    EEPROM.writeFloat(0, calFactor);
    EEPROM.commit();
    lcd.setCursor(0, 1);
    lcd.print("Cal complete      ");
    delay(5000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  if ((millis() - delayTime1) > 1000)
  {
    float avr=0;
    Serial.print("one reading:\t");
    Serial.print(scale.get_units(), 1);
    Serial.print("\t| average:\t");
    avr=scale.get_units(10);
    Serial.println(avr, 5);
    lcd.setCursor(8, 0);
    lcd.print("       ");
    lcd.setCursor(8, 0);
    lcd.print(avr,2);
    delayTime1=millis();
  }
}

/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////




/**
OLED Weigth scale
**/

#include "HX711.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


HX711 scale;

void setup() 
{
  Serial.begin(115200);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

/////////////////////OLED init/////////////////////////////////
  Wire.begin();
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
  //////////////////////////////////////////////////////

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1); 
  
            
  scale.set_scale(23.435);
  
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);       
 

  Serial.println("Readings:");
}

void loop() 
{
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);

  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Weight="));
  display.setTextSize(3); 
  display.println(scale.get_units(10), 2);
  display.display();

  delay(2000);
}



//////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 33;
const int LOADCELL_SCK_PIN = 27;

HX711 scale;

void setup() 
{
  Serial.begin(115200);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1); 
  
            
  scale.set_scale(23.435);
  
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());                

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   

  
  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);       
 

  Serial.println("Readings:");
}

void loop() 
{
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);

  delay(5000);
}
