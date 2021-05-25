int ldrPin = 0;
int pirPin = 10;
int relayPin = 9;
int lightThreshold = 200;

void setup(){
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop(){

  bool isDark = analogRead(ldrPin) < lightThreshold;
  bool isMotionDetected = digitalRead(pirPin) == HIGH;

  digitalWrite(relayPin, isDark && isMotionDetected ? LOW : HIGH);
  
  Serial.println(isDark ? "DARK" : "BRIGHT");
  Serial.println(isMotionDetected ? "MOTION DETECTED" : "NO MOTION");
  Serial.println(isDark && isMotionDetected ? HIGH : LOW);
  Serial.println("========");
  delay(1000);
  
}
