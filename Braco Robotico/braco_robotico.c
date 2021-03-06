#include <IRremote.h>

int RECV_PIN = 2;  
float armazenavalor;  
int motorA = 3;  
int motorB = 4; 
int motorC = 6;  
int motorD = 7;
int motorE = 8;  
int motorF = 9;
int motorX = 0;
int motorY = 0;
int motorZ = 0;
int opcao = 0;


IRrecv irrecv(RECV_PIN);  
decode_results resultados;  

void setup()  {  
  pinMode(motorA, OUTPUT); 
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT); 
  pinMode(motorD, OUTPUT);
  pinMode(motorE, OUTPUT); 
  pinMode(motorF, OUTPUT);
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa receptor IR  
}  

void loop()  {  
  if (irrecv.decode(&resultados))  {    
    armazenavalor = (resultados.value);   

    if (armazenavalor == 0xFD08F7){//tecla 1 , motor 1 um lado    
      opcao = 1;
      motorX++;
      Serial.println("Girando braco direita"); 
    }
    if (armazenavalor == 0xFD8877){ //tecla 2, desliga motor
      opcao = 2;
      Serial.println("Parando braco"); 
    }
    if (armazenavalor == 0xFD48B7){ //tecla 3, motor 1 outro lado
      opcao = 3; 
      motorX--;
      Serial.println("Girando braco para esquerda"); 
    }
    if (armazenavalor == 0xFD28D7){//tecla 4, motor 2 um lado
      opcao = 4;
      motorY++;
      Serial.println("Movendo braco frente");
    }
    if (armazenavalor == 0xFDA857){ //tecla 5, desliga motor 2  
      opcao = 5; 
      Serial.println("Parando braco"); 
    }
    if (armazenavalor == 0xFD6897){ //tecla 6, motor 2 outro lado  
      opcao = 6;
      motorY--;
      Serial.println("Movento braco para trás");
    }
    if (armazenavalor == 0xFD18E7){//tecla 7, motor 3 um lado  
      opcao = 7;
      motorZ++;
      Serial.println("Movendo braco cima");
    }
    if (armazenavalor == 0xFD9867){ //tecla 8 desliga motor 2
      opcao = 8; 
      Serial.println("Prando braco.");  
    }
    if (armazenavalor == 0xFD58A7){ //tecla 9 motor 3 outro lado  
      opcao = 9;
      motorZ--;
      Serial.println("Movendo braco baixo");  
    }
    irrecv.resume(); //Le o próximo valor  
  }  

  switch(opcao){//muda opções
    case 1:
    if(giraMotor(motorX, motorA) > 0){//Verifica se dá pra girar ou já chegou no limite do braço
      digitalWrite(motorA, HIGH);   
      digitalWrite(motorB, LOW); 
      motorX++;
    }
    break;
    case 2:
    digitalWrite(motorA, LOW);   
    digitalWrite(motorB, LOW); 
    break;
    case 3:
    if(giraMotor(motorX, motorB) >0){
      digitalWrite(motorA, LOW);   
      digitalWrite(motorB, HIGH); 
      motorX--;
    }
    break;
    case 4:
    if(giraMotor(motorY, motorC)>0){
      digitalWrite(motorC, HIGH);   
      digitalWrite(motorD, LOW); 
      motorY++;
    }
    break;
    case 5:
    digitalWrite(motorC, LOW);   
    digitalWrite(motorD, LOW); 
    break;
    case 6:
    if(giraMotor(motorY, motorD)>0){
      digitalWrite(motorC, LOW);   
      digitalWrite(motorD, HIGH);   
      motorY--;
    }   
    break;
    case 7:
    if(giraMotor(motorZ, motorE)>0){
      digitalWrite(motorE, HIGH);   
      digitalWrite(motorF, LOW);  
      motorZ++;
    }
    break;
    case 8:
    digitalWrite(motorE, LOW);   
    digitalWrite(motorF, LOW); 
    break;
    case 9:
    if(giraMotor(motorZ, motorF)>0){
      digitalWrite(motorE, LOW);   
      digitalWrite(motorF, HIGH);  
      motorZ--;
    }
    break;
  }

}

int giraMotor(int eixo_motor, int motor){
  Serial.println(eixo_motor);
  if(eixo_motor >= 150 || eixo_motor <= -150){
    digitalWrite(motor, LOW);
    return 0;
  }
  else{
    return 1;
  }
}