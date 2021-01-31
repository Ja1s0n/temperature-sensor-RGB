#define tempPin A0;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int temp = 0;

void setColor(int red, int green, int blue) {
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatuteC = voltage * 100;
  Serial.print(temperatuteC); Serial.println(" degrees C");

  if (temperatuteC <= 0.0) setColor(0, 100, 255);
  if (temperatuteC > 0.0 && temperatuteC < 17.0) setColor(255, 184, 0);
  if (temperatuteC > 17.0 && temperatuteC <= 20.0) setColor(255, 255, 0);
  if (temperatuteC > 20.0) setColor(255, 50, 0);
  delay(500);
}