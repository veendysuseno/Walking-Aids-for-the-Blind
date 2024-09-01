#include <HCSR04.h>     //Library HCSR-04
HCSR04 hc(5,6);         //initialisation class HCSR04 (trig pin , echo pin)

#define buzzer 13

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int jarak = hc.dist();      //Baca jarak
  if(jarak > 100){            //Jika jarak > 100 cm
    jarak = 100;
  }
  else if(jarak < 0){         //Antisipasi error pembacaan jika < 0 cm
    jarak = 100;
  }

  jarak = jarak * 30;         //Pengaturan delay off
  
  digitalWrite(buzzer, HIGH);
  delay(125);
  digitalWrite(buzzer, LOW);
  delay(jarak);
}
