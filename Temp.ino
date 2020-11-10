void findtemp() {
  float temp = dht.readTemperature();
  if ( temp > 0) {
    microgear.chat(DATA_TEMP, temp);
  }
}
