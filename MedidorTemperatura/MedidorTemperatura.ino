#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Sensor DHT22 iniciando...");
}

void loop() {
  delay(2000);

  float temperatura = random(200, 300) / 10.0; // entre 20.0°C e 30.0°C
  float umidade = random(400, 700) / 10.0;     // entre 40.0% e 70.0%

  // float temperatura = dht.readTemperature();
  // float umidade = dht.readHumidity();

  if(isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha ao ler sensor DHT.");

    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  Serial.println();
  delay(2000);
}
