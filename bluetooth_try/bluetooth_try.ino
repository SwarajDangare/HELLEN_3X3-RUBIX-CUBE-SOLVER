#include <SoftwareSerial.h>
SoftwareSerial BT(19, 18); 
// creates a "virtual" serial port/UART
// connect BT module TX to 0
// connect BT module RX to 1
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set digital pin to control as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available()>0)
  
  // if text arrived in from BT serial...
  {
    a=Serial.read();
    if (a=='\n')
 {
    if (a=="1")
    {
      digitalWrite(LED_BUILTIN, HIGH);
      BT.println(" LED on");
    }
    if (a=="2")
    {
      digitalWrite(LED_BUILTIN, LOW);
      BT.println(" LED off");
    }
    if (a=="?")
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}}

