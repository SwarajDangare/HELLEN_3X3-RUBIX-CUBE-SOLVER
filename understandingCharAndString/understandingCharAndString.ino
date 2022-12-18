
String Step;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  //start communication at 9600 baud
Serial.begin(9600);

pinMode(13, OUTPUT);


  }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
if (Serial.available()>0){
   char availableSerial = Serial.read();

   /*
   the problem is, when you in the Serial monitor you enter a word like "bat", arduino doesn't just see "bat", but instead, it sees "bat\r\n"

   now, \r means 'carriage return' which is nothing but bringing the cursor back to the start of the line.
        \n means 'line feed', which is nothing but pressing the button 'enter' on your keyboard, which takes you to the next line.

        Arduino sees all of this, so if you were to write an if statement saying: if (Step == "bat") it won't work. 
                                                               You have to write: if (Step == "bat\r\n"). Then it will work. 
   */
   
   
   Step += availableSerial; //Save all the characters being read in the serial monitor to the string: Step
   
   
   if(availableSerial == '\n'){ 
    
    /*We want to trigger an action only when the complete command has been entered. 
     So what the above line is saying is: 'if the command has been fully entered then....'
     Remember the final character in any string will be \n (which means nothing but 'enter'). Thats how we know the command has been entered.
   
    */
    
   Serial.print("Step is "); 
   Serial.println(Step);

   /*now we take whatever action based on the command. Here I have just turned an LED on and off based on the command. 
   Also remember, whatever command you wish to enter in the Serial monitor, make sure you follow it with the characters "\r\n".*/
   
   if(Step.equals("A\r\n")){ //notice how, when you are dealing with Strings, the syntax for '==' changes slightly.

    digitalWrite(13, HIGH);
    
    } else if(Step.equals("A'\r\n")){
      
      digitalWrite(13, LOW);
      
      }
    Step = ""; //you need to reset your String Step variable to null, so that it can read whatever next command you may enter in the serial monitor.
   }
   
   
}
}
