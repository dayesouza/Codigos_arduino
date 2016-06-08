float seno;
int frequencia;
#define bot1 8
#define buzzer 3

void setup() {
  pinMode(bot1, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
    // Aciona o buz
    //;zer na frequencia relativa ao Dó em Hz
    tone(buzzer,261);    
    // Espera um tempo para Desativar
    delay(2000);
    //Desativa o buzzer
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Ré em Hz   
    tone(buzzer,293);             
    delay(2000);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Mi em Hz
    tone(buzzer,329);      
    delay(2000);
    noTone(buzzer);     
    // Aciona o buzzer na frequencia relativa ao Fá em Hz
    tone(buzzer,349);    
    delay(2000);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Sol em Hz
    tone(buzzer,392);            
    delay(2000);
    noTone(buzzer); 
}


