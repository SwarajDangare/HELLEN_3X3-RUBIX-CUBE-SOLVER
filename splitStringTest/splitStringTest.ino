String test = "sw,ar,aj, ";

String temp = "";

String stringArray[20];

int stringArrayPos = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0; i < test.length(); i++) {

    if (test[i] != ',') {

      temp += test[i];

    } else if( test[i] == ',') {

      stringArray[stringArrayPos] = temp;
      temp = "";
      stringArrayPos++;

    }


  }

  stringArrayPos = 0;

  for (int i = 0 ; i < 20; i++) {

    if (stringArray[i] != NULL) {

      Serial.println(stringArray[i]);

    }

  }

}

void loop() {
  // put your main code here, to run repeatedly:



}
