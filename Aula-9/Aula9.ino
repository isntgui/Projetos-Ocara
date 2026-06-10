#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHTPIN 2       // pino do DHT11
#define DHTTYPE DHT11
#define LEDPIN 4       // pino do LED

const char* ssid = "I4"; // nome da rede
const char* password = "I4emssocara@nov2023"; // senha da rede

ESP8266WebServer server(80);
DHT dht(DHTPIN, DHTTYPE);

bool ledState = false;

void setup() {

  Serial.begin(115200);

  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  dht.begin();

  WiFi.begin(ssid, password);

  Serial.print("Conectando");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println(WiFi.localIP());

  // rota para enviar dados
  server.on("/get", handleData);

  // rota para controlar LED
  server.on("/led", handleLED);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleData() {

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade)) {
    server.send(200, "application/json", "{\"erro\":\"falha sensor\"}");
    return;
  }

  String json = "{";
  json += "\"temperatura\":" + String(temperatura) + ",";
  json += "\"umidade\":" + String(umidade) + ",";
  json += "\"led\":" + String(ledState ? 1 : 0);
  json += "}";

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

void handleLED() {

  if (server.hasArg("valor")) {

    String valor = server.arg("valor");

    if (valor == "1") {
      digitalWrite(LEDPIN, HIGH);
      ledState = true;
    } 
    else {
      digitalWrite(LEDPIN, LOW);
      ledState = false;
    }
  }

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "OK");
}
