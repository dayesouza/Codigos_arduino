#define poten A7
#define led 3

int valPot = 0;
void setup() {
 pinMode(led,OUTPUT);
}

void loop() {
  int valorPot = analogRead(poten);//pega o valor analogico do potenciometro
  valPot = map(valorPot,0,1023,0,255); //faz o map (map(valor,0,1023,0,255)
  analogWrite(led,valPot);//escreve na saida analogica do led
}
