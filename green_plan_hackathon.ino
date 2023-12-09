int Moisture_signal = A7;
const int PWMA = 6;
const int AIN1 = 5;
const int AIN2 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop() {
  int Moisture = analogRead(Moisture_signal);
  Serial.println("Soil Moisture Level: ");
  int per = 101-(Moisture/10.23);
  Serial.println(per);
  if (per>49){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(PWMA, 255);

    delay(1000);

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);
    delay(1000);
    }
  delay(200);
}
