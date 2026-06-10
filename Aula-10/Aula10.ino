#include <ESP8266WiFi.h> // Para ESP8266
#include <PubSubClient.h>
#include <DHT.h>

// --- Configurações Wi-Fi ---
const char* ssid = "I4";
const char* password = "I4emssocara@nov2023";

// --- Configurações MQTT ---
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* clientID = "Esp8266";

// --- Tópicos MQTT ---
const char* topico_led = "comando/led";
const char* topico_temperatura = "comando/Temperatura";
const char* topico_umidade = "comando/Umidade";

// --- Pinos ---
#define LED_PIN 4 //D2
#define DHTPIN 12 //D6
#define DHTTYPE DHT11

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

// --- Setup ---
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");

  // Configurar MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

// --- Callback para mensagens MQTT recebidas ---
void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem;
  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  Serial.print("Mensagem recebida em ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(mensagem);

  // Controle do LED
  if (String(topic) == topico_led) {
    if (mensagem == "1") {
      digitalWrite(LED_PIN, HIGH);
    } else if (mensagem == "0") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

// --- Reconnect MQTT ---
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect(clientID)) {
      Serial.println("Conectado!");
      client.subscribe(topico_led);
    } else {
      Serial.print("Falhou. Código: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

// --- Loop principal ---
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Enviar dados do DHT11 a cada 1 segundos
  static unsigned long lastSend = 0;
  if (millis() - lastSend > 1000) {
    lastSend = millis();

    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    if (!isnan(temperatura)) {
      client.publish(topico_temperatura, String(temperatura).c_str(), true);
      Serial.print("Temperatura: ");
      Serial.println(temperatura);
    }
    if (!isnan(umidade)) {
      client.publish(topico_umidade, String(umidade).c_str(), true);
      Serial.print("Umidade: ");
      Serial.println(umidade);
    }
  }
}
