//CUBE SOLVER ROBOT
//SWARAJ DANGARE
//ST.MICHAEL'S SCHOOL

//SORCE OF ALL THE INFORMATION :
//INFO/WORKING ABOUT STEPPER MOTOR FROM MY FATHER



#include <Stepper.h>
#include <SoftwareSerial.h>
//constant defined
//according to my stepper motors [name:(STEP MOTOR 28BY-48 5VDC)]
//defining colour wise

//White side motor
int StepsPerRevolution  = 32;
int GearReduction = 64;
int StepsPerOutputRotation = StepsPerRevolution * GearReduction;
////yellow side motor
//int StepsPerRevolutionYellow  = 32;
//int GearReductionYellow = 64;
//int StepsPerOutputRotationYellow = StepsPerRevolutionYellow * GearReductionYellow;
////Red side motor
//int StepsPerRevolutionRed  = 32;
//int GearReductionRed = 64;
//int StepsPerOutputRotationRed = StepsPerRevolutionRed * GearReductionRed;
////Orange side motor
//int StepsPerRevolutionOrange  = 32;
//int GearReductionOrange = 64;
//int StepsPerOutputRotationOrange = StepsPerRevolutionOrange * GearReductionOrange;
////Blue side motor
//int StepsPerRevolutionBlue  = 32;
//int GearReductionBlue = 64;
//int StepsPerOutputRotationBlue = StepsPerRevolutionBlue * GearReductionBlue;
////Green side motor
//int StepsPerRevolutionGreen  = 32;
//int GearReductionGreen = 64;
//int StepsPerOutputRotationGreen = StepsPerRevolutionGreen * GearReductionGreen;

//defining the alogorithms(Steps)
String algo ;
String temp = "";

#define ARRAY_SIZE 20

String commandArray[ARRAY_SIZE];
int commandArrayPos = 0;

//all the motors and its pin on ARDUINO MEGA
Stepper steppermotorwhite   (StepsPerRevolution   , 42, 44, 43, 45);  //IN1,IN2,IN3,IN4
Stepper steppermotoryellow  (StepsPerRevolution   , 38, 40, 39, 41);
Stepper steppermotorred     (StepsPerRevolution   , 34, 36, 35, 37);
Stepper steppermotororange  (StepsPerRevolution   , 30, 32, 31, 33);
Stepper steppermotorblue    (StepsPerRevolution   , 26, 28, 27, 29);
Stepper steppermotorgreen   (StepsPerRevolution   , 8, 10, 9, 11);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  //start communication at 9600 baud
  Serial.begin(9600);
  //set the speed of the motors(rpm)
  //i have set it to the highest speed 1100rpm according to my motor
  steppermotorwhite.  setSpeed (700);
  steppermotoryellow. setSpeed (700);
  steppermotorred.    setSpeed (700);
  steppermotororange. setSpeed (700);
  steppermotorblue.   setSpeed (700);
  steppermotorgreen.  setSpeed (700);

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
              Serial.print("F");
              delay(1000);
            }
            else if (commandArray[i].equals("F'")) {                                            //RED
              steppermotorred.step(-512);
              Serial.print("F'");
              delay(1000);
            }
            else if (commandArray[i].equals("F2")) {
              steppermotorred.step(1024);
              delay(1000);
            }
            //...................................

            //down side/motor (white)
            else if (commandArray[i].equals("D")) {
              steppermotorwhite.step(512);
              delay(1000);
            }
            else if (commandArray[i].equals("D'")) {                                           //WHITE
              steppermotorwhite.step( -512);
              delay(1000);
            }
            else if (commandArray[i].equals("D2")) {
              steppermotorwhite.step(1024);
              delay(1000);
            }
            //...................................

            //left side/motor (blue)
            else if (commandArray[i].equals("L")) {
              steppermotorblue.step(512);
              delay(1000);
            }
            else if (commandArray[i].equals("L'")) {                                             //BLUE
              steppermotorblue.step(-512);
              delay(1000);
            }
            else if (commandArray[i].equals("L2")) {
              steppermotorblue.step(1024);
              delay(1000);
            }
            //...................................

            //right side/motor (green)
            else if (commandArray[i].equals("R")) {
              steppermotorgreen.step(512);
              delay(1000);
            }
            else if (commandArray[i].equals("R'")) {                                             //GREEN
              steppermotorgreen.step(-512);
              delay(1000);
            }
            else if (commandArray[i].equals("R2")) {
              steppermotorgreen.step(1024);
              delay(1000);
            }
            //...................................

            //back side/motor (orange)
            else if (commandArray[i].equals("B")) {
              steppermotororange.step(512);
              delay(1000);
            }
            else if (commandArray[i].equals("B'")) {                                             //ORANGE
              steppermotororange.step(-512);
              delay(1000);
            }
            else if (commandArray[i].equals("B2")) {
              steppermotororange.step(1024);
              delay(1000);
            }
            //...................................

            //upper side/motor (yellow)
            else if (commandArray[i].equals("U")) {
              steppermotoryellow.step(512);
              delay(1000);
            }
            else if (commandArray[i].equals("U'")) {                                             //YELLOW
              steppermotoryellow.step(-512);
              delay(1000);
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

      }//U',L,F,R2,D,B2,U,R,F',D',F',U',F2,D,F2,U',R2,U',D2,B2,D,
    }
  }
