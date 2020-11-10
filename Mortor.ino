void motorControl(int pwm) {
  analogWrite(motorEn, pwm);
  microgear.chat(DATA_SPEED, pwm);
}
