/*
esp32_ws0
*/
#define L1 27
#define L2 13
#define R1 19
#define R2 18

// the setup function runs once 
void setup() 
{
  // initialize digital pin as an output.
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(L1, HIGH); 
  delay(500); 
  digitalWrite(L1, LOW);
  delay(500);  

  digitalWrite(L2, HIGH); 
  delay(500); 
  digitalWrite(L2, LOW);
  delay(500);  

  digitalWrite(R2, HIGH); 
  delay(500); 
  digitalWrite(R2, LOW);
  delay(500);  

  digitalWrite(R1, HIGH); 
  delay(500); 
  digitalWrite(R1, LOW);
  delay(500);  
}

///////////////////////////////////////////////////////////////////////
//////////////////////////////  FBLRS /////////////////////////////////
/*
esp32_ws0_FBLRS
*/
#define L1 27
#define L2 13
#define R1 19
#define R2 18

// the setup function runs once 
void setup() 
{
  // initialize digital pin as an output.
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{

  digitalWrite(L1, HIGH);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, HIGH);  
  digitalWrite(R2, LOW);  //FW
  delay(1000);     
  
  digitalWrite(L1, LOW);  
  digitalWrite(L2, HIGH);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, HIGH);  //BW
  delay(1000);  

  digitalWrite(L1, HIGH);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, HIGH);  //L
  delay(1000);  
  
  digitalWrite(L1, LOW);  
  digitalWrite(L2, HIGH);  
  digitalWrite(R1, HIGH);  
  digitalWrite(R2, LOW);  //R
  delay(1000);  
  
  digitalWrite(L1, LOW);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, LOW);  //Stop
  delay(1000);  
}
////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18

void setup() 
{
  RemoteXY_Init (); 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() 
{ 
  RemoteXY_Handler ();
  if(RemoteXY.button_F==1) forward();
  else if(RemoteXY.button_B==1) backward();
  else if(RemoteXY.button_L==1) left();
  else if(RemoteXY.button_R==1) right();
  else Stop();
}

void forward()
{
  digitalWrite(L1, HIGH);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, HIGH);  
  digitalWrite(R2, LOW);  //FW
}

void backward()
{
  digitalWrite(L1, LOW);  
  digitalWrite(L2, HIGH);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, HIGH);  //BW
}

void right()
{
  digitalWrite(L1, HIGH);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, HIGH);  //R
}

void left()
{
  digitalWrite(L1, LOW);  
  digitalWrite(L2, HIGH);  
  digitalWrite(R1, HIGH);  
  digitalWrite(R2, LOW);  //L
}

void Stop()
{
  digitalWrite(L1, LOW);  
  digitalWrite(L2, LOW);  
  digitalWrite(R1, LOW);  
  digitalWrite(R2, LOW);  //Stop
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/*
 esp32 analogWrite
*/

int Led1 = 2;

void setup() 
{
  pinMode(Led1, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  for (int brightness = 0; brightness < 255; brightness++) 
  {
    analogWrite(Led1, brightness);
    Serial.println(brightness);
    delay(10);
  }
  
  for (int brightness = 255; brightness >= 0; brightness--) 
  {
    analogWrite(L1, brightness);
    Serial.println(brightness);
    delay(10);
  }
  
  delay(100);
}

/////////////////////////////////////////////////////////////////////////////
////////////////////////////remotexy joy analogwrite ///////////////////////////////////////////

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18
int Offset =90; 

void setup() 
{
  RemoteXY_Init (); 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  int X2 = RemoteXY.joystick_01_x;
  int Y2 = RemoteXY.joystick_01_y;
  Serial.print(X2); 
  Serial.print(" ");
  Serial.println(Y2);


  if(Y2<=-20)  // joy backward
  {
    int Backward=abs(Y2)*2; 

     if(X2>=0)  //joy backward+Right
     {
      analogWrite(L1, 0);   
      analogWrite(L2, constrain(Backward+Offset+(abs(X2)),0,255));    
      analogWrite(R1, 0); 
      analogWrite(R2, constrain(Backward+Offset-(abs(X2)),0,255)); 
      Serial.println("Backward+Right"); 
     }
     else  //joy backward+left
     {
      analogWrite(L1, 0);  
      analogWrite(L2, constrain(Backward+Offset-(abs(X2)),0,255));   
      analogWrite(R1, 0);
      analogWrite(R2, constrain(Backward+Offset+(abs(X2)),0,255)); 
      Serial.println("Backward+Left"); 
     }
  }else if(Y2>=20) //joy forward
  {
    int Forward=abs(Y2)*2; 
    if(X2>=0)  //joy forward+Right
     {
    
    analogWrite(L1, constrain(Forward+Offset+(abs(X2)),0,255));   
    analogWrite(L2, 0);  
    analogWrite(R1, constrain(Forward+Offset-(abs(X2)),0,255));   
    analogWrite(R2, 0); 
    Serial.println("Forward+Right"); 
     }else   //joy forward+Left
     {
      analogWrite(L1, constrain(Forward+Offset-(abs(X2)),0,255));   
      analogWrite(L2, 0); 
      analogWrite(R1, constrain(Forward+Offset+(abs(X2)),0,255));   
      analogWrite(R2, 0);  
      Serial.println("Forward+Left"); 
     } 
    
  }else if(Y2==0&&X2==0) //center = stop
  {
    analogWrite(L1, 0);   
    analogWrite(L2, 0);  
    analogWrite(R1, 0);   
    analogWrite(R2, 0);   
    //Serial.println("Stop"); 
  }else  //between +-20  = rotate mode
  {
    int RotateR=X2; 
    if(RotateR<=0) //rotate right
     {
      int RotateL=abs(X2); 
      analogWrite(L1,  0);  
      analogWrite(L2, constrain(RotateL+Offset,0,255));   
      analogWrite(R1, constrain(RotateL+Offset,0,255)); 
      analogWrite(R2,  0);  
      Serial.println("Rotate L");
     }
     else //rotate left
     {
      int RotateR=abs(X2); 
      analogWrite(L1, constrain(RotateR+Offset,0,255)); 
      analogWrite(L2, 0);   
      analogWrite(R1, 0);  
      analogWrite(R2, constrain(RotateR+Offset,0,255)); 
      Serial.println("Rotate R");
     }
  } 
  RemoteXY_delay(10); 
}

//////////////////////// end /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////
///////////////// esp32 analogWrite VR ////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18
#define Ain 36
int VR;
int brightness;

void setup() 
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(Ain, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  VR=analogRead(Ain);
  brightness=map(VR,0,4095,0,255);
  analogWrite(L2, brightness);
  Serial.println(brightness);
  delay(100);
}


////////////////////////////////////////////////////////////////////////////
/////////////////////  esp32 ledc VR  //////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18
#define Ain 36
int VR;
int brightness;

void setup() 
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(Ain, INPUT);
  Serial.begin(9600);
  ledcSetup(0,500,12);  //channel 0-15,freq,resolution 
  ledcAttachPin(R2,0); //pin,chennel
  ledcAttachPin(R1,0); //pin,chennel
}

void loop() 
{
  VR=analogRead(Ain);
  ledcWrite(0,VR);
  Serial.println(VR);
  delay(100);
}

///////////////////////////////////////////////////////////////////////
////////////////////*  servo ledc VR *///////////////////////////////

#define servoPin 15
#define Ain 36
int VR;
int pos;

void setup() 
{
  pinMode(servoPin, OUTPUT);
  pinMode(Ain, INPUT);
  Serial.begin(9600);
  ledcSetup(0,50,12);  //channel 0-15,freq,resolution 
  ledcAttachPin(servoPin,0); //pin,chennel
}  

void loop() 
{
  VR=analogRead(Ain);
  pos=map(VR,0,4095,0,180);
  ledcWrite(0,map(pos,0,180,504,107));
  Serial.println(pos);
  delay(50);
}

/////////////////////////////////////////////////////////////////////////
/////////////// code for remoteXY ///////////////////////////

#define analogInPin 36
unsigned long lastTime=0; 
void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_BUTTON_01, (RemoteXY.button_01==0)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_01, (RemoteXY.pushSwitch_01==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_01, (RemoteXY.switch_01==0)?LOW:HIGH);
  

  if(millis()>lastTime+1000)
  {
   float sensorValue = analogRead(analogInPin);
   int percent= sensorValue *(100/4096.0);
   float volt= sensorValue *(3.3/4096.0);
   RemoteXY.linearbar_01=percent;
   //snprintf (RemoteXY.text_01, 5, "%f.2", volt);
   dtostrf(volt, 1, 2, RemoteXY.value_01);
   lastTime=millis();
  } 
}

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// slider servo ////////////////////////////////////////////////


/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_BUTTON_01 19
#define PIN_PUSHSWITCH_01 18
#define servoPin 15
#define Ain 36
unsigned long lastTime=0; 

void setup() 
{
  RemoteXY_Init (); 
  pinMode (PIN_BUTTON_01, OUTPUT);
  pinMode (PIN_PUSHSWITCH_01, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(Ain, INPUT);
  ledcSetup(0,50,12);  //channel 0-15,freq,resolution 
  ledcAttachPin(servoPin,0); //pin,chennel
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_BUTTON_01, (RemoteXY.button_01==0)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_01, (RemoteXY.pushSwitch_01==0)?LOW:HIGH);
  
 if(millis()>lastTime+50)
  {
   float sensorValue = analogRead(Ain);
   int percent= sensorValue *(100/4096.0);
   float volt= sensorValue *(3.3/4096.0);
   RemoteXY.linearbar_01=percent;
   //snprintf (RemoteXY.text_01, 5, "%f.2", volt);
   dtostrf(volt, 1, 2, RemoteXY.value_01);

   int pos=map(RemoteXY.slider_01,0,100,0,180);
   ledcWrite(0,map(pos,0,180,504,107));
   lastTime=millis();
  } 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////test FBLRS smd ///////////////////////////////////////////////////
/*
Esp32 rover smd
*/
#define L1 27
#define L2 13
#define R1 19
#define R2 18

void setup() 
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  forward(); 
  delay(1000);         
  stop();
  delay(100);  
  backward();
  delay(1000); 
  stop();
  delay(100); 
  left(); 
  delay(1000);   
  stop();
  delay(100); 
  right();
  delay(1000);   
  stop();
  delay(100);   
}
void forward()
{
  Serial.println("forward");
  digitalWrite(L1, HIGH);                   
  digitalWrite(L2, LOW);   //forward
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);  
}

void backward()
{
  Serial.println("backward");
  digitalWrite(L1, LOW);                   
  digitalWrite(L2, HIGH);   //backward
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH); 
}


void left()
{
  Serial.println("left");
  digitalWrite(L1, HIGH);      //left             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH);   
}

void right()
{
  Serial.println("Right");
  digitalWrite(L1, LOW);       //right            
  digitalWrite(L2, HIGH);   
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);   
}

void stop()
{
  Serial.println("Stop");
  digitalWrite(L1, LOW);      //stop             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, LOW); 
  delay(40);   
}

//////////////////////////////////////////////////////////////////////////////
//////////////////// FBLRS remoteXY /////////////////////////////////////////

 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18

void setup() 
{
  RemoteXY_Init (); 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() 
{ 
  RemoteXY_Handler ();
  if(RemoteXY.button_01==1) forward();
  else if (RemoteXY.button_04==1) backward();
  else if (RemoteXY.button_02==1) left();
  else if (RemoteXY.button_03==1) right();
  else stop();
}


void forward()
{
  digitalWrite(L1, HIGH);                   
  digitalWrite(L2, LOW);   //forward
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);  
}

void backward()
{
  digitalWrite(L1, LOW);                   
  digitalWrite(L2, HIGH);   //backward
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH); 
}


void left()
{
  digitalWrite(L1, HIGH);  //left             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH);   
}

void right()
{
  digitalWrite(L1, LOW);    //right            
  digitalWrite(L2, HIGH);   
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);   
}


void stop()
{
  digitalWrite(L1, LOW);      //stop             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, LOW);  
}


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////FBLRS remoteXY///////////////////////////////////////

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18

void setup() 
{
  RemoteXY_Init (); 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
}

void loop() 
{ 
  RemoteXY_Handler ();
  if(RemoteXY.button_01==1) forward();
  else if (RemoteXY.button_04==1) backward();
  else if (RemoteXY.button_02==1) left();
  else if (RemoteXY.button_03==1) right();
  else stop();
}


void forward()
{
  digitalWrite(L1, HIGH);                   
  digitalWrite(L2, LOW);   //forward
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);  
}

void backward()
{
  digitalWrite(L1, LOW);                   
  digitalWrite(L2, HIGH);   //backward
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH); 
}


void left()
{
  digitalWrite(L1, HIGH);  //left             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, HIGH);   
}

void right()
{
  digitalWrite(L1, LOW);    //right            
  digitalWrite(L2, HIGH);   
  digitalWrite(R1, HIGH);                   
  digitalWrite(R2, LOW);   
}


void stop()
{
  digitalWrite(L1, LOW);      //stop             
  digitalWrite(L2, LOW);   
  digitalWrite(R1, LOW);                   
  digitalWrite(R2, LOW);  
}

///////////////////////////////////////////////////////////////////////
/////////////////// joy ledc remotexy ///////////////////////////////////

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define L1 27
#define L2 13
#define R1 19
#define R2 18
int Offset =90; 

void setup() 
{
  RemoteXY_Init (); 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  
  ledcSetup(0, 100, 8);
  ledcAttachPin(L1, 0);

  ledcSetup(1, 100, 8);
  ledcAttachPin(L2, 1);

  ledcSetup(2, 100, 8);
  ledcAttachPin(R1, 2);

  ledcSetup(3, 100, 8);
  ledcAttachPin(R2, 3);
  Serial.begin(9600);

}

void loop() 
{ 
  RemoteXY_Handler ();
  int X2 = RemoteXY.joystick_01_x;
  int Y2 = RemoteXY.joystick_01_y;
  if(Y2<=-20)  // joy forward
  {
    int Backward=abs(Y2)*2; 

     if(X2>=0)  //joy forward+Right
     {
      ledcWrite(0,  constrain(Backward+Offset+(abs(X2)),0,255));   
      ledcWrite(1, 0);   
      ledcWrite(2, constrain(Backward+Offset-(abs(X2)),0,255)); 
      ledcWrite(3, 0); 
      Serial.println("Backward+Right"); 
     }
     else  //joy forward+left
     {
      ledcWrite(0,   constrain(Backward+Offset-(abs(X2)),0,255));  
      ledcWrite(1, 0);   
      ledcWrite(2,  constrain(Backward+Offset+(abs(X2)),0,255));
      ledcWrite(3, 0); 
      Serial.println("Backward+Left"); 
     }
  }else if(Y2>=20) //joy backward
  {
    int Forward=abs(Y2)*2; 
    if(X2>=0)  //joy backward+Right
     {
    
    ledcWrite(0, 0);   
    ledcWrite(1, constrain(Forward+Offset+(abs(X2)),0,255));  
    ledcWrite(2, 0);   
    ledcWrite(3, constrain(Forward+Offset-(abs(X2)),0,255)); 
    Serial.println("Forward+Right"); 
     }else   //joy backward+Left
     {
      ledcWrite(0, 0);   
      ledcWrite(1, constrain(Forward+Offset-(abs(X2)),0,255)); 
      ledcWrite(2, 0);   
      ledcWrite(3, constrain(Forward+Offset+(abs(X2)),0,255));  
      Serial.println("Forward+Left"); 
     } 
    
  }else if(Y2==0&&X2==0) //center = stop
  {
    ledcWrite(0, 0);   
    ledcWrite(1, 0);  
    ledcWrite(2, 0);   
    ledcWrite(3, 0);   
    //Serial.println("Stop"); 
  }else  //between +-20  = rotate mode
  {
    int RotateR=X2; 
    if(RotateR<=0) //rotate right
     {
      int RotateL=abs(X2); 
      ledcWrite(0,  constrain(RotateL+Offset,0,255));  
      ledcWrite(1, 0);   
      ledcWrite(2, 0); 
      ledcWrite(3,  constrain(RotateL+Offset,0,255));  
      Serial.println("Rotate L");
     }
     else //rotate left
     {
      int RotateR=abs(X2); 
      ledcWrite(0, 0); 
      ledcWrite(1, constrain(RotateR+Offset,0,255));   
      ledcWrite(2, constrain(RotateR+Offset,0,255));  
      ledcWrite(3, 0); 
      Serial.println("Rotate R");
     }
  }  
}

///////////////////////////////////////////////////////////////////////////////////////
