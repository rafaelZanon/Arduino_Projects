#include<Servo.h>
#define sPin 3 //define qual o pino será utilizado 
#define bPin 6 // define botao

Servo servo1;
int valor = 0;
int pos = 0;
int posIn = 0;
int direcao = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Iniciando o uso do servo");
  
  //conectar pino a classe do servo
  servo1.attach(sPin);
  servo1.write(0);
  pinMode(bPin, INPUT);

}

void loop() {

  if (digitalRead(bPin) == 0)
  {
    while(digitalRead(bPin) == 0);
    Serial.println("Botao Pressionado");
    if(valor == 0)
      valor = 1;
    else 
      valor = 0;
  }

    
    if(valor == 0){
      posIn = pos;
      if(pos >= 120)
         direcao = 1;
      if (pos <= 0)
         direcao = 0;
      if (direcao == 0){
         pos = pos + 30;

        for(int i = posIn; i <=pos; i ++){
          servo1.write(i);
          delay(10);
        }
      }
      if (direcao == 1){
         pos = pos - 30;
         
        for(int i = posIn; i >=pos; i --){
          servo1.write(i);
          delay(10);
         
      }
    }
      servo1.write(pos);
      valor=1;
      Serial.println(pos);
    } 
  


}
