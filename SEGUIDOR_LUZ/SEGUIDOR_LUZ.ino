
#define pinoldr1 A0
#define pinoldr2 A1
#define pinomot1a 6
#define pinomot1b 9
#define pinomot2a 10
#define pinomot2b 11

void setup() {
  Serial.begin(9600);
  pinMode(pinomot1a, OUTPUT);
  pinMode(pinomot1b, OUTPUT);
  pinMode(pinomot2a, OUTPUT);
  pinMode(pinomot2b, OUTPUT);
}

void loop() {
  int valorldr1 = analogRead(pinoldr1);
  int valorldr2 = analogRead(pinoldr2);
  Serial.print("LDR1 = ");
  Serial.print(valorldr1);
  Serial.print(" LDR2 = ");
  Serial.println(valorldr2);

  if ((valorldr1 >= 100) && (valorldr2 < 100)) {
    analogWrite(pinomot1a, 100);
    analogWrite(pinomot1b, 0);
    analogWrite(pinomot2a, 0);
    analogWrite(pinomot2b, 0);
  }

  if ((valorldr1 < 100) && (valorldr2 >= 100)) {
    analogWrite(pinomot1a, 0);
    analogWrite(pinomot1b, 0);
    analogWrite(pinomot2a, 100);
    analogWrite(pinomot2b, 0);
  }

  if ((valorldr1 >= 100) && (valorldr2 >= 100)) {
    analogWrite(pinomot1a, 100);
    analogWrite(pinomot1b, 0);
    analogWrite(pinomot2a, 100);
    analogWrite(pinomot2b, 0);
  }

  if ((valorldr1 < 100) && (valorldr2 < 100)) {
    analogWrite(pinomot1a, 255);
    analogWrite(pinomot1b, 0);
    analogWrite(pinomot2a, 255);
    analogWrite(pinomot2b, 0);
  }

}
