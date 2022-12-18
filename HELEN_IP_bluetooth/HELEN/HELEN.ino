

//CUBE SOLVER ROBOT
//SWARAJ DANGARE
//ST.MICHAEL'S SCHOOL

#include <Stepper.h>
#include <SoftwareSerial.h>
//for bluetooth control from mobile
//app needed
//I have built up an app by MIT App Inventor  http://www.appinventor.mit.edu
SoftwareSerial BT(0,1); //TX, RX

//define constant
//according to my stepper motors [name:(STEP MOTOR 28BY-48 5VDC)]
//defining colour wise

//White side motor
const float StepsPerRevolutionWhite  = 32;
const float GearReductionWhite = 64;
const float StepsPerOutputRotationWhite = StepsPerRevolutionWhite * GearReductionWhite;
//yellow side motor
const float StepsPerRevolutionYellow  = 32;
const float GearReductionYellow = 64;
const float StepsPerOutputRotationYellow = StepsPerRevolutionYellow * GearReductionYellow;
//Red side motor
const float StepsPerRevolutionRed  = 32;
const float GearReductionRed = 64;
const float StepsPerOutputRotationRed = StepsPerRevolutionRed * GearReductionRed;
//Orange side motor
const float StepsPerRevolutionOrange  = 32;
const float GearReductionOrange = 64;
const float StepsPerOutputRotationOrange = StepsPerRevolutionOrange * GearReductionOrange;
//Blue side motor
const float StepsPerRevolutionBlue  = 32;
const float GearReductionBlue = 64;
const float StepsPerOutputRotationBlue = StepsPerRevolutionBlue * GearReductionBlue;
//Green side motor
const float StepsPerRevolutionGreen  = 32;
const float GearReductionGreen = 64;
const float StepsPerOutputRotationGreen = StepsPerRevolutionGreen * GearReductionGreen;

//defining the alogorithms(Steps)
String algo ;


//all the motors and its pin on ARDUINO MEGA
Stepper steppermotorwhite   (StepsPerRevolutionWhite   ,  2,  4,  3,  5);
Stepper steppermotoryellow  (StepsPerRevolutionYellow  ,  6,  8,  7,  9);
Stepper steppermotorred     (StepsPerRevolutionRed     , 10, 12, 11 ,13);
Stepper steppermotororange  (StepsPerRevolutionOrange  , 14, 16, 15, 17);
Stepper steppermotorblue    (StepsPerRevolutionBlue    , 18, 20, 19 ,21);
Stepper steppermotorgreen   (StepsPerRevolutionGreen   , 22, 24, 23 ,25);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  
//start with bluetooth   
BT.begin(9600);

//start communication at 9600 baud
Serial.begin(9600);


//set the speed of the motors(rpm)
//i have set it to the highest speed 1100rpm according to my motor
 steppermotorwhite.setSpeed (1100);  
 steppermotoryellow.setSpeed (1100);  
 steppermotorred.setSpeed (1100);     
 steppermotororange.setSpeed (1100);  
 steppermotorblue.setSpeed (1100);    
 steppermotorgreen.setSpeed (1100); 

 Serial.println("HI,");
  Serial.println("I'AM HELEN");
  Serial.println("  THE CUBE SOVING GHOST!");
  Serial.println(" ");
  Serial.println("NOW NO NEED TO SOLVE CUBE !!");
  Serial.println("HERE IS A -CUBE SOLVING GHOST- FOR YOU !!");
  Serial.println(" ");
  Serial.println("PLEASE ENTER THE ALGORITHMS");
  Serial.println("AND SEE MY HORROR ");
  
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
while (BT.available())
{ 
  //if BT is available
  delay(10); 
  char Step = BT.read();// to read the data reciver from app(mobile)
  algo += Step; // built the strings :-  "R", "R'", "R2", "F", "F'", "R2", ETC.

  
//now defining the algorithms of cube
//each and every angle of all the 6 motors
//512 are the plus/step which gives the angle eg 512=90* ,1024=180*

//...................................

if(Step == '\n'){

//front side/motor (red)
if (algo.equals("F\r\n")){
steppermotorred.step(512);
delay(10);
}
else if (algo.equals("F'\r\n")){                                             //RED
steppermotorred.step(-512);
delay(10);
}
else if (algo.equals("F2\r\n")){
steppermotorred.step(1024);
delay(10);
}
//...................................       

//down side/motor (white)
else if (algo.equals("D\r\n")){
steppermotorwhite.step(512);    

}
else if (algo.equals("D'\r\n")){                                            //WHITE
steppermotorwhite.step( -512); 

}
else if (algo.equals("D2\r\n")){
steppermotorwhite.step(1024); 

}
//...................................

//left side/motor (blue)
else if (algo.equals("L\r\n")){
steppermotorblue.step(512);
delay(10);
}
else if (algo.equals("L'\r\n")){                                              //BLUE
steppermotorblue.step(-512);
delay(10);
}
else if (algo.equals("L2\r\n")){
steppermotorblue.step(1024);
delay(10);
}
//...................................

//right side/motor (green)
else if (algo.equals("R\r\n")){
steppermotorgreen.step(512);
delay(10);
}
else if (algo.equals("R'\r\n")){                                              //GREEN
steppermotorgreen.step(-512);
delay(10);
}
else if (algo.equals("R2\r\n")){
steppermotorgreen.step(1024);
delay(10);
}
//...................................

//back side/motor (orange)
else if (algo.equals("B\r\n")){
steppermotororange.step(512);
delay(10);
}
else if (algo.equals("B'\r\n")){                                              //ORANGE
steppermotororange.step(-512);
delay(10);
}
else if (algo.equals("B2\r\n")){
steppermotororange.step(1024);
delay(10);
}
//...................................

//upper side/motor (yellow)
else if (algo.equals("U\r\n")){
steppermotoryellow.step(512);
delay(10);
}
else if (algo.equals("U'\r\n")){                                              //YELLOW
steppermotoryellow.step(-512);
delay(10);
}
else if (algo.equals("U2\r\n")){
steppermotoryellow.step(1024);
delay(1000);
}
//...................................
//reset the vairiable
algo = ""; // no left over ;read for next command

//DONE
}}}
