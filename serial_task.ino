HardwareSerial Serial( PA3, PA2 ); 
#define  stdout  Serial
#define button A0

int Count=0;
int value;
int oldval=0;
int state=0;

void setup() {
  stdout.begin( 115200UL );
  delay( 20UL );
  pinMode(A0,INPUT);
}
void loop() {
value=digitalRead(A0);
if((value==HIGH)&&(oldval==LOW))
  {
    state=1-state;
    delay(10);
  }  
oldval=value;
if(state==1)
{
  Count=Count+1;  // count up
}
else
{
  Count=Count-1;  // count down
}
stdout.print(" Count = ");
stdout.println(Count);
}
