#include "FastLED.h"

byte baza = 0;

#define NUM_LEDS 256 // количество светодиодов на ленте
#define PIN 13 // порт для подключения ленты
CRGB leds[NUM_LEDS];

int face_selection = 0;


void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);

  FastLED.addLeds <WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);//основные настройки
  FastLED.setBrightness(20);//яркость (максимальное значение 255)
}

bool isPressed()
{
  if(digitalRead(3))//==1
  {
    while(digitalRead(3));//без этой строчки спамит 1
    face_selection = random(1, 3);//0 занят другими лицами
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
      leds[i] = CRGB(40, 100, 255);
    else if(i==164 || i==155 || i==132   || i==171 || i==148 || i==139)
      leds[i] = CRGB(0, 0, 255);
  }

}

void eyeUmolLeft()
{
  for (int i = 131; i < 173; i ++)
  {
    if(i==165 || i==133 || i==154 || i==131 || i==132   || i==172 || i==139 || i==147 || i==138 || i==140)
      leds[i] = CRGB(40, 100, 255);
    else if(i==164 || i==155 || i==156 || i==163    || i==170 || i==171 || i==149 || i==148)
      leds[i] = CRGB(0, 0, 255);
  }
}

void eyeUmolRight()
{
  for (int i = 131; i < 173; i ++)
  {
    if(i==163 || i==133 || i==156 || i==131 || i==132   || i==170 || i==139 || i==149 || i==138 || i==140)
      leds[i] = CRGB(40, 100, 255);
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

void umolchanie()
{
  notEye();
  notMouth();

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

void tongue()
{
  notEye();
  notMouth();
  delay(10);

  tongueMouth();
  closeEye();
  FastLED.show();
  delay(700);
  //notMouth();
  face_selection = 0;
}

void evil()
{
  notEye();
  notMouth();
  delay(10);

  mouth();
  openEye();
  evilBrows();
  FastLED.show();
  delay(700);

  //notMouth();
  face_selection = 0;
}





void loop()
{
  nose();
  //morgaet();
  //umolchanie();
  //tongue();
  //evil();

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

  //delay(200);


  //delay(10);
  
}