#define R1 12
#define R2 11
#define R3 10
#define R4 9
#define C1 8
#define C2 7
#define C3 6

void setup() 
{
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(C1,INPUT_PULLUP);
  pinMode(C2,INPUT_PULLUP);
  pinMode(C3,INPUT_PULLUP);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);

  Serial.begin(115200);
}

void loop() 
{
 int key=scankey();
 if(key!=20)
 {
   Serial.println(key);
   delay(100);
 }
}

int scankey()
{
  int tempKey=20;
  digitalWrite(R1,LOW);
  if(digitalRead(C1)==0){ tempKey=1;}
  else if(digitalRead(C2)==0){ tempKey=2;}
  else if(digitalRead(C3)==0){ tempKey=3;}
  digitalWrite(R1,HIGH);
  
  digitalWrite(R2,LOW);
  if(digitalRead(C1)==0){ tempKey=4;}
  else if(digitalRead(C2)==0){ tempKey=5;}
  else if(digitalRead(C3)==0){ tempKey=6;}
  digitalWrite(R2,HIGH);

  digitalWrite(R3,LOW);
  if(digitalRead(C1)==0){ tempKey=7;}
  else if(digitalRead(C2)==0){ tempKey=8;}
  else if(digitalRead(C3)==0){ tempKey=9;}
  digitalWrite(R3,HIGH);
  
  digitalWrite(R4,LOW);
  if(digitalRead(C1)==0){ tempKey=10;}
  else if(digitalRead(C2)==0){ tempKey=11;}
  else if(digitalRead(C3)==0){ tempKey=12;}
  digitalWrite(R4,HIGH);
  delay(10);
  return tempKey;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// i2c scanner ///////////////////////////////////////////////////////////////////////////////////////////

#include "Wire.h"

void setup() 
{
  Serial.begin(115200);
  Wire.begin();
}

void loop() 
{
  byte error, address;
  int nDevices = 0;

  delay(5000);

  Serial.println("Scanning for I2C devices ...");
  for(address = 0x01; address < 0x7f; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.printf("I2C device found at address 0x%02X\n", address);
      nDevices++;
    } else if(error != 2)
    {
      Serial.printf("Error %d at address 0x%02X\n", error, address);
    }
  }
  if (nDevices == 0)
  {
    Serial.println("No I2C devices found");
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include <Wire.h>
void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
}
 void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)Serial.println("No I2C devices found\n");
  else Serial.println("done\n");
  delay(5000);           // wait 5 seconds for next scan
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  LCD I2C hello world ///////////////////////////////////////////////////////////////
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() 
{
  // Init
  lcd.init();
  lcd.backlight();

  // Print something
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(2, 1);
  lcd.print("Wokwi Online IoT");
  lcd.setCursor(5, 2);
  lcd.print("Simulator");
  lcd.setCursor(7, 3);
  lcd.print("Enjoy!");
}


void loop()
{


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// LCD keypad DHT22 ///////////////////////////////////////////////////////////////////////////////////////////
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN A1  
#define DHTTYPE DHT22

#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2

#define R1 12
#define R2 11
#define R3 10
#define R4 9
#define C1 8
#define C2 7
#define C3 6
#define Led 4

unsigned long DHTtime;
int keyindex=0;
int in1=0,in2=0,set=20;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() 
{
  pinMode(Led,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(C1,INPUT_PULLUP);
  pinMode(C2,INPUT_PULLUP);
  pinMode(C3,INPUT_PULLUP);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
   
  dht.begin(); 
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  // Print something
  lcd.setCursor(0, 0);
  lcd.print(F("Hello, world!"));
  lcd.setCursor(0, 1);
  lcd.print(F("enter set temp"));
  delay(2000);
}

void loop() 
{
 int key=scankey();
 if(key!=20)
 {
   Serial.println(key);
   if(keyindex==0)
   {
     lcd.setCursor(0, 1);
     lcd.print(F("Set T:         "));
     lcd.setCursor(6, 1);
     lcd.print(key);
     in1=key;
     keyindex++;
   }else
   {
     lcd.setCursor(7, 1);
     lcd.print(key);
     lcd.print("  ");
     in2=key;
     set=(in1*10)+in2;
     Serial.print("set:");
     Serial.println(set);

     keyindex=0;

   }
  
   delay(100);
 }
 checkDHT();
 

}

void checkDHT()
{
   if ((millis() - DHTtime) > 1000)
  {
   
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   DHTtime=millis();
     

   if (isnan(h) || isnan(t)) 
   {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
   }
   Serial.print(F("Humidity: "));
   Serial.print(h);
   Serial.print(F("%  Temperature: "));
   Serial.print(t);
   Serial.println(F("°C "));

   lcd.setCursor(0, 0);
   lcd.print(F("H:"));
   lcd.print(h,1);
   lcd.print(F("% T:"));
   lcd.print(t,1);
   lcd.print(F("C  "));
   //lcd.setCursor(5, 1);
   //lcd.print("line2");

   if(t>=set) 
   {
     digitalWrite(Led, HIGH);
   }
   else
   {
     digitalWrite(Led, LOW);
   }
  }
}

int scankey()
{
  int tempKey=20;
  digitalWrite(R1,LOW);
  if(digitalRead(C1)==0){ tempKey=1;}
  else if(digitalRead(C2)==0){ tempKey=2;}
  else if(digitalRead(C3)==0){ tempKey=3;}
  digitalWrite(R1,HIGH);
  
  digitalWrite(R2,LOW);
  if(digitalRead(C1)==0){ tempKey=4;}
  else if(digitalRead(C2)==0){ tempKey=5;}
  else if(digitalRead(C3)==0){ tempKey=6;}
  digitalWrite(R2,HIGH);

  digitalWrite(R3,LOW);
  if(digitalRead(C1)==0){ tempKey=7;}
  else if(digitalRead(C2)==0){ tempKey=8;}
  else if(digitalRead(C3)==0){ tempKey=9;}
  digitalWrite(R3,HIGH);
  
  digitalWrite(R4,LOW);
  if(digitalRead(C1)==0){ tempKey=0;}
  else if(digitalRead(C2)==0){ tempKey=20;}
  else if(digitalRead(C3)==0){ tempKey=20;}
  digitalWrite(R4,HIGH);
  delay(40);
  return tempKey;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  LCD keypad ntc  /////////////////////////////////////////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2
#define R1 12
#define R2 11
#define R3 10
#define R4 9
#define C1 8
#define C2 7
#define C3 6
#define Led 4

unsigned long Ttime;
int keyindex=0;
int in1=0,in2=0,set=20;
const float BETA = 3950;
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() 
{
  pinMode(Led,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(C1,INPUT_PULLUP);
  pinMode(C2,INPUT_PULLUP);
  pinMode(C3,INPUT_PULLUP);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH); 
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  // Print something
  lcd.setCursor(0, 0);
  lcd.print(F("Hello, world!"));
  lcd.setCursor(0, 1);
  lcd.print(F("enter set temp"));
  delay(2000);
}

void loop() 
{
 int key=scankey();
 if(key!=200)
 {
     Serial.println(key);
   
     lcd.setCursor(0, 1);
     lcd.print(F("Set T:            "));
     lcd.setCursor(6, 1);
     lcd.print(key);
     set=key;
    delay(100);
 }
 checkT();
}

void checkT()
{
   if ((millis() - Ttime) > 1000)
  {
  Ttime=millis();
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");

   lcd.setCursor(0, 0);
   lcd.print(F("Temperature:"));
   lcd.print(celsius,1);
   lcd.print((char)223);
   lcd.print(F("C  "));

   //////////////////////////////////////////////////////////////
  // Write your code here //

  


    
   /////////////////////////////////////////////////////////////
  }
}

int scankey()
{
  int tempKey=200;
  digitalWrite(R1,LOW);
  if(digitalRead(C1)==0){ tempKey=0;}
  else if(digitalRead(C2)==0){ tempKey=10;}
  else if(digitalRead(C3)==0){ tempKey=20;}
  digitalWrite(R1,HIGH);
  
  digitalWrite(R2,LOW);
  if(digitalRead(C1)==0){ tempKey=30;}
  else if(digitalRead(C2)==0){ tempKey=40;}
  else if(digitalRead(C3)==0){ tempKey=50;}
  digitalWrite(R2,HIGH);

  digitalWrite(R3,LOW);
  if(digitalRead(C1)==0){ tempKey=60;}
  else if(digitalRead(C2)==0){ tempKey=70;}
  else if(digitalRead(C3)==0){ tempKey=80;}
  digitalWrite(R3,HIGH);
  
  digitalWrite(R4,LOW);
  if(digitalRead(C1)==0){ tempKey=90;}
  else if(digitalRead(C2)==0){ tempKey=100;}
  else if(digitalRead(C3)==0){ tempKey=110;}
  digitalWrite(R4,HIGH);
  delay(40);
  return tempKey;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

