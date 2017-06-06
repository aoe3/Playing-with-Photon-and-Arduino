const int ledPin = D0; // LED connected to digital pin 7

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Temporary buffer
  byte incoming_byte;
  String record = "";

  // Check if the something is pending
  if (Serial.available() > 0){
    // Read the pending byte;
    incoming_byte = Serial.read();
    Serial.write(incoming_byte);
    Serial1.write(incoming_byte);

    if (incoming_byte == '1'){
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '2') {
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '3') {
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '4') {
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '5') {
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '6') {
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '7') {
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '8') {
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '9') {
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dot
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == '0') {
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      delay(300);
      //dash
      digitalWrite(ledPin, HIGH);
      delay(900);
      digitalWrite(ledPin, LOW);
      //in case part of sequence of characters
      digitalWrite(ledPin, LOW);
      delay(900);

    } else if (incoming_byte == ' ') {
      //only 1200 as each char already has 900ms offset to account for words
      digitalWrite(ledPin, LOW);
      delay(1200);

    } else {
      // For anything not # or '_' we will just shut LED off.
      digitalWrite(ledPin, LOW);
    }
  }
}
