#pragma once 

#include <SoftwareSerial.h>               // Подключаем библиотеку SoftwareSerial
#include <DFPlayerMini_Fast.h>            // Подключаем библиотеку DFPlayerMini_Fast

#define NUM_LEDS 256 // количество светодиодов на ленте
#define PIN 13 // порт для подключения ленты

SoftwareSerial mySerial(11, 10);          // Указываем к какими портам подключен DFPlayer
DFPlayerMini_Fast myMP3;                  // Создаем объект 
CRGB leds[NUM_LEDS];

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);

  FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);//основные настройки
  FastLED.setBrightness(40);//яркость (максимальное значение 255)

  mySerial.begin(9600);                   // Открываем последовательную связь
  myMP3.begin(mySerial);                  // инициализация
  myMP3.volume(25);                       // Указываем громкость (0-30)
}

void nose()
{
  leds[120] = CRGB(255, 105, 180);
  leds[119] = CRGB(255, 105, 180);
}

void mouth()
{
  for(int i = 51; i < 89; i++)
  {
    if(i==51 || i==52 || i==53 || i==58 || i==59 || i==60 || i==66 || i==70 || i==73 || i==77 || i==87 || i==88)
     leds[i] = CRGB(10, 30, 255);
  }

}

void littleMouth()
{
  for(int i = 68; i < 92; i++)
  {
    if(i==69 || i==70 || i==73 || i==74 || i==84 || i==87 || i==88 || i==91)
     leds[i] = CRGB(10, 30, 255);
  }
}

void tongueMouth()
{
  littleMouth();
  leds[71] = CRGB(255, 105, 180);
  leds[72] = CRGB(255, 105, 180);
  leds[56] = CRGB(255, 105, 180);
  leds[55] = CRGB(255, 105, 180);

}

void evilMouth()
{
  for(int i = 52; i < 92; i++)
  {
    if(i==53 || i==58 || i==73 || i==70 || i==87 || i==88)
     leds[i] = CRGB(10, 30, 255);
  }  
}

void notMouth()
{
  for(int i = 0; i < 95; i++)
    leds[i] = CRGB(0, 0, 0);
}

void openEye()
{
  for (int i = 131; i < 173; i ++)
  {
    if(i==163 || i==165 || i==156 || i==154 || i==131 || i==133   || i==170 || i==172 || i==149 || i==147 || i==138 || i==140)
      leds[i] = CRGB(175, 238, 238);
    else if(i==164 || i==155 || i==132   || i==171 || i==148 || i==139)
      leds[i] = CRGB(0, 0, 255);
  }

}

void eyeUmolLeft()
{
  for (int i = 131; i < 173; i ++)
  {
    if(i==165 || i==133 || i==154 || i==131 || i==132   || i==172 || i==139 || i==147 || i==138 || i==140)
      leds[i] = CRGB(175, 238, 238);
    else if(i==164 || i==155 || i==156 || i==163    || i==170 || i==171 || i==149 || i==148)
      leds[i] = CRGB(0, 0, 255);
  }
}

void eyeUmolRight()
{
  for (int i = 131; i < 173; i ++)
  {
    if(i==163 || i==133 || i==156 || i==131 || i==132   || i==170 || i==139 || i==149 || i==138 || i==140)
      leds[i] = CRGB(175, 238, 238);
    else if(i==164 || i==155 || i==154 || i==165    || i==172 || i==171 || i==147 || i==148)
      leds[i] = CRGB(0, 0, 255);
  }
}

void closeEye()
{
  for(int i = 131; i < 221; i++)
  {
    if(i==131 || i==132 || i==154 || i==164 || i==188   || i==140 || i==139 || i==149 || i==171 || i==179)
     leds[i] = CRGB(0, 0, 255);
  }
}

void squintEyeRight()   //прищюренные глаза
{
  for (int i = 129; i < 158; i ++)
  {
    if(i==130 || i==131 || i==138 || i==139 || i==148   || i==149 || i==156 || i==157)
      leds[i] = CRGB(175, 238, 238);
    else if(i==132 || i==133 || i==140 || i==141    || i==146 || i==147 || i==154 || i==155)
      leds[i] = CRGB(0, 0, 255);
  }  
}

void squintEyeLeft()   //прищюренные глаза
{
  for (int i = 129; i < 158; i ++)
  {
    if(i==130 || i==131 || i==138 || i==139 || i==148   || i==149 || i==156 || i==157)
      leds[i] = CRGB(0, 0, 255);
    else if(i==132 || i==133 || i==140 || i==141    || i==146 || i==147 || i==154 || i==155)
      leds[i] = CRGB(175, 238, 238);
  }  
}

void sleepEye()
{
  for(int i = 131; i < 221; i++)
  {
    if(i==132 || i==133 || i==138 || i==139 || i==147   || i==150 || i==153 || i==156 || i==162 || i==173)
     leds[i] = CRGB(0, 0, 255);
  }  
}

void notEye()
{
  for(int i = 130; i < 239; i++)
    leds[i] = CRGB(0, 0, 0);
}

int brows(int a)
{
  for(int i = 208; i < 223; i++)
  {
    if(i==211+a || i==212+a || i==213+a || i==218+a || i==219+a || i==220+a)
     leds[i] = CRGB(10, 30, 255);
  }
}

void evilBrows()
{
  leds[201] = CRGB(10, 30, 255);
  leds[198] = CRGB(10, 30, 255);
  leds[213] = CRGB(10, 30, 255);
  leds[218] = CRGB(10, 30, 255);
  leds[228] = CRGB(10, 30, 255);
  leds[235] = CRGB(10, 30, 255);
}

void squintBrowsRight()
{
  leds[186] = CRGB(10, 30, 255);
  leds[187] = CRGB(10, 30, 255);
  leds[194] = CRGB(10, 30, 255);
  leds[195] = CRGB(10, 30, 255);
  leds[201] = CRGB(10, 30, 255);
  leds[202] = CRGB(10, 30, 255);
  leds[211] = CRGB(10, 30, 255);
  leds[212] = CRGB(10, 30, 255);
}

void squintBrowsLeft()
{
  leds[181] = CRGB(10, 30, 255);
  leds[182] = CRGB(10, 30, 255);
  leds[196] = CRGB(10, 30, 255);
  leds[197] = CRGB(10, 30, 255);
  leds[203] = CRGB(10, 30, 255);
  leds[204] = CRGB(10, 30, 255);
  leds[220] = CRGB(10, 30, 255);
  leds[221] = CRGB(10, 30, 255);
}

void sleepBrows()
{
  leds[195] = CRGB(10, 30, 255);
  leds[196] = CRGB(10, 30, 255);
  leds[197] = CRGB(10, 30, 255);
  leds[203] = CRGB(10, 30, 255);
  leds[204] = CRGB(10, 30, 255);
  leds[202] = CRGB(10, 30, 255); 
}







