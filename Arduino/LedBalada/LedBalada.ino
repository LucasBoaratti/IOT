//UC_IOT_AULA2_Prática2 - Ligar Led com pulso no pino D15
//Recursos KIT ESP32 / Resistor / Led
//PROGRAMA 2 : PISCA PISCA

const int ledPin = 15; //PINO D15

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //Define o PINO do LED como saída
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH); //Liga o LED
  delay(1000); //Alterar o valor dessa variavel muda o tempo de duração em MILISEGUNDOS que o led permanece LIGADO.
  digitalWrite(ledPin, LOW);  //Desliga o LED
  delay(1000); //Alterar o valor dessa variavel muda o tempo de duração em MILISEGUNDOS que o led permanece DESLIGADO.
}

//const int -> declara uma variavel apenas uma vez e a partir daquele momento ela se torna fixa.
//int -> por sua vez quando utilizar somente o "int" é declarada uma variavel inteira que a qualquer momento do código pode ser alterada.