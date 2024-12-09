#ifndef MY_WEB_CONTROLLER_H
#define MY_WEB_CONTROLLER_H

#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>

extern WebServer server;
extern const char* htmlPage;

void webController();
void handleRoot();
void lightsOn();
void lightsOff();
void setFanSpeed();
void setText();

#endif