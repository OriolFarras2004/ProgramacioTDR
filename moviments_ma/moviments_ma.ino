#include <Servo.h>

Servo servothumb;
Servo servoindex;
Servo servomajeure;
Servo servoringfinger;
Servo servopinky;

int boto1 = 4;
int boto2 = 13;

int cont = 0;
int cont2 = 0;

void setup() {
  
  servothumb.attach(12);
  servoindex.attach(11);
  servomajeure.attach(10);
  servoringfinger.attach(9);
  servopinky.attach(8);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(boto1, INPUT);
  pinMode(boto2, INPUT);

  obrirMa();
}

void Color(int R, int G, int B){     
  analogWrite(5 , R);   
  analogWrite(6, G);   
  analogWrite(7, B);   
}

void obrirMa(){
  servothumb.write(90);
  servoindex.write(90);
  servomajeure.write(90);
  servoringfinger.write(90);
  servopinky.write(90);
}

void loop() {

  int valorBoto1 = digitalRead(boto1);
  int valorBoto2 = digitalRead(boto2);

  if(valorBoto1 == HIGH){

    if(cont == 0){
      Color(255 ,0 ,0);
      cont = 1;
    }
    else{
      
      if(cont == 1){
        Color(0 ,255 ,0);
        cont = 2;
      }
      else{
        if(cont == 2){
          Color(0 ,0 ,255);
          cont = 0;
        }
      }
    }
    delay(250);
  }

  if(valorBoto2 == HIGH){

    if(cont == 0){
      if(cont2 == 0){
        servothumb.write(0);
        servoindex.write(180);
        servomajeure.write(90);
        servoringfinger.write(90);
        servopinky.write(90);
        cont2 = 1;
      }else{
        obrirMa();
        cont2 = 0;  
      }

    }else{
      if(cont == 1){
        if(cont2 == 0){
          
          servothumb.write(0);
          servoindex.write(180);
          servomajeure.write(0);
          servoringfinger.write(180);
          servopinky.write(180);
          
          cont2 = 1;
        }else{
          obrirMa();
          cont2 = 0;  
        }
      }else{
        if(cont == 2){

          if(cont2 == 0){
            servothumb.write(90);
            servoindex.write(180);
            servomajeure.write(0);
            servoringfinger.write(180);
            servopinky.write(180);
            cont2 = 1;
          }else{
            obrirMa();
            cont2 = 0;  
          } 
        }  
      }  
    }
   delay(250); 
  }

}
