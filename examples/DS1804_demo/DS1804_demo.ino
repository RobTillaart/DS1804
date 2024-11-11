//    FILE: DS1804_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/DS1804

#include "DS1804.h"

//  adjust pins if needed
DS1804 ds(5, 6, 7);


void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println(__FILE__);
  Serial.print("DS1804_LIB_VERSION: ");
  Serial.println(DS1804_LIB_VERSION);

  ds.begin();
  ds.select(true);
}


void loop()
{
  if (Serial.available())
  {
    int c = Serial.read();
    if (c == 'T') ds.select(true);
    if (c == 'F') ds.select(false);
    if (c == 'U') ds.moveUp();
    if (c == 'D') ds.moveDown();
  }
}


//  -- END OF FILE --
