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
String temp = "";

#define ARRAY_SIZE 20

String commandArray[ARRAY_SIZE];
int commandArrayPos = 0;

//all the motors and its pin on ARDUINO MEGA
Stepper steppermotorwhite   (StepsPerRevolutionWhite   ,  2,  4,  3,  5);  //IN1,IN2,IN3,IN4
Stepper steppermotoryellow  (StepsPerRevolutionYellow  ,  6,  8,  7,  9);
Stepper steppermotorred     (StepsPerRevolutionRed     , 10, 12, 11 , 13);
Stepper steppermotororange  (StepsPerRevolutionOrange  , 14, 16, 15, 17);
Stepper steppermotorblue    (StepsPerRevolutionBlue    , 18, 20, 19 , 21);
Stepper steppermotorgreen   (StepsPerRevolutionGreen   , 22, 24, 23 , 25);

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
  if (Serial.available() > 0) {
    

      char Step = Serial.read();
      algo += Step;


      if (Step == '\n') {

        for (int i = 0 ; i <= algo.length() ; i++) {

          if (algo[i] != ',') {

            temp += algo[i];

          } else if ( algo[i] == ',') {

            commandArray[commandArrayPos] = temp;
            temp = "";
            commandArrayPos++;

          }


        }

        for (int i = 0 ; i < ARRAY_SIZE ; i++) {

          if (commandArray[i] != NULL || commandArray[i] != 0) {

            //front side/motor (red)
            if (commandArray[i].equals("F")) {
              steppermotorred.step(512);
              delay(10);
            }
            else if (commandArray[i].equals("F'")) {                                            //RED
              steppermotorred.step(-512);
              delay(10);
            }
            else if (commandArray[i].equals("F2")) {
              steppermotorred.step(1024);
              delay(10);
            }
            //...................................

            //down side/motor (white)
            else if (commandArray[i].equals("D")) {
              steppermotorwhite.step(512);

            }
            else if (commandArray[i].equals("D'")) {                                           //WHITE
              steppermotorwhite.step( -512);

            }
            else if (commandArray[i].equals("D2")) {
              steppermotorwhite.step(1024);

            }
            //...................................

            //left side/motor (blue)
            else if (commandArray[i].equals("L")) {
              steppermotorblue.step(512);
              delay(10);
            }
            else if (commandArray[i].equals("L'")) {                                             //BLUE
              steppermotorblue.step(-512);
              delay(10);
            }
            else if (commandArray[i].equals("L2")) {
              steppermotorblue.step(1024);
              delay(10);
            }
            //...................................

            //right side/motor (green)
            else if (commandArray[i].equals("R")) {
              steppermotorgreen.step(512);
              delay(10);
            }
            else if (commandArray[i].equals("R'")) {                                             //GREEN
              steppermotorgreen.step(-512);
              delay(10);
            }
            else if (commandArray[i].equals("R2")) {
              steppermotorgreen.step(1024);
              delay(10);
            }
            //...................................

            //back side/motor (orange)
            else if (commandArray[i].equals("B")) {
              steppermotororange.step(512);
              delay(10);
            }
            else if (commandArray[i].equals("B'")) {                                             //ORANGE
              steppermotororange.step(-512);
              delay(10);
            }
            else if (commandArray[i].equals("B2")) {
              steppermotororange.step(1024);
              delay(10);
            }
            //...................................

            //upper side/motor (yellow)
            else if (commandArray[i].equals("U")) {
              steppermotoryellow.step(512);
              delay(10);
            }
            else if (commandArray[i].equals("U'")) {                                             //YELLOW
              steppermotoryellow.step(-512);
              delay(10);
            }
            else if (commandArray[i].equals("U2")) {
              steppermotoryellow.step(1024);
              delay(1000);
            }
            //...................................
            //reset the vairiable
          }
        }
        temp = "";
        commandArrayPos = 0;
        memset (commandArray, 0, 20);
        algo = ""; // no left over ;read for next command
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

      }
    }
  }

