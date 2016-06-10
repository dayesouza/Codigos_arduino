int ledRed = 5;
int ledGreen = 7;
int ledYellow = 6;

void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledYellow,OUTPUT);
}
                                                  
void loop() {
  digitalWrite(ledRed,HIGH);
  delay(3000);//3 segundos
  digitalWrite(ledRed,LOW);
  digitalWrite(ledGreen,HIGH);
  delay(2000);//3 segundos
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow, HIGH);
  delay(3000);
  digitalWrite(ledYellow,LOW);
  }
