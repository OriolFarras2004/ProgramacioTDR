#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);

const int analogPin1 = A4;
const int analogPin2 = A3;
const int analogPin3 = A2;
const int analogPin4 = A1;
const int analogPin5 = A0;

const int boto = 11;

int value1;
int posicio1;

int value2;
int posicio2;

int value3;
int posicio3;

int value4;
int posicio4;

int value5;
int posicio5;

bool ficomprovacio1 = false;
bool ficomprovacio2 = false;

int posicioInicial1;
int posicioInicial2;
int posicioInicial3;
int posicioInicial4;
int posicioInicial5;

int valorInicial1;
int valorInicial2;
int valorInicial3;
int valorInicial4;
int valorInicial5;

int posicioFinal1;
int posicioFinal2;
int posicioFinal3;
int posicioFinal4;
int posicioFinal5;

int valorFinal1;
int valorFinal2;
int valorFinal3;
int valorFinal4;
int valorFinal5;

char enviar1;
char enviar2;
char enviar3;
char enviar4;
char enviar5;

void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(analogPin1,INPUT);
  pinMode(analogPin2,INPUT);
  pinMode(analogPin3,INPUT);
  pinMode(analogPin4,INPUT);
  pinMode(analogPin5,INPUT);

  pinMode(boto, INPUT);  
}

void loop() {

   int estat = digitalRead(boto);
   while(estat!=HIGH && ficomprovacio1 != true){
     Serial.println("Obra la ma i apreta el boto");
     estat = digitalRead(boto);
   }
   if(ficomprovacio1 == false){
     int posicioInicial1 = analogRead(analogPin1);
     int posicioInicial2 = analogRead(analogPin2);
     int posicioInicial3 = analogRead(analogPin3);
     int posicioInicial4 = analogRead(analogPin4);
     int posicioInicial5 = analogRead(analogPin5);
     Serial.println(posicioInicial1);
     delay(1000);
     valorInicial1 = posicioInicial1;
     valorInicial2 = posicioInicial2;
     valorInicial3 = posicioInicial3;
     valorInicial4 = posicioInicial4;
     valorInicial5 = posicioInicial5;
     
     delay(1000);
   }
   ficomprovacio1 = true;

   
   estat = digitalRead(boto);
   while(estat!=HIGH && ficomprovacio2 != true){
     Serial.println("Tanca la ma i apreta el boto");
     estat = digitalRead(boto);
   }
   if(ficomprovacio2 == false){
     int posicioFinal1 = analogRead(analogPin1);
     int posicioFinal2 = analogRead(analogPin2);
     int posicioFinal3 = analogRead(analogPin3);
     int posicioFinal4 = analogRead(analogPin4);
     int posicioFinal5 = analogRead(analogPin5);
     Serial.println(posicioFinal1);
     delay(1000);
     valorFinal1 = posicioFinal1;
     valorFinal2 = posicioFinal2;
     valorFinal3 = posicioFinal3;
     valorFinal4 = posicioFinal4;
     valorFinal5 = posicioFinal5;
     delay(1000);

 
   }
   ficomprovacio2 = true;

  // Serial.println(valorInicial1);
   //Serial.println(valorFinal1);


/*
+--------------+
|   ENVIAR     |
+--------------+
|  OBERT = 1   |
|  TANCAT = 0  |
+--------------+
*/
   

  // sensor 1
    
  value1 = analogRead(analogPin1);
  posicio1 = value1;
  if (posicio1 > (valorFinal1 / 2)) {
  
  //Serial.println("TANCAT");
  enviar1 = '0';
  
  }
  else{
  //Serial.println("OBERT");
  enviar1 = '1';
  }
  
  // sensor 2
  
  value2 = analogRead(analogPin2);
  posicio2 = value2;
  if (posicio2 > (valorFinal2 / 2)) {
  
  //Serial.println("TANCAT");
  enviar2 = '0';
  
  }
  else{
  //Serial.println("OBERT");
  enviar2 = '1';
  }
  
  // sensor 3
  
  value3 = analogRead(analogPin3);
  posicio3 = value3;
  if (posicio3 > (valorFinal3 / 2)) {
  
  //Serial.println("TANCAT");
  enviar3 = '0';
  
  }
  else{
    //Serial.println("OBERT");
    enviar3 = '1';
  }
  
  // sensor 4
  
  value4 = analogRead(analogPin4);
  posicio4 = value4;
  if (posicio4 > (valorFinal4 / 2)) {
  
  //Serial.println("TANCAT");
  enviar4 = '0';
  
  }
  else{
  //Serial.println("OBERT");
  enviar4 = '1';
  }
  
  // sensor 5
  
  value5 = analogRead(analogPin5);
  posicio5 = value5;
  if (posicio5 > (valorFinal5 / 2)) {
  
  //Serial.println("TANCAT");
  enviar5 = '0';
  
  }
  else{
  //Serial.println("OBERT");
  enviar5 = '1';
  }

  // IMPRIMIR VALORS PER LA CONSOLA

String paquet = String(enviar1) + String(enviar2) + String(enviar3) + String(enviar4) + String(enviar5);

Serial.println(paquet);

//Serial.println(paquet);

mySerial.write(char(enviar1));
delay(50);
mySerial.write(char(enviar2));
delay(50);
mySerial.write(char(enviar3));
delay(50);
mySerial.write(char(enviar4));
delay(50);
mySerial.write(char(enviar5));
delay(50);


delay(500);

}

/*
  Serial.print(enviar1);
  Serial.print("    ");

  Serial.print(enviar2);
  Serial.print("    ");

  Serial.print(enviar3);
  Serial.print("    ");

  Serial.print(enviar4);
  Serial.print("    ");

  Serial.print(enviar5);
  Serial.println("    ");
}
*/


// ===============

//sensor A0 (SI)
//sensor A1 (si)
//sensor A2 (SI)
//sensor A3 (SI)
//sensor A4 (SI)


   
