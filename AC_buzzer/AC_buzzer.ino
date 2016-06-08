float seno;
int frequencia;
#define bot1 8
#define buzzer 3

void setup() {
  pinMode(bot1, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(bot1) == HIGH){
    for(int x=0;x<180;x++){
      //converte graus para radiando e depois obtém o valor do seno
      seno=(sin(x*3.1416/180));
      //gera uma frequência a partir do valor do seno
      frequencia = 2000+(int(seno*1000));
      tone(buzzer,frequencia);
      delay(2);
    }
  }
  else if(digitalRead(bot1) == LOW){ 
    noTone(buzzer);
  }
}
