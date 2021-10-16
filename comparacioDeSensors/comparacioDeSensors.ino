const int analogPin2 = A2;

int value1;
int posicio1;

void setup() {

  Serial.begin(9600);
  pinMode(analogPin2,INPUT);
  

}

void loop() {
  
  int posicioInicial2 = analogRead(analogPin2);
  int valorInicial2 = posicioInicial2;

  Serial.println(valorInicial2);

  delay(100);
}
