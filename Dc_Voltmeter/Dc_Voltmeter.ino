/*
  DC Voltmeter
  An Arduino based on voltage divider concept
  Shahadat Hossen Razib
  Youtube Channel: Razib Shahadat
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K)
float R2 = 10000.0; // resistance of R2 (10K)
int value = 0;
int a[5] = {};
void setup() {
  Serial.begin(9600);
  pinMode(analogInput, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("DC VOLTMETER");
  lcd.setCursor(2, 1);
  lcd.print("ST.Michael's");
  delay(5000);
  lcd.clear();

}
void loop() {
  lcd.print("DC Voltmeter");
  // read the value at analog input
  value = analogRead(analogInput);
  vout = (value * 5) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  Serial.println(vin);
  if (vin < 0.09)
  {
    vin = 0.0;
  }
  lcd.setCursor(0, 1);
  lcd.print("Voltage V :");
  lcd.print(vin);
  delay(500);
  lcd.clear();
 Serial.print(vin);
}
