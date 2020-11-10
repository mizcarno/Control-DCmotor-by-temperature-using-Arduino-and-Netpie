void timeFind() {
  DateTime now = RTC.now();

  Serial.println(now.hour(), DEC);
  Serial.print(':');
  Serial.println(now.minute(), DEC);

  microgear.chat(DATA_TIME, String(now.hour()) + " : " + String(now.minute()));

  delay(1000);
}
