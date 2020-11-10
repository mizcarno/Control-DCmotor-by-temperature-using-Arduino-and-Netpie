void setTime() {
  if (num == 1) {
    microgear.chat(DATA_TIME1, String(OnHour) + " : " + String(OnMinute) + " - " + String(OffHour) + " : " + String(OffMinute));
    OnHour1 = OnHour, OnMinute1 = OnMinute, OffHour1 = OffHour, OffMinute1 = OffMinute;
    Serial.println("Set 1");
    Serial.println(OnHour1);
    Serial.println(OnMinute1);
    Serial.println(OffHour1);
    Serial.println(OffMinute1);
    num += 1;
    count += 1;
  } else if (num == 2) {
    microgear.chat(DATA_TIME2, String(OnHour) + " : " + String(OnMinute) + " - " + String(OffHour) + " : " + String(OffMinute));
    OnHour2 = OnHour, OnMinute2 = OnMinute, OffHour2 = OffHour, OffMinute2 = OffMinute;
    Serial.println("Set 2");
    Serial.println(OnHour2);
    Serial.println(OnMinute2);
    Serial.println(OffHour2);
    Serial.println(OffMinute2);
    num += 1;
  } else if (num == 3) {
    microgear.chat(DATA_TIME3, String(OnHour) + " : " + String(OnMinute) + " - " + String(OffHour) + " : " + String(OffMinute));
    OnHour3 = OnHour, OnMinute3 = OnMinute, OffHour3 = OffHour, OffMinute3 = OffMinute;
    Serial.println("Set 3");
    Serial.println(OnHour3);
    Serial.println(OnMinute3);
    Serial.println(OffHour3);
    Serial.println(OffMinute3);
    num += 1;
  } else if (num == 4) {
    microgear.chat(DATA_TIME4, String(OnHour) + " : " + String(OnMinute) + " - " + String(OffHour) + " : " + String(OffMinute));
    OnHour4 = OnHour, OnMinute4 = OnMinute, OffHour4 = OffHour, OffMinute4 = OffMinute;
    Serial.println("Set 4");
    Serial.println(OnHour4);
    Serial.println(OnMinute4);
    Serial.println(OffHour4);
    Serial.println(OffMinute4);
  }
}
void reTime() {
  microgear.chat(DATA_TIME1, String(0) + " : " + String(0) + " - " + String(0) + " : " + String(0));
  microgear.chat(DATA_TIME2, String(0) + " : " + String(0) + " - " + String(0) + " : " + String(0));
  microgear.chat(DATA_TIME3, String(0) + " : " + String(0) + " - " + String(0) + " : " + String(0));
  microgear.chat(DATA_TIME4, String(0) + " : " + String(0) + " - " + String(0) + " : " + String(0));
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  num = 1;
  count = 0;
  microgear.chat(DATA_RETIME, 0);
}
