const int ledPin = D0; // LED connected to analog pin 7

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Temporary buffer
  byte incoming_byte;

  // Check if the something is pending
  if (Serial.available() > 0){
    // Read the pending byte;
    incoming_byte = Serial.read();
    Serial.write(incoming_byte);
    Serial1.write(incoming_byte);

    if (incoming_byte == '1'){
      //11%
      analogWrite(ledPin, (255 * 0.11));

    } else if (incoming_byte == '2') {
      //22%
      analogWrite(ledPin, (255 * 0.22));

    } else if (incoming_byte == '3') {
      //33%
      analogWrite(ledPin, (255 * 0.33));

    } else if (incoming_byte == '4') {
      //44%
      analogWrite(ledPin, (255 * 0.44));

    } else if (incoming_byte == '5') {
      //55%
      analogWrite(ledPin, (255 * 0.55));

    } else if (incoming_byte == '6') {
      //66%
      analogWrite(ledPin, (255 * 0.66));

    } else if (incoming_byte == '7') {
      //77%
      analogWrite(ledPin, (255 * 0.77));

    } else if (incoming_byte == '8') {
      //88%
      analogWrite(ledPin, (255 * 0.88));

    } else if (incoming_byte == '9') {
      //on
      analogWrite(ledPin, 255);


    } else if (incoming_byte == '0') {
      //off
      analogWrite(ledPin, 0);

    }
  }
}
