


// colour sensor pins connected to Arduino
const int s0 = 2;
const int s1 = 3;
const int s2 = 4;
const int s3 = 5;
const int out = 6;

// Variables
int red = 0;
int green = 0;
int blue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

}

void loop()
{
  color();
  Serial.print("R =");
  Serial.print(red, DEC);
  Serial.print(" G = ");
  Serial.print(green, DEC);
  Serial.print(" B = ");
  Serial.print(blue, DEC);
  Serial.print("\n");


  if (red < blue && red < green && red < 40)
  {
    if (red>=30 && red>=40 && green>=55 && green>=68 && blue<=40 &&blue<=50)
    {
      
      Serial.print("red");             //red
     
    }

   else if (green - red <= 10 && green - red >= -3 && blue >= green)
    {
      Serial.print("yellow");             //yellow
   
    }
    
    else if (green - blue >= -5 && green - blue <= 5 && green - ( 2 * red ) <= 5 )
    {
      Serial.print("orange");             //orange
    
    }

  }

  else if (green < red && green < blue && green < 25)
  {
    Serial.print("green");               //green

  }

  else if ((red > green &&  blue < green) && blue < 25 && red > 40)
  {
    Serial.print("blue");               //blue

  }

  else if (blue < red && blue < green && (blue && red && green) < 25)
  {

    if (red - green <= 5 && red - green >= 0 && ((green - blue) || (red - blue)) < 5 && blue < 50)
    {
      Serial.print("white");             //white

    }
  }

  delay(300);
}

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
