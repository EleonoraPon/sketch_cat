#pragma once
#include "partsOfFace.h"

int face_selection = 0;

bool isPressed()
{
  if(digitalRead(3))//==1
  {
    while(digitalRead(3));//без этой строчки спамит 1
    face_selection = random(1, 5);//0 занят лицом по умолчанию
    return true;
  }
  return false;
}

bool mdelay(int ms)
{
  for(int i=0;i<ms;i++)
  {
    if(isPressed())
    {
      Serial.println(1);
      return true;
    }
    delay(1);
  }
  return false;
}

void umolchanie()
{
  notEye();
  notMouth();
  myMP3.play(5);
    //nose();
  littleMouth();
  for(int i = 0; i < 3; i++)
  {
    eyeUmolLeft();
    brows(-1);
    FastLED.show();
    if(mdelay(800))
      return;

    notEye();
    FastLED.show();
    if(mdelay(5))
      return;

    eyeUmolRight();
    brows(1);
    FastLED.show();
    if(mdelay(800))
      return;

    notEye();
    FastLED.show();
    if(mdelay(5))
      return;
  }
  closeEye();
  FastLED.show();
  if(mdelay(350))
      return;

  notEye();
  FastLED.show();
  if(mdelay(5))
      return;

}

void tongue()
{
  myMP3.play(1);
  delay(10);
  notEye();
  notMouth();
  delay(10);

  

  tongueMouth();
  closeEye();
  FastLED.show();
  delay(1000);
  //notMouth();
  face_selection = 0;
}

void evil()
{
  myMP3.play(2);
  delay(10);
  notEye();
  notMouth();
  delay(10);

  //mouth();
  evilMouth();
  openEye();
  evilBrows();
  FastLED.show();
  delay(1000);

  //notMouth();
  face_selection = 0;
}

void squint()
{
  myMP3.play(4);
  delay(10);
  notEye();
  notMouth();
  delay(10);

  mouth();
  for(int i = 0; i < 2; i++)
  {
    squintEyeRight();
    squintBrowsRight();
    FastLED.show();
    delay(700);
    
    notEye();
    FastLED.show();
    delay(5);

    squintEyeLeft();
    squintBrowsLeft();
    FastLED.show();
    delay(700);

    notEye();
    FastLED.show();
    delay(5);

  }

  notEye();
  FastLED.show();
  delay(5);

  face_selection = 0;
}

void sleep()
{
  myMP3.play(3);
  delay(10);
  notEye();
  notMouth();
  delay(10);

  littleMouth();
  sleepEye();
  sleepBrows();

  FastLED.show();
  delay(3000);

  //notMouth();
  face_selection = 0;
}

void morgaet()
{
  notEye();
  notMouth();
  delay(10);

  //nose();
  mouth();
  openEye();
  FastLED.show();
  delay(800);

  notEye();
  FastLED.show();
  delay(5);

  closeEye();
  FastLED.show();
  delay(700);

  notEye();
  FastLED.show();
  delay(5);

  //notMouth();
  face_selection = 0;
}
