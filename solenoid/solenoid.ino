Servo myservo;
//set pins for servo and the motor attached to the wheel (we had one front wheel
// connected to a motor. This will probably be changed, as drag was a big issue.
// We plan to use a motor on each of the rear wheels.)
const int servoPin = D0;
const int wheelPin = D2;
//two bools for the different states of the machine. We do want to have rolling
//and spraying at the same time.
bool rolling = true;
bool spraying = false;


void setup(){
  //make pins available to be interacted with
  myservo.attach(servoPin);
  pinMode(wheelPin, OUTPUT);
}

void loop(){
  //machine is spraying, set rolling to true and spraying to false at end
  if ((rolling == false) && (spraying == true)){
    //servo pulls the trigger for .37 s
    myservo.write(120);
    delay(370);
    myservo.write(0);
    delay(500);
    //swap boolean states
    rolling = true;
    spraying = false;

  //machine is rolling, set spraying to true and rolling to false at end
  } else if ((rolling == true) && (spraying == false)){
    //let motor spin for 1 second
    analogWrite(wheelPin, 200);
    delay(1000);
    analogWrite(wheelPin, 0);
    delay(200);
    //swap boolean states
    rolling = false;
    spraying = true;
  }
}
