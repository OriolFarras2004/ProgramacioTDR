#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(2,3);

Servo servothumb;
Servo servoindex;
Servo servomajeure;
Servo servoringfinger;
Servo servopinky;

char dato;
String msg = "";

byte i;

void setup() {
  
  servothumb.attach(12);
  servoindex.attach(11);
  servomajeure.attach(10);
  servoringfinger.attach(9);
  servopinky.attach(8);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {

    if (mySerial.available() > 0){
  
    for (int i = 0; i < 5; i++) {
        dato = mySerial.read();
        Serial.println(dato);
        msg = msg + dato;
      
    }
    Serial.println(msg);
    }
  
  for(i=0; i<5; i++){
    
    comprovacio(0, servothumb, 0, 90);
    comprovacio(1, servoindex, 180, 90);
    comprovacio(2, servomajeure, 0, 90);
    comprovacio(3, servoringfinger, 180, 90);
    comprovacio(4, servopinky, 180, 90);
   }

  msg = "";
  delay(500);

}

void comprovacio(int num, Servo servo, int val1, int val2){
  
    if(i == num && msg[num] == '0'){
        servo.write(val1);  
    }

    if(i == num && msg    [num] == '1'){
        servo.write(val2);    
    }
}
