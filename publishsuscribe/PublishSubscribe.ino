// from https://docs.particle.io/guide/getting-started/examples/photon/#the-buddy-system-publish-and-subscribe
const int blue_led_pin = D7;
const int redPin = D0;
const int grnPin = D1;
const int bluPin = D2;


void setup() {
  Serial.begin(9600);
  pinMode(blue_led_pin, OUTPUT);

  Particle.subscribe("Dot_Dash_fvg", dot_dash_handler);
}


void loop() {
  if (Serial.available())
  {
    switch (Serial.read())
    {
      case '.':
        Particle.publish("Dot_Dash_fvg","Dot");
        break;
      case '-':
        Particle.publish("Dot_Dash_fvg","Dash");
        break;
      default:
        break;
    }
  }
}


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void dot_dash_handler(const char *event, const char *data)
{
  /* Particle.subscribe handlers are void functions, which means they don't return anything.
  They take two variables-- the name of your event, and any data that goes along with your event.
  Note we have to use the strcmp functions. If they are the same, strcmp will return 0.
  */

  if (strcmp(data,"Dot")==0) {
    digitalWrite(bluPin, HIGH);
    delay(300);
    digitalWrite(bluPin, LOW);
  }
  else if (strcmp(data,"Dash")==0) {
    digitalWrite(redPin, HIGH);
    delay(3*300);
    digitalWrite(redPin, LOW);
  }
  else {
    // if the data is something else, don't do anything.
  }
  digitalWrite(bluPin, LOW);
  delay(300);
}
