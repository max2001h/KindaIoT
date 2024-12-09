#include <KindaIoT.h>

WebServer server(80);

const char* ssid = "WiFiGruglev";
const char* password = "54396654";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  webController();
}

void loop() {
  server.handleClient();
  delay(2);
}
