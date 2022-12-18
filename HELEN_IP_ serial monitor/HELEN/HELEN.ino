//CUBE SOLVER ROBOT
//SWARAJ DANGARE
//ST.MICHAEL'S SCHOOL

//SORCE OF ALL THE INFORMATION :
//INFO/WORKING ABOUT STEPPER MOTOR FROM MY FATHER
//1) https://youtu.be/0qwrnUeSpYQ <FOR CODDING OF STEPPER MOTORS> 
//2) https://youtu.be/8oiMnygYRJo <TO CONNECT THE CODE WITH SERIAL MONITOR> 

  
#include <Stepper.h>
#include <SoftwareSerial.h>
//constant defined
//according to my stepper motors [name:(STEP MOTOR 28BY-48 5VDC)]
//defining colour wise

//White side motor
int StepsPerRevolutionWhite  = 32;
int GearReductionWhite = 64;
int StepsPerOutputRotationWhite = StepsPerRevolutionWhite * GearReductionWhite;
//yellow side motor
int StepsPerRevolutionYellow  = 32;
int GearReductionYellow = 64;
int StepsPerOutputRotationYellow = StepsPerRevolutionYellow * GearReductionYellow;
//Red side motor
int StepsPerRevolutionRed  = 32;
int GearReductionRed = 64;
int StepsPerOutputRotationRed = StepsPerRevolutionRed * GearReductionRed;
//Orange side motor
int StepsPerRevolutionOrange  = 32;
int GearReductionOrange = 64;
int StepsPerOutputRotationOrange = StepsPerRevolutionOrange * GearReductionOrange;
//Blue side motor
int StepsPerRevolutionBlue  = 32;
int GearReductionBlue = 64;
int StepsPerOutputRotationBlue = StepsPerRevolutionBlue * GearReductionBlue;
//Green side motor
int StepsPerRevolutionGreen  = 32;
int GearReductionGreen = 64;
int StepsPerOutputRotationGreen = StepsPerRevolutionGreen * GearReductionGreen;

//defining the alogorithms(Steps)
String algo ;


//all the motors and its pin on ARDUINO MEGA
Stepper steppermotorwhite   (StepsPerRevolutionWhite   ,  2,  4,  3,  5);  //IN1,IN2,IN3,IN4
Stepper steppermotoryellow  (StepsPerRevolutionYellow  ,  6,  8,  7,  9);
Stepper steppermotorred     (StepsPerRevolutionRed     , 10, 12, 11 ,13);
Stepper steppermotororange  (StepsPerRevolutionOrange  , 14, 16, 15, 17);
Stepper steppermotorblue    (StepsPerRevolutionBlue    , 18, 20, 19 ,21);
Stepper steppermotorgreen   (StepsPerRevolutionGreen   , 22, 24, 23 ,25);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
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

  //SIR I TOOK THIS NAME FOR THIS PROJECT FROM OUR 10 STD'S ENGLISH LESSON :-) 
  Serial.println("HI,");
  Serial.println("I'AM HELEN");
  Serial.println("  THE CUBE SOVING GHOST!");
  Serial.println(" ");
  Serial.println("NOW NO NEED TO SOLVE CUBE !!");
  Serial.println("HERE IS A -CUBE SOLVING GHOST- FOR YOU !!");
  Serial.println(" ");
  Serial.println("PLEASE ENTER THE ALGORITHMS");
  Serial.println("AND SEE MY HORROR ");
  algo = Serial.parseInt();


  }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
if (Serial.available()>0){
  {
   
 char Step = Serial.read();
  algo += Step;
  //SIR I TOOK THIS NAME FOR THIS PROJECT FROM OUR 10 STD'S ENGLISH LESSON :-) 

//now defining the algorithms of cube
//each and every angle of all the 6 motors
//512 are the plus/step which gives the angle eg 512=90* ,1024=180*
 
//...................................

// sir i have tryed with both ("*F#"),("*F'#").. AND ("F"),("F'") [FORM MY PREVIOUS PROJECT : VOICE/TEXT BLUETOOR CONTROLED CAR ] 
//which is also like this (with if and else code) but via bluetooth and working fantastic!!

//.........................................

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
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

}}}}

