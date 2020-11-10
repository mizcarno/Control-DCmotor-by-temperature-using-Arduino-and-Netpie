/*  NETPIE ESP8266 basic sample                            */
/*  More information visit : https://netpie.io             */

#include <ESP8266WiFi.h>
#include <MicroGear.h>
#include "DHT.h"
#include <Wire.h>
#include <SPI.h>
#include "RTClib.h"

RTC_DS1307 RTC;

const char* ssid     = "MEK_WiFi";
const char* password = "11111111";

#define APPID   "MCUTESTRmuti"
#define KEY     "kILajp3n1KySTBq"
#define SECRET  "1S5jXuDXnat3BhqTHSgrs6d8H"
#define ALIAS   "MyNodeMCU"

#define DATA_TEMP "data/temp"
#define DATA_RPM "data/rpm"
#define DATA_SPEED "data/speed"
#define DATA_TIME   "/data/time"
#define DATA_TIME1   "/data/time1"
#define DATA_TIME2   "/data/time2"
#define DATA_TIME3   "/data/time3"
#define DATA_TIME4   "/data/time4"
#define DATA_RETIME   "/data/retime"




#define DHTPIN D5
#define DHTTYPE DHT11

#define motorIn1 D7
#define motorIn2 D6
#define motorEn D3

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

int timer = 0, pwm = 0 , numPwm = 0 , setTemp = 0, num = 1, count = 0, OnHour = 0, OnMinute = 0, OffHour = 0, OffMinute = 0;
int OnHour1 = 0, OnMinute1 = 0, OffHour1 = 0, OffMinute1 = 0;
int OnHour2 = 0, OnMinute2 = 0, OffHour2 = 0, OffMinute2 = 0;
int OnHour3 = 0, OnMinute3 = 0, OffHour3 = 0, OffMinute3 = 0;
int OnHour4 = 0, OnMinute4 = 0, OffHour4 = 0, OffMinute4 = 0;
float temp;
String mStr, msgAll, msgPwm, msgSt, mStrOnH, mStrOnM, mStrOffH, mStrOffM;



MicroGear microgear(client);


void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
  Serial.print("Incoming message --> ");
  msg[msglen] = '\0';

  mStr = String((char *)msg);

  msgAll = mStr.substring(0, 2);

  if (msgAll == "pw") {
    msgPwm = mStr.substring(2, 6);

  } else if (msgAll == "st") {
    msgSt = mStr.substring(2, 5);

  } else if (msgAll == "oh") {
    mStrOnH = mStr.substring(2, 4);

  } else if (msgAll == "om") {
    mStrOnM = mStr.substring(2, 4);

  } else if (msgAll == "fh") {
    mStrOffH = mStr.substring(2, 4);

  } else if (msgAll == "fm") {
    mStrOffM = mStr.substring(2, 4);

  } else if (msgAll == "ts") {
    setTime();
  } else if (msgAll == "rt") {
    reTime();
  }

  OnHour = mStrOnH.toInt();
  OnMinute = mStrOnM.toInt();
  OffHour = mStrOffH.toInt();
  OffMinute = mStrOffM.toInt();

  numPwm = ((msgPwm.toInt() * 623) / 100) + 400;

  setTemp = msgSt.toInt();

}

void onFoundgear(char *attribute, uint8_t* msg, unsigned int msglen) {
  Serial.print("Found new member --> ");
  for (int i = 0; i < msglen; i++)
    Serial.print((char)msg[i]);
  Serial.println();
}

void onLostgear(char *attribute, uint8_t* msg, unsigned int msglen) {
  Serial.print("Lost member --> ");
  for (int i = 0; i < msglen; i++)
    Serial.print((char)msg[i]);
  Serial.println();
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
  Serial.println("Connected to NETPIE...");
  microgear.setAlias(ALIAS);
}


void setup() {

  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));

  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorEn, OUTPUT);

  microgear.on(MESSAGE, onMsghandler);
  microgear.on(PRESENT, onFoundgear);
  microgear.on(ABSENT, onLostgear);
  microgear.on(CONNECTED, onConnected);

  Serial.begin(115200);
  Serial.println("Starting...");

  dht.begin();

  if (WiFi.begin(ssid, password)) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  microgear.init(KEY, SECRET, ALIAS);

  microgear.connect(APPID);
}

void loop() {
  DateTime now = RTC.now();

  microgear.loop();
  findtemp();
  motorControl(numPwm);

  timeFind();

  if (count == 0) {
    controlTemp();


  } else {
    controlTime();
    numPwm = 1023;
  }

  delay(1000);
}
