//////////////////////// night rider////////////////////////////////////
YLXeK3
//////////////////////// night rider////////////////////////////////////

int led7 = 13;
int led6 = 12;
int led5 = 11;
int led4 = 10;
int led3 = 9;
int led2 = 8;
int led1 = 7;
int led0 = 6;
int sw1 =3;
int sw2 =2;


void setup() 
{                
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);  pinMode(led6, OUTPUT); 
  pinMode(led7, OUTPUT);     
  pinMode(sw1, INPUT_PULLUP);   
  pinMode(sw2, INPUT_PULLUP);   
  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  
}
void loop() 
{
  digitalWrite(led0,HIGH); delay(200); digitalWrite(led0,LOW);
  digitalWrite(led1,HIGH); delay(200); digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH); delay(200); digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH); delay(200); digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH); delay(200); digitalWrite(led4,LOW);
  digitalWrite(led5,HIGH); delay(200); digitalWrite(led5,LOW);
  digitalWrite(led6,HIGH); delay(200); digitalWrite(led6,LOW);
  digitalWrite(led7,HIGH); delay(200); digitalWrite(led7,LOW);
  
  digitalWrite(led6,HIGH); delay(200); digitalWrite(led6,LOW);
  digitalWrite(led5,HIGH); delay(200); digitalWrite(led5,LOW);
  digitalWrite(led4,HIGH); delay(200); digitalWrite(led4,LOW);
  digitalWrite(led3,HIGH); delay(200); digitalWrite(led3,LOW);
  digitalWrite(led2,HIGH); delay(200); digitalWrite(led2,LOW);
  digitalWrite(led1,HIGH); delay(200); digitalWrite(led1,LOW);
}

///////////////////////////////////////////////////////////////
//////////////////////// night rider II///////////////////////

int led[]={6,7,8,9,10,11,12,13};

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
}

void loop() 
{
  for(int i=0; i<=7; i++)
  {
    digitalWrite(led[i],HIGH); delay(200); digitalWrite(led[i],LOW);
  } 

  for(int i=6; i>=1; i--)
  {
    digitalWrite(led[i],HIGH); delay(200); digitalWrite(led[i],LOW);
  } 
}


////////////////////////////////////////////////////////////////////
////////////////////// night rider III noblock////////////////////

int led[]={6,7,8,9,10,11,12,13};
bool upDown=1;
int i=0;
int delayTime=200;
long lastTime=0;

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
  Serial.begin(115200);
}

void loop() 
{ 
  if((upDown==1)&&(millis()-lastTime>delayTime))
  {
      digitalWrite(led[i],LOW);
      i++;
      digitalWrite(led[i],HIGH);
      if(i>=8) 
      { 
        i=6;
        upDown=0;
        digitalWrite(led[7],LOW);
        digitalWrite(led[6],HIGH);
      }  
    lastTime=millis();
    Serial.println(i);
  }
    
 if((upDown==0)&&(millis()-lastTime>delayTime))
  {
      digitalWrite(led[i],LOW);
      i--;
      digitalWrite(led[i],HIGH);
      if(i<=0) 
      { 
        i=0;
        upDown=1;
      }  
    lastTime=millis();
    Serial.println(i);
  }
}

//////////////////////////////////////////////////////////////////////
////////////////////// binary count updown I ///////////////////////

int led[]={6,7,8,9,10,11,12,13};

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
}

void loop() 
{
  for(int i=0; i<=7; i++)
  {
    digitalWrite(led[i],HIGH); delay(200); digitalWrite(led[i],LOW);
  } 

  for(int i=6; i>1; i--)
  {
    digitalWrite(led[i],HIGH); delay(200); digitalWrite(led[i],LOW);
  } 
///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
  
  
int led[]={6,7,8,9,10,11,12,13};
bool upDown=1;
int i=0;
int delayTime=200;
long lastTime=0;
int sw1=2;
int sw2=3;

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
  pinMode(sw1, INPUT_PULLUP);   
  pinMode(sw2, INPUT_PULLUP);  
  Serial.begin(115200);
  i=0;
}


void loop() 
{
  if((digitalRead(sw1)==0)&&(i<254))
  {
    i++;
    out8bit(i);
  }
  
  if((digitalRead(sw2)==0)&&(i>0))
  {
    i--;
    out8bit(i);
  }
  Serial.print("i=");
  Serial.print(i);
  Serial.print(" ,");
  Serial.println(i,BIN);
  delay(100);
}

void out8bit(unsigned char data)
{
  digitalWrite(led[0],data&B00000001);
  digitalWrite(led[1],data&B00000010);
  digitalWrite(led[2],data&B00000100);
  digitalWrite(led[3],data&B00001000);
  digitalWrite(led[4],data&B00010000);
  digitalWrite(led[5],data&B00100000);
  digitalWrite(led[6],data&B01000000);
  digitalWrite(led[7],data&B10000000);
}

  
  
  
  
  
  
  
  
  
  
/////////////// binary count updown II //////////////////


    {
      "type": "wokwi-7segment",
      "id": "sevseg1",
      "top": -205.38,
      "left": -75.68,
      "attrs": { "digits": "4" }
    }



///////////////////////////////////////////////////////////////////////////////////
  // binary count updown 7seg I //

int led[]={6,7,8,9,10,11,12,13};
bool upDown=1;
int i=0;
int delayTime=200;
long lastTime=0;
int sw1=2;
int sw2=3;

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
  pinMode(sw1, INPUT_PULLUP);   
  pinMode(sw2, INPUT_PULLUP);  
  Serial.begin(115200);
  i=0;
}

void loop() 
{
  if((digitalRead(sw1)==0)&&(i<9))
  {
    i++;
    out8bit(i);
  }
  if((digitalRead(sw2)==0)&&(i>0))
  {
    i--;
    out8bit(i);
  }
  Serial.print("i=");
  Serial.println(i);
  delay(100);
}

const char segment[]={  B00111111,
                        B00000110,
                        B01011011,
                        B01001111,
                        B01100110,
                        B01101101,
                        B01111101,
                        B00000111,
                        B01111111,
                        B01101111,
                        B00000000 };

void out8bit(unsigned char data)
{
  digitalWrite(led[0],segment[data] & B00000001);
  digitalWrite(led[1],segment[data] & B00000010);
  digitalWrite(led[2],segment[data] & B00000100);
  digitalWrite(led[3],segment[data] & B00001000);
  digitalWrite(led[4],segment[data] & B00010000);
  digitalWrite(led[5],segment[data] & B00100000);
  digitalWrite(led[6],segment[data] & B01000000);
  digitalWrite(led[7],segment[data] & B10000000);
}


  
  
///////////////////////////////////////////////////////////////
////////// binary count updown 7seg I /////////////////////////

// decimal count 7seg II //
int led[]={6,7,8,9,10,11,12,13};
int digit[]={5,4,3,2};
int i=0;
int delayTime=50;
long lastTime=0;
int tem1,tem2,tem3,tem4;

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
  pinMode(digit[0], OUTPUT);
  pinMode(digit[1], OUTPUT);
  pinMode(digit[2], OUTPUT);
  pinMode(digit[3], OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  if(millis()-lastTime>delayTime)
  {
    if(i<1999) i++;
    else i=0;
    Serial.print("i=");
    Serial.println(i);
    lastTime=millis();
    calculate(i);
  }
  display();
}

void calculate(int val)
{
  tem4=(val/1000);
  tem3=((val%1000)/100);
  tem2=(((val%1000)%100)/10);
  tem1=(((val%1000)%100)%10);

  if(tem4==0) tem4=10;
  if((tem3==0)&&(tem4==10)) tem3=10;
  if((tem2==0)&&(tem4==10)&&(tem3==10)) tem2=10;
}

void display()
{
  for(int sel=0;sel<4;sel++)
  {
    digitalWrite(digit[0],HIGH);
    digitalWrite(digit[1],HIGH);
    digitalWrite(digit[2],HIGH);
    digitalWrite(digit[3],HIGH);
    if(sel==0) {out8bit(tem1); digitalWrite(digit[0],LOW);}
    else if(sel==1) {out8bit(tem2); digitalWrite(digit[1],LOW);}
    else if(sel==2) {out8bit(tem3); digitalWrite(digit[2],LOW);}
    else if(sel==3) {out8bit(tem4); digitalWrite(digit[3],LOW);}
    delay(2);
  }
}

const char segment[]={  B00111111,
                        B00000110,
                        B01011011,
                        B01001111,
                        B01100110,
                        B01101101,
                        B01111101,
                        B00000111,
                        B01111111,
                        B01101111,
                        B00000000 };

void out8bit(unsigned char data)
{
  digitalWrite(led[0],segment[data] & B00000001);
  digitalWrite(led[1],segment[data] & B00000010);
  digitalWrite(led[2],segment[data] & B00000100);
  digitalWrite(led[3],segment[data] & B00001000);
  digitalWrite(led[4],segment[data] & B00010000);
  digitalWrite(led[5],segment[data] & B00100000);
  digitalWrite(led[6],segment[data] & B01000000);
  digitalWrite(led[7],segment[data] & B10000000);
}


  
