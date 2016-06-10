int Q1 = 7;//branco
int Q2 = 6;//Vermelho
int v = 5;//verde
int s = 4;//amarelo
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
  if(leitura == 'Q'){
    digitalWrite(Q1,!digitalRead(Q1));//faz a leitura e faz o oposto do que já esta acionado
  }
  else if(leitura == ('q')){
       digitalWrite(Q2,!digitalRead(Q2));//faz a leitura e faz o oposto do que já esta acionado
  }
  else if(leitura == ('v')){
   digitalWrite(v,!digitalRead(v));//faz a leitura e faz o oposto do que já esta acionado
  }   
  else if(leitura == ('s')){
    digitalWrite(s,!digitalRead(s));//faz a leitura e faz o oposto do que já esta acionado
  }   
}
