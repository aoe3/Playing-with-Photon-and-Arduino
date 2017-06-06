// Motor control
const int motorEnablePin = D0;
const int leftSidePin = D1;
const int rightSidePin = D2;
const int encoderPin = D3;

// old state of the encoder
boolean old_state = LOW;

// current state of the encoder
boolean current_state = LOW;

// current transition count
int pulse_count;

// number of transition for a full turn
const int full_turn_count = 900;

void setup(){
  // configure the motor pins
  pinMode(motorEnablePin,OUTPUT);
  pinMode(leftSidePin,OUTPUT);
  pinMode(rightSidePin,OUTPUT);
  // Motor is off going forward
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  // configure the photo-transistor pin
  pinMode(encoderPin,INPUT);
}

void loop(){

  //Serial.println("A");
  // reset the pulse counter
  pulse_count = 0;

//  Serial.println("B");
  // start the motor at 20% speed
  analogWrite(motorEnablePin,51);

//  Serial.println("C");
  // loop until we get the correct count

  while (pulse_count < full_turn_count){

    Particle.process();

    //Serial.println("D");
    // read the state of the photo-transistor

    current_state = digitalRead(encoderPin);
    //Serial.println(current_state);

    //Serial.println("E");
    if (current_state != old_state){
      // we detected a transition
      //Serial.println("F");
      pulse_count++;
      //Serial.println("G");
      //Serial.println(pulse_count);
      // delay here is problem with de-bounding
    }
    //Serial.println("H");
    old_state = current_state;
    //Serial.println("I");
  }
//  Serial.println("J");

  // switch off the motor
  if (digitalRead(leftSidePin) == HIGH){
    analogWrite(motorEnablePin,0);
    digitalWrite(leftSidePin, LOW);
    digitalWrite(rightSidePin, HIGH);
  } else {
    analogWrite(motorEnablePin,0);
    digitalWrite(leftSidePin, HIGH);
    digitalWrite(rightSidePin, LOW);
  }
//  Serial.println("K");

  // wait a bit
  delay(5000);
}
