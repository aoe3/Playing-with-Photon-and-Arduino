// LED connected to pin 9
const int ledPin = D0;
// button connected to pin 10
const int buttonPin = A0;
// State of the button
byte current_button = LOW;
// Previous state of the button
byte old_button = LOW;
// Empty string
String record = "";
// Record for time
unsigned long previousTime = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}

void loop(){
  while (1) { // Fast loop…
    Particle.process();
    // Read the state of the button
    current_button = digitalRead(buttonPin);
    // LOW to HIGH transition:
    if ((old_button == LOW) && (current_button == HIGH)) {
      previousTime = millis();

    // HIGH to LOW transition:
    } else if ((old_button == HIGH) && (current_button == LOW)){
      unsigned long endTime = millis();
      // we record dots or dashes. 200ms will be used to account
      // for human error with a 100ms buffer range for dots and dashes
        if ((endTime - previousTime) < 200){
          record =  record + ".";
          //Let us know we input correctly
          Serial.print("dot");
        } else if ((endTime - previousTime) >= 200){
          record = record + "-";
          //Let us know we input correctly
          Serial.print("dash");
        }
        previousTime = endTime;
    }

    // remember the state of the button
    old_button = current_button;
    // Update the LED pin

    if (record.length() == 5) {
      //Change motor speed based on record's contents.
      if(record == ".----"){
        analogWrite(ledPin, (255 * 0.11));
        //Let us know we output correctly
        Serial.print("1");
        Serial.print('\n');
        record = "";
      } else if (record == "..---"){
        analogWrite(ledPin, (255 * 0.22));
        //Let us know we output correctly
        Serial.print("2");
        Serial.print('\n');
        record = "";
      } else if (record == "...--"){
        analogWrite(ledPin, (255 * 0.33));
        //Let us know we output correctly
        Serial.print("3");
        Serial.print('\n');
        record = "";
      } else if (record == "....-"){
        analogWrite(ledPin, (255 * 0.44));
        //Let us know we output correctly
        Serial.print("4");
        Serial.print('\n');
        record = "";
      } else if (record == "....."){
        analogWrite(ledPin, (255 * 0.55));
        //Let us know we output correctly
        Serial.print("5");
        Serial.print('\n');
        record = "";
      } else if (record == "-...."){
        analogWrite(ledPin, (255 * 0.66));
        //Let us know we output correctly
        Serial.print("6");
        Serial.print('\n');
        record = "";
      } else if (record == "--..."){
        analogWrite(ledPin, (255 * 0.77));
        //Let us know we output correctly
        Serial.print("7");
        Serial.print('\n');
        record = "";
      } else if (record == "---.."){
        analogWrite(ledPin, (255 * 0.88));
        //Let us know we output correctly
        Serial.print("8");
        Serial.print('\n');
        record = "";
      } else if (record == "----."){
        analogWrite(ledPin, 255);
        //Let us know we output correctly
        Serial.print("9");
        Serial.print('\n');
        record = "";
      }else if (record == "-----"){
        analogWrite(ledPin, 0);
        //Let us know we output correctly
        Serial.print("0");
        Serial.print('\n');
        record = "";
      }
    // This next line is to deal with faulty inputs
    // like dot dash dot dash dot (. - . - .)
    } else if (record.length() > 5){
      record = "";
    }
  }
}
