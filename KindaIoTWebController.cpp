#include <KindaIoT.h>

//Routes
void webController() {
  server.on("/", handleRoot);
  server.on("/api/lights/on", lightsOn);
  server.on("/api/lights/off", lightsOff);
  server.on("/api/fan", setFanSpeed);
  server.on("/api/text", setText);
  server.begin();
}

void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void lightsOn() {
 Serial.println("***lights on***");
}

void lightsOff() {
  Serial.println("***lights off***");
}

void setFanSpeed() {
  if (server.hasArg("speed")) {
    Serial.println("***fan rotation speed changed to " + server.arg("speed") + "***");
  }
}

void setText() {
  if (server.hasArg("text")) {
    Serial.println("***text changed to " + server.arg("text") + "***");
  }
}