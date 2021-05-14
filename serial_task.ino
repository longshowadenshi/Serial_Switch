HardwareSerial Serial( PA3, PA2 ); 
#define  stdout  Serial
#define button A0

int ONcount=0;
int OFFcount=0;
int value;
int oldvalue=0;

void setup() {
  stdout.begin( 115200UL );
  delay( 20UL );
  pinMode(A0,INPUT);
}
//when switch off, the value read from A0pin is about 950~960
//and when switch on , the value read from A0pin is about ~ 0
void loop() {
value=analogRead(A0);
if((value-oldvalue)>950)
{
  OFFcount=OFFcount+1;
}
if((value-oldvalue)<(-950))
{
  ONcount=ONcount+1;
}
oldvalue=value;
delay(10);
stdout.print(" OFF = ");
stdout.println(OFFcount);
stdout.print(" ON = ");
stdout.println(ONcount);
}
