/*Criado por Rafael Zanon RA:21113
Aluno Cotuca*/

#include <LiquidCrystal.h>
//Define Lcd

LiquidCrystal lcd (12, 11, 7, 6, 5, 4);
String txt = "RA: 21113";
String temps = "";


void setup()
{//inicia Serial + o lcd
	Serial.begin(9600);
	lcd.begin(16,2);
}

void loop()
{ 
  
  /*Logica para a conta de temperatura
  
  Regra de 3, multiplicando a informação que esta entrando
  na porta 'A0' por 5 dividindo por 1023, fazendo isso nós temos
  a informação da variação da tensão na entrada do arduino
  
  depois nós fazemos a tensão - 0.5 e multiplicamos por 100
  e printamos no Serial, função 'Round' foi usado para arredondar 
  o numero da temperatura*/
  
  
  float tensao = analogRead(A0)*5.0/1023;
  int temp = round ((tensao-.5)*100);
  Serial.println(temp);
  
  //Fazendo os prints
  temps.concat("Temp: ");
  temps.concat(temp);

  //definindo colunas e linhas do lcd
  
 lcd.setCursor(0, 0);
 lcd.print(temps);
 lcd.setCursor(0, 1);
 lcd.print(txt); 

  //delay de 1 segundo na porta serial
 delay(1000);
 temps = "";
 lcd.clear();
 
}