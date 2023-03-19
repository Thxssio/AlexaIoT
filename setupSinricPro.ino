void setupSinricPro() {
  SinricProWindowAC &myAcUnit = SinricPro[ACUNIT_ID];
  myAcUnit.onPowerState(onPowerState);
  myAcUnit.onTargetTemperature(onTargetTemperature);
  myAcUnit.onAdjustTargetTemperature(onAdjustTargetTemperature);
  myAcUnit.onThermostatMode(onThermostatMode);
  myAcUnit.onRangeValue(onRangeValue);
  myAcUnit.onAdjustRangeValue(onAdjustRangeValue);

  // setup SinricPro
  SinricPro.onConnected([]() {
    Serial.printf("Connected to SinricPro\r\n");
  });
  SinricPro.onDisconnected([]() {
    Serial.printf("Disconnected from SinricPro\r\n");
  });
  SinricPro.begin(APP_KEY, APP_SECRET);
}
