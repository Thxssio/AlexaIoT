void turnOn(String deviceId)
{
  if (deviceId == ACUNIT_ID)
  {
    Serial.print("Ligar o dispositivo ID: ");
    Serial.println(deviceId);

    SendCommand(temperature, true, Mode, true, "high");

  }
}

void turnOff(String deviceId)
{
  if (deviceId == ACUNIT_ID)
  {
    Serial.print("Desligar o dispositivo ID: ");
    Serial.println(deviceId);

    ac.next.power = false;
    ac.sendAc();
  }
}
