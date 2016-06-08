int led = 3;
int ldr = A1;

int valorLdr = 0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
  valorLdr = analogRead(ldr);
  float valorLuminosidade = map(valorLdr,0,1023,0,255);

  if(valorLuminosidade < 200){
    valorLuminosidade = 0;//Para desligar se o valor for muito baixo
  }
  
   analogWrite(led,valorLuminosidade);
}
