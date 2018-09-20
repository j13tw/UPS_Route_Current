#include "EmonLib.h"

// Include Emon Library
EnergyMonitor V110_1;                   // Create an instance
EnergyMonitor V110_2;                   // Create an instance
EnergyMonitor V110_3;                   // Create an instance
EnergyMonitor V110_4;                   // Create an instance
EnergyMonitor V110_5;                   // Create an instance
EnergyMonitor V220_1;                   // Create an instance
EnergyMonitor V220_2;                   // Create an instance

void setup()
{  
    Serial.begin(9600);
    V110_1.current(0, 38);
    V110_2.current(1, 38);
    V110_3.current(2, 38);
    V110_4.current(4, 38);
    V110_5.current(5, 38);
    V220_1.current(6, 38);
    V220_2.current(7, 38);
}

void loop()
{
  // define emonlib Calculate Irms only
  double V110_A = V110_1.calcIrms(1480);  
  double V110_B = V110_2.calcIrms(1480);
  double V110_C = V110_3.calcIrms(1480);
  double V110_D = V110_4.calcIrms(1480);
  double V110_E = V110_5.calcIrms(1480); 
  double V220_A = V220_1.calcIrms(1480);
  double V220_B = V220_2.calcIrms(1480);

  if (V110_A > 0.08) V110_A = V110_A - 0.08;
  if (V110_B > 0.08) V110_B = V110_B - 0.08;
  if (V110_C > 0.08) V110_C = V110_C - 0.08;
  if (V110_D > 0.08) V110_D = V110_D - 0.08;
  if (V110_E > 0.08) V110_E = V110_E - 0.08;
  if (V220_A > 0.08) V220_A = V220_A - 0.08;
  if (V220_B > 0.08) V220_B = V220_B - 0.08;
  
  // print out the all current value
  Serial.print("{");
  Serial.print("\"V110_A\" : ");
  Serial.print(V110_A);
  Serial.print(", \"V110_B\" : ");
  Serial.print(V110_B);
  Serial.print(", \"V110_C\" : ");
  Serial.print(V110_C);
  Serial.print(", \"V110_D\" : ");
  Serial.print(V110_D);
  Serial.print(", \"V220_E\" : ");
  Serial.print(V110_E);
  Serial.print(", \"V220_A\" : ");
  Serial.print(V220_A);
  Serial.print(", \"V220_B\" : ");
  Serial.print(V220_B);
  Serial.print("}");
}
