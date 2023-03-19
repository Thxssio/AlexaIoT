void SendCommand(int Temp, bool Turbo, String Mode, bool Swing, String FanSpeed)
{
  ac.next.protocol = decode_type_t::Protocolo;      //Protocolo
  ac.next.model = 1;
  ac.next.celsius = true;                           //Use Degrees Celsius

  if (FanSpeed == "low")
    ac.next.fanspeed = stdAc::fanspeed_t::kLow;     //Velocidade do Ventilador
  if (FanSpeed == "medium")
    ac.next.fanspeed = stdAc::fanspeed_t::kMedium;
  if (FanSpeed == "high")
    ac.next.fanspeed = stdAc::fanspeed_t::kHigh;

  if (Mode == "Cool")
    ac.next.mode = stdAc::opmode_t::kCool;          //Modo de Operação
  if (Mode == "Dry")
    ac.next.mode = stdAc::opmode_t::kDry;

  if (Swing)
    ac.next.swingv = stdAc::swingv_t::kAuto;        //Movimento das Aletas
  else
    ac.next.swingv = stdAc::swingv_t::kOff;

  ac.next.light = true;                             //Define se as luzes do Aparelho ficam acesas
  ac.next.turbo = Turbo;                            //Turbo ON/OFF
  ac.next.degrees = Temp;                           //Temperaura
  ac.next.power = true;                             //Ligado/Desligado
  ac.next.fanspeed = stdAc::fanspeed_t::kHigh;
  ac.sendAc();                                      //Envia o Comando
}
