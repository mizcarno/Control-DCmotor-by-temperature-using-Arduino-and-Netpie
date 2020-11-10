int controlTemp() {
  if (dht.readTemperature() > setTemp) {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
  } else if (dht.readTemperature() < setTemp) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
  }
  else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);

  }
}


int controlTime() {
  DateTime now = RTC.now();
  if (OnHour1 == now.hour() && OnMinute1 == now.minute()) {
    digitalWrite(motorIn1, HIGH);
  } else if (OffHour1 == now.hour() && OffMinute1 == now.minute()) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  } else if (OnHour2 == now.hour() && OnMinute2 == now.minute()) {
    digitalWrite(motorIn1, HIGH);
  } else if (OffHour2 == now.hour() && OffMinute2 == now.minute()) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  } if (OnHour3 == now.hour() && OnMinute3 == now.minute()) {
    digitalWrite(motorIn1, HIGH);
  } else if (OffHour3 == now.hour() && OffMinute3 == now.minute()) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  } if (OnHour4 == now.hour() && OnMinute4 == now.minute()) {
    digitalWrite(motorIn1, HIGH);
  } else if (OffHour4 == now.hour() && OffMinute4 == now.minute()) {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  }


}
