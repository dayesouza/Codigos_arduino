#define poten A7

int valPot = 0;
int valor_antigo = 0;
void setup() {
 Serial.begin(9600);//fechando a comunicacao entre o arduino e o pc
}

void loop() {
  int valorPot = analogRead(poten);//pega o valor analogico do potenciometro
  valPot = map(valorPot,0,1023,0,100); //faz o map (map(valor,0,1023,0,255)
  if (valor_antigo != valPot){
    Serial.print("Valor do potenciometro= ");
    Serial.println(valPot);
  }
  valor_antigo = valPot;
}
