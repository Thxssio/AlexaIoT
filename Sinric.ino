bool onPowerState(const String &deviceId, bool &state) {

  Serial.printf("Termostato %s em %s\r\n", deviceId.c_str(), state ? "on" : "off");
  globalPowerState = state;
  if (globalPowerState == 1) {

    turnOn(deviceId);
    Serial.println("\n Ligar");
    Serial.print("\n Temperatura: ");
    Serial.println(temperature);
    Serial.print("\n Modo: ");
    Serial.println(Mode);
    Serial.print("\n");
    state == 1;
  }
  if (globalPowerState == 0) {
    turnOff(deviceId);
    Serial.println("\n Desligar \n");
    state == 0;
  }

  return true; // request handled properly
}

bool onTargetTemperature(const String &deviceId, float &temperature) {
  Serial.printf("Thermostat %s set temperature to %f\r\n", deviceId.c_str(), temperature);
  globalTemperature = temperature;


  int temp = globalTemperature;

  if (temp < TempMin)
  {
    SendCommand(TempMin, true, Mode, false, "high");
    temperature = TempMin;
    Serial.print("\n Temperatura: ");
    Serial.println(TempMin);
    Serial.println(" Turbo Ligado ");
    Serial.print("\n");;
  }
  if (temp > TempMax)
  {
    SendCommand(TempMax, true, Mode, false, "high");
    temperature = TempMax;
    Serial.print("\n Temperatura: ");
    Serial.println(TempMax);
    Serial.print("\n");
  }
  if ((temp >= TempMin) && (temp <= TempMax))
  {
    SendCommand(temp, true, Mode, false, "high");
    temperature = temp;
    Serial.print("\n Temperatura: ");
    Serial.println(temp);
    Serial.print("\n");
  }
  return true;
}

bool onAdjustTargetTemperature(const String & deviceId, float &temperatureDelta) {
  globalTemperature += temperatureDelta;  // calculate absolut temperature
  Serial.printf("Thermostat %s changed temperature about %f to %f", deviceId.c_str(), temperatureDelta, globalTemperature);
  temperatureDelta = globalTemperature; // return absolut temperature
  return true;
}

bool onThermostatMode(const String &deviceId, String &mode) {
  Serial.printf("Thermostat %s set to mode %s\r\n", deviceId.c_str(), mode.c_str());
  if (mode == "cool")
  {
    Mode = "Cool";
    SendCommand(temperature, false, Mode, false, "high");
    Serial.println("\n Modo: Resfriamento \n");
  }
  if (mode == "heat")
  {
    Mode = "Dry";
    SendCommand(temperature, false, Mode,  false, "high");
    Serial.println("\n Modo: Desumidificar \n");
  }
  if (mode == "off")
  {
    turnOff(deviceId);
    Serial.println("\n Desligar \n");
  }

 if (mode == "turbo")
{
  Serial.println("\n TESTE FEITO NO SINRIC \n");
}

return true;
}


bool onRangeValue(const String &deviceId, int &rangeValue) {
  Serial.printf("Fan speed set to %d\r\n", rangeValue);
  globalFanSpeed = rangeValue; //NÂO CONCLUIDO
  Serial.println("velocidade");
  return true;
}

bool onAdjustRangeValue(const String &deviceId, int &valueDelta) {
  globalFanSpeed += valueDelta;
  Serial.printf("Fan speed changed about %d to %d\r\n", valueDelta, globalFanSpeed);
  valueDelta = globalFanSpeed;
  Serial.println("ajuste de velocidade");  //NÂO CONCLUIDO
  return true;
}
