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
