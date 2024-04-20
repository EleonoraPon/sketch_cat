#include "FastLED.h"
#include "collectionOfFace.h"
#include "partsOfFace.h"

byte baza = 0;

void loop()
{
  nose();

  if(face_selection == 0)
  {
    umolchanie();
  }
  else if(face_selection == 1)
  {
    tongue();
  }
  else if(face_selection == 2)
  {
    evil();
  }
  else if(face_selection == 3)
  {
    morgaet();
  }

  
}