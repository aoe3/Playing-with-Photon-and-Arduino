const int tonePin = D0;
const int greenLED = D1;
const int redLED = D2;
const int potentiometer = A0;
const int sonarPin = A1;

double pVal = 0;
double sVal = 0;
double pVoltage = 0;
double sVoltage = 0;
double pCM = 0;
double sonar_cm = 0;
double pInches = 0;
double sonar_inches = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  //Read potentiometer and convert the reading to "inches."
  pVal = analogRead(potentiometer);
  pVoltage = map(pVal, 0.0, 4095.0, 0.0, 3300);
  pCM = ((70.0/(pVoltage/1000.0)) - 6.0);
  pInches = (pCM/2.54);

  //Read the sonar and convert the output to inches.
  sVal = analogRead(sonarPin);
  sVoltage = map(sVal, 0.0, 4095.0, 0.0, 3300);
  sonar_cm = ((70.0/(sVoltage/1000.0)) - 6.0);
  sonar_inches = (sonar_cm/2.54);

  //Check the potentiometer is in the range of 15cm (6 in) to 150cm (60 in).
  if((6.0 < pInches) && (pInches < 60.0)){

    /*String p = "Potentiometer: ";
    String s = "Sonar: ";
    p.concat(pInches);
    s.concat(sonar_inches);
    Serial.print(p);
    Serial.print("\n");
    Serial.print(s);
    Serial.print("\n");*/

    //set range for human error, within 3 inches of actual reading; 1.5 on each
    //side
    double minBoundary = (pInches - 1.5);
    Serial.print(minBoundary);
    Serial.print("\n");
    double maxBoundary = (pInches + 1.5);
    Serial.print(maxBoundary);
    Serial.print("\n");

    //The object is closer to the sonar than the potentiometer's reading.
    if (sonar_inches < minBoundary){
      pinMode(greenLED, OUTPUT);
      /*Serial.print("Less than");
      Serial.print("\n");*/
      // range is from 15cm (6 in) to minBoundary
      double range = (minBoundary - 6.0);

      /*Find relative distance in that range.
      Ex:

        6_inches-------------------------signal-------------maxBoundary
                                        |__________difference_________|
        |__________________________range______________________________|
      */

      double difference = (minBoundary - sonar_inches);

      //If ratio is low, then the object is close to the range
      double ratio = (difference/range);

      /*Set LED based on ratio. A low ratio should be dim, and the object will
      be close. A high ratio is bright and the object will be far.
      */

      // Find what to scale the brightness by.
      double scaled = (255.0 * ratio);
      /*Serial.print(scaled);
      Serial.print("\n");*/
      analogWrite(greenLED, scaled);

    //The object is farther from the sonar than the potentiometer's reading.
    } else if (sonar_inches > maxBoundary){
      pinMode(redLED, OUTPUT);
      /*Serial.print("Greater than");
      Serial.print("\n");*/
      //range is from maxBoundary to 150cm (60 in)
      double range = (60.0 - maxBoundary);

      /*Find relative distance in that range.
      Ex:

        maxBoundary------signal-------------------------------60_inches
        |______difference_____|
        |__________________________range______________________________|
      */

      double difference = (sonar_inches - maxBoundary);

      //If ratio is low, then the object is close to the range.
      double ratio = (difference/range);

      /*Set LED based on ratio. A low ratio should be dim, and the object will
      be close. A high ratio is bright and the object will be far.
      */

      // Find what to scale the brightness by.
      double scaled = (255.0 * ratio);
      /*Serial.print(scaled);
      Serial.print("\n");*/
      analogWrite(redLED, scaled);

    } else {
      /*Serial.print("In range");
      Serial.print("\n");*/
      // We are in the range specified by the potentiometer. We will make a tone.
      // The commented out sequence is "Twinkle, twinkle, little star."" I tried
      // to get it to play the sequence, but then it doesn't judge change in
      // distance as constantly as it should. It waits for the whole tone to
      // play and complete before reading again.
      tone(tonePin, 261, 500);
      delay(1000);
      /*
      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 440, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 440, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      delay(400);

      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      delay(400);


      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      delay(400);

      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      delay(400);

      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 440, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 440, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 392, 500);
      delay(400);
      noTone(tonePin);
      delay(400);

      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 349, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 329, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 294, 500);
      delay(400);
      noTone(tonePin);
      tone(tonePin, 261, 500);
      delay(400);
      noTone(tonePin);
      delay(2000);*/
    }

  // The potentiometer's reading was not between 15cm (6 in) to 150cm (60 in).
  } else {
    /*Serial.print("Potentiometer outside of 15cm to 150cm.");*/
    //Flash the LEDs to draw attention.
    pinMode(greenLED, OUTPUT);
    digitalWrite(greenLED, HIGH);
    delay(1000);
    digitalWrite(greenLED, LOW);
    pinMode(redLED, OUTPUT);
    digitalWrite(redLED, HIGH);
    delay(1000);
    digitalWrite(redLED, LOW);
  }
}
