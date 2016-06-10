int Q1 = 8;//branco
int Q2 = 6;//Vermelho
int v = 5;//verde
int s = 4;//amarelo
int ldr = A0;
char leitura = ' '; //variavel que recebe o valor inserido

void setup() {
  Serial.begin(9600);//Inicializa a porta serial;
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(v,OUTPUT);
  pinMode(s,OUTPUT);
}

void loop() {
  leitura = Serial.read();
  if(leitura == ('q')){
       digitalWrite(Q2,!digitalRead(Q2));//faz a leitura e faz o oposto do que já esta acionado
  }
  else if(leitura == ('v')){
   digitalWrite(v,!digitalRead(v));//faz a leitura e faz o oposto do que já esta acionado
  }   
  else if(leitura == ('s')){
    digitalWrite(s,!digitalRead(s));//faz a leitura e faz o oposto do que já esta acionado
  }   
  else if(leitura == ('l')){
    int valorLdr = analogRead(ldr);
    int valorDigital = map(valorLdr,0,1023,0,100);
    int valor = (100-valorDigital);
    analogWrite(Q1,valor);//faz a leitura e faz o oposto do que já esta acionado
    Serial.print("O valor = ");
    Serial.println(valorDigital);
    delay(200);
  }
}
