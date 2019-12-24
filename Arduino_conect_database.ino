#include <ESP8266WiFi.h>           // Use this for WiFi instead of Ethernet.h
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

WiFiClient client;
const IPAddress server(192,168,43,37);
const int httpPort = 3306;
const char* ssid = "sohit";
const char* password =  "bukasandi";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booted");
  Serial.println("Connecting to Wi-Fi");
  WiFi.begin (ssid, password);
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    yield();
  }
  Serial.println("WiFi connected");
  if (client.connect(server,httpPort )) {
    Serial.println("Client Connected");
  } else {
    Serial.println("No Connection");
  }
}

void loop() {
}
