#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
 
//Enter network credentials:
const char* ssid = "redesiot";
const char* password = "a1234567";
 
//Enter Google Script Deployment ID:
const char* GScriptId = "AKfycby9ABPLoiuWLvoqcScrpNlc0uo-KkZjiHTjkRCQk9nJW4vldCG9Us6iLi1Llse4Vx-VZQ";
 
//Enter command (insert_row or append_row) and your Google Sheets sheet name (default is sheet1):
String url = "https://script.google.com/macros/s/" + String(GScriptId) + "/exec";
 
//Google Sheets setup (do not edit)
const char* host = "script.google.com";
const int httpsPort = 443;
const char* fingerprint = "";

String nomes[] = {
  "Lucas",
  "Duda",
};

WiFiClientSecure client;
 
void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println('\n');
 
  //Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  Serial.print(ssid);
  Serial.println(" ...");
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println('\n');
  Serial.println("Conectado ao Wi-Fi!");
  Serial.print("Endereço IP: \t");
  Serial.println(WiFi.localIP());
 
  client.setInsecure();
}
 
 
void loop() {
  String esteira1 = nomes[random(0, 2)];
  String esteira2 = nomes[random(0, 2)];
  String esteira3 = nomes[random(0, 2)];

  String payload = "{\"command\": \"insert_row\", \"sheet_name\": \"Sheet1\", \"values\": \"" + esteira1 + "," + esteira2 + "," + esteira3 + "\"}";
 
  HTTPClient https;
  https.begin(client, url);
  https.addHeader("Content-Type", "application/json");

  Serial.println("Enviando dados...");
  Serial.println(payload);

  int httpCode = https.POST(payload);

  if (httpCode > 0) {
    Serial.print("Código de resposta: ");
    Serial.println(httpCode);
    String resposta = https.getString();
    Serial.println("Resposta do servidor:");
    Serial.println(resposta);
  } else {
    Serial.print("Erro na requisição: ");
    Serial.println(httpCode);
  }

  https.end();
  delay(5000);
}
