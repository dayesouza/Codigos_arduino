int motor1A = 8;
int motor1B = 9;
int motor2A = 10;
int motor2B = 11;

void setup() {
  pinMode(motor1A,OUTPUT);
  pinMode(motor1B,OUTPUT);
  pinMode(motor2A,OUTPUT);
  pinMode(motor2B,OUTPUT);
Serial.begin(9600);
}

void loop() {
  char leitura = Serial.read();
  switch (leitura){
    case 'f': 
      digitalWrite(motor1A,HIGH);
      digitalWrite(motor2A,HIGH);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,LOW);
      Serial.println("Em frente!");
    break;
    case 'p':
    digitalWrite(motor1A,LOW);
      digitalWrite(motor2A,LOW);
      digitalWrite(motor1B,LOW);
      digitalWrite(motor2B,LOW);
      Serial.println("Parar!");
    break;
  }
}
