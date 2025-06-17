
///////////////////////////////////////////////////////////////////////////
/*
  Blink
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

#define led1 13
#define led1 12

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() 
{
  digitalWrite(led1, HIGH);   
  delay(1000);                       
  digitalWrite(led1, LOW);    
  delay(1000);                       

  digitalWrite(led2, HIGH);   
  delay(1000);                       
  digitalWrite(led2, LOW);   
  delay(1000);                      
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
const int ledPin =  12;      

int buttonPin = 2;        

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
 
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) 
  {
    // turn LED on
    digitalWrite(ledPin, HIGH);
  } else 
  {
     //turn LED off
    digitalWrite(ledPin, LOW);
  }
}

/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// code 2 digital input pullup 
const int buttonPin = 2;     
const int ledPin =  13;      
const int led2 =  12;  
int buttonState = 0;        

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() 
{
 
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) 
  {
     //turn LED on
    digitalWrite(ledPin, HIGH);
    digitalWrite(led2, HIGH);
  } else 
  {
     //turn LED off
    digitalWrite(ledPin, LOW);
    digitalWrite(led2, LOW);
  }
}

///////////////////////////////////////////////////////////////////////////////
// code 3 sw toggle 
int led1 = 13;
int led2 = 12;
int sw1 = 2;
int sw_state=0;
int state=0;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
}

void loop() 
{
  sw_state=digitalRead(sw1);
  if(sw_state==0)state=!state; 
  
  
  if(state==0)
  { 
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,LOW);
  } 
  if(state==1)
  {
    digitalWrite(led1,LOW); 
    digitalWrite(led2,HIGH);
    
  }
  delay(200);
}


// code 3.1 sw easy debounce toggle 

int led1 = 13;
int led2 = 12;
int sw1 = 2;
int sw_state=0;
int state=0;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
}

void loop() 
{
  sw_state=digitalRead(sw1);
  if(sw_state==0)
  {
    delay(50);
    sw_state=digitalRead(sw1);
    if(sw_state==0)
    {
     state=!state; 
     delay(50);
    }
    
  }
  
  if(state==0)
  { 
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,LOW);
  } 
  if(state==1)
  {
    digitalWrite(led1,LOW); 
    digitalWrite(led2,HIGH);
  }
}


////////////////////////////////////////////////////////////////////////////////////////////
// code 4 sw debounce


int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1;
int state=0;
unsigned long time1;
int debounceDelay=40;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
}

void loop() 
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    buttonstate=sw_state;
    time1=millis();
        
  }

  
  if(buttonstate==0)
  {
    state=!state; 
    buttonstate=1;
    if(state==0){digitalWrite(led1,HIGH); digitalWrite(led2,LOW);} 
    if(state==1){digitalWrite(led1,LOW); digitalWrite(led2,HIGH);}
    while(!digitalRead(sw1));
    delay(10);
  }
  
  
  last_sw_state=sw_state;
}


///////////////////////////////////////////////////////////////////////////////////////////
// code 5 sw debounce



int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1;
int state=0;
unsigned long time1;
int debounceDelay=40;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
}

void loop() 
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    buttonstate=sw_state;
    time1=millis();
        
  }

  
  if(buttonstate==0)
  {
    state=!state; 
    buttonstate=1;
    if(state==0){digitalWrite(led1,HIGH); digitalWrite(led2,LOW);} 
    if(state==1){digitalWrite(led1,LOW); digitalWrite(led2,HIGH);}
    while(!digitalRead(sw1));
    delay(10);
  }
  
  
  last_sw_state=sw_state;
}

///////////////////////////////////////////////////////////////////////////////////////////
// code 5 sw debounce

int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1,change=0;
int state=0;
unsigned long time1;
int debounceDelay=40;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
}

void loop() 
{
  checkSW();

  if(state==0){ digitalWrite(led2,LOW);} 
  else{ digitalWrite(led2,HIGH);}
  
  
}



void checkSW()
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    if(buttonstate!=sw_state)
    {
    buttonstate=sw_state;
    change=1;
    }   
  }

  if((buttonstate==0)&&(change==1))
  {
    state=!state; 
    change=0;
  }
  if((buttonstate==1)&&(change==1))
  {
    change=0;
  }
  last_sw_state=sw_state;
}

//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// code 7 sw debounce blink noblock 

int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1,change=0;
bool state=0;
unsigned long time1;
int debounceDelay=40;
bool LED1State=0;
unsigned long delayTime1;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
  
}

void loop() 
{
  checkSW();
  if(state==0){ digitalWrite(led2,LOW);} 
  else{ digitalWrite(led2,HIGH);}
  
  if ((millis() - delayTime1) > 1000)
  {
   LED1State=!LED1State;
   digitalWrite(led1, LED1State);
   delayTime1=millis();
  }

}                                                                     


void checkSW()
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    if(buttonstate!=sw_state)
    {
    buttonstate=sw_state;
    change=1;
    }   
  }

  if((buttonstate==0)&&(change==1))
  {
    state=!state; 
    change=0;
  }
  if((buttonstate==1)&&(change==1))
  {
    change=0;
  }
  last_sw_state=sw_state
/////////////////////////////////////////////Code 8 


int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1,change=0;
bool state=0;
unsigned long time1;
int debounceDelay=40;
bool LED1State=0;
unsigned long delayTime1;
unsigned long delayA0;
void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);;;;;  
  Serial.begin(115200);
}

void loop() 
{
  checkSW();
  if(state==0){ digitalWrite(led2,LOW);} 
  else{ digitalWrite(led2,HIGH);}
  
  if ((millis() - delayTime1) > 1000)
  {
   LED1State=!LED1State;
   digitalWrite(led1, LED1State);
   delayTime1=millis();
  }

  if ((millis() - delayA0) > 500)
  {
   int sensorValue = analogRead(A0);
   float volt = sensorValue*5.0/1023;
   Serial.print("ADC: ");
   Serial.print(sensorValue);
   Serial.print(" volt: ");
   Serial.println(volt);
   delayA0=millis();
  }
}                                                                     


void checkSW()
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    if(buttonstate!=sw_state)
    {
    buttonstate=sw_state;
    change=1;
    }   
  }

  if((buttonstate==0)&&(change==1))
  {
    state=!state; 
    change=0;
  }
  if((buttonstate==1)&&(change==1))
  {
    change=0;
  }
  last_sw_state=sw_state;
}

/////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////
      
//code 9 sw debounce blink noblock analogRead-analogWrite

int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1,change=0;
bool state=0;
unsigned long time1;
int debounceDelay=40;
bool LED1State=0;
unsigned long delayTime1;
unsigned long delayA0;

void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(sw1,INPUT_PULLUP);  
  Serial.begin(115200);
}

void loop() 
{
  checkSW();
  if(state==0){ digitalWrite(led2,LOW);} 
  else{ digitalWrite(led2,HIGH);}
  
  if ((millis() - delayTime1) > 1000)
  {
   LED1State=!LED1State;
   digitalWrite(led1, LED1State);
   delayTime1=millis();
  }

  if ((millis() - delayA0) > 500)
  {
  
   int sensorValue = analogRead(A0);
   int PWM = map(sensorValue,0,1023,0,255);
   analogWrite(6,PWM);
   Serial.print("sensorValue: " );
   Serial.print(sensorValue);
   Serial.print( "  PWM: ");
   Serial.print(PWM);
   float volt = sensorValue*5.0/1024;
   Serial.print("  volt:");
   Serial.println(volt);
   delayA0=millis();
  }
}                                                                     


void checkSW()
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    if(buttonstate!=sw_state)
    {
    buttonstate=sw_state;
    change=1;
    }   
  }

  if((buttonstate==0)&&(change==1))
  {
    state=!state; 
    change=0;
  }
  if((buttonstate==1)&&(change==1))
  {
    change=0;
  }
  last_sw_state=sw_state;
}

  //code 9 sw debounce blink noblock analogRead-analogWrite

/////////////////////////////////////////////////
