#include <Arduino.h>
#include <StreamString.h>
#include <IRac.h>
#include <IRsend.h>
#include <IRutils.h>
#include <IRremoteESP8266.h>
#include <ArduinoJson.h>
#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
#ifdef ESP32
#include <WiFi.h>
#endif

#include "SinricPro.h"
#include "SinricProWindowAC.h"

#define WIFI_SSID         "HDSST"
#define WIFI_PASS         "###"
#define APP_KEY           "####"      // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        "####"   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"
#define ACUNIT_ID         "####"    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define BAUD_RATE         115200                     // Change baudrate to your need

#define kIrLed 14         //Pino onde o LED IR está conectado
#define Protocolo GREE   //Substitua pelo Protocolo Obtido no Teste
#define TempMin 16       //Temperatura Mínima do Ar 
#define TempMax 32       //Temperatura Máxima do Ar 

float globalTemperature;
bool globalPowerState = 0;
int globalFanSpeed;

#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 
IRac ac(kIrLed);




int temperature = 16;
String Mode = "Cool"; //Modo de Resfriamento Padrão, para Desumidificador selecionar Modo de Aquecimento 
String FanSpeed = "medium";

void turnOn(String deviceId);
void turnOff(String deviceId);
void SendCommand(int Temp, bool Turbo, String Mode, bool Swing, String FanSpeed);



void setup() {
  pinMode(kIrLed, OUTPUT);
  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");
  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}
