#include "EmonLib.h"

// Include Emon Library
EnergyMonitor OUT_V110_1;                   // Create an instance
EnergyMonitor OUT_V110_2;                   // Create an instance
EnergyMonitor OUT_V110_3;                   // Create an instance
EnergyMonitor OUT_V110_4;                   // Create an instance
EnergyMonitor OUT_V110_5;                   // Create an instance
EnergyMonitor IN_V110_1;                   // Create an instance
EnergyMonitor IN_V110_2;                   // Create an instance

void setup()
{  
    Serial.begin(9600);
    OUT_V110_1.current(0, 38);
    OUT_V110_2.current(7, 38);
    OUT_V110_3.current(1, 38);
    OUT_V110_4.current(6, 38);
    OUT_V110_5.current(2, 38);
    IN_V110_1.current(3, 38);
    IN_V110_2.current(5, 38);
}

void loop()
{
  // define emonlib Calculate Irms only
  double OUT_V110_A = OUT_V110_1.calcIrms(1480);  
  double OUT_V110_B = OUT_V110_2.calcIrms(1480);
  double OUT_V110_C = OUT_V110_3.calcIrms(1480);
  double OUT_V110_D = OUT_V110_4.calcIrms(1480);
  double OUT_V110_E = OUT_V110_5.calcIrms(1480); 
  double IN_V110_A = IN_V110_1.calcIrms(1480);
  double IN_V110_B = IN_V110_2.calcIrms(1480);

  // 誤差調整
  IN_V110_A = IN_V110_A * 1.025;
  IN_V110_B = IN_V110_B * 0.975;
  OUT_V110_A = OUT_V110_A * 1.075;
  OUT_V110_B = OUT_V110_B * 0.925;
  OUT_V110_C = OUT_V110_C * 0.975;
  OUT_V110_D = OUT_V110_D * 0.8;
  
  // print out the all current value
  Serial.print("{");
  Serial.print("\"DEVICE\" : \"UPS_B\"");
  Serial.print(", \"IN_V110_A\" : ");
  Serial.print(IN_V110_A);
  Serial.print(", \"IN_V110_B\" : ");
  Serial.print(IN_V110_B);
  Serial.print(", \"OUT_V110_A\" : ");
  Serial.print(OUT_V110_A);
  Serial.print(", \"OUT_V110_B\" : ");
  Serial.print(OUT_V110_B);
  Serial.print(", \"OUT_V110_C\" : ");
  Serial.print(OUT_V110_C);
  Serial.print(", \"OUT_V110_D\" : ");
  Serial.print(OUT_V110_D);
  Serial.print(", \"OUT_V110_E\" : ");
  Serial.print(OUT_V110_E);
  Serial.print("}");
}