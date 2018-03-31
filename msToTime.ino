#include <Arduino.h>

String msToTime(long dauer) {

  long hours = dauer / 3600000;
  long minutes = (dauer/60000)%60;
  long seconds = (dauer/1000)%60;

  String h;

  if(hours == 0 ){
    h = " 0";
  }else{
    h = (hours < 10 ? String("0") + hours : hours);
  }
  String m = (minutes < 10 ? String("0") + minutes : minutes);
  String s = (seconds < 10 ? String("0") + seconds : seconds);

  return String(h) + ":" + String(m) + ":" + String(s);
}

