//front 9
#define Str0 13
#define Str1 12
#define Str2 14
#define Str3 27
#define Str4 26
#define Str5 25
#define Str6 33
#define Str7 32
#define Str8 23

//back 
#define Str9  15
#define Str10 4
#define Str11 5
#define Str12 18
#define Str13 19
#define Str14 21
#define Str15 22



#include <Adafruit_NeoPixel.h>

uint8_t BRIGHT = 40;
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 20;  //the value is a number of milliseconds
uint8_t curUp = 0;

class Strip
{
public:
  uint8_t   effect;
  uint8_t   effects;
  uint16_t  effStep;
  unsigned long effStart;
  Adafruit_NeoPixel strip;
  Strip(uint16_t leds, uint8_t pin, uint8_t toteffects, uint16_t striptype) : strip(leds, pin, striptype) {
    effect = -1;
    effects = toteffects;
    Reset();
  }
  void Reset(){
    effStep = 0;
    effect = (effect + 1) % effects;
    effStart = millis();
  }
};

struct Loop
{
  uint8_t currentChild;
  uint8_t childs;
  bool timeBased;
  uint16_t cycles;
  uint16_t currentTime;
  Loop(uint8_t totchilds, bool timebased, uint16_t tottime) {currentTime=0;currentChild=0;childs=totchilds;timeBased=timebased;cycles=tottime;}
};

Strip strip_0(15, Str0, 15, NEO_GRB + NEO_KHZ800);
Strip strip_1(15, Str1, 15, NEO_GRB + NEO_KHZ800);
Strip strip_2(15, Str2, 15, NEO_GRB + NEO_KHZ800);
Strip strip_3(15, Str3, 15, NEO_GRB + NEO_KHZ800);
Strip strip_4(15, Str4, 15, NEO_GRB + NEO_KHZ800);
Strip strip_5(15, Str5, 15, NEO_GRB + NEO_KHZ800);
Strip strip_6(15, Str6, 15, NEO_GRB + NEO_KHZ800);
Strip strip_7(15, Str7, 15, NEO_GRB + NEO_KHZ800);
Strip strip_8(15, Str8, 15, NEO_GRB + NEO_KHZ800);
Strip strip_9(15, Str9, 15, NEO_GRB + NEO_KHZ800);
Strip strip_10(15, Str10, 15, NEO_GRB + NEO_KHZ800);
Strip strip_11(15, Str11, 15, NEO_GRB + NEO_KHZ800);
Strip strip_12(15, Str12, 15, NEO_GRB + NEO_KHZ800);
Strip strip_13(15, Str13, 15, NEO_GRB + NEO_KHZ800);
Strip strip_14(15, Str14, 15, NEO_GRB + NEO_KHZ800);
Strip strip_15(15, Str15, 15, NEO_GRB + NEO_KHZ800);



struct Loop strip0loop0(1, false, 1);

//[GLOBAL_VARIABLES]

void setup() {

  //Your setup here:

  strip_0.strip.begin();
  strip_1.strip.begin();
  strip_2.strip.begin();
  strip_3.strip.begin();
  strip_4.strip.begin();
  strip_5.strip.begin();
  strip_6.strip.begin();
  strip_7.strip.begin();
  strip_8.strip.begin();
  strip_9.strip.begin();
  strip_10.strip.begin();
  strip_11.strip.begin();
  strip_12.strip.begin();
  strip_13.strip.begin();
  strip_14.strip.begin();
  strip_15.strip.begin();

  
}

void loop() {

  //Your code here:

  strips_loop();
  
}

void strips_loop() {
  if(strip0_loop0() & 0x01)
    strip_0.strip.show();
    strip_1.strip.show();
    strip_2.strip.show();
    strip_3.strip.show();
    strip_4.strip.show();
    strip_5.strip.show();
    strip_6.strip.show();
    strip_7.strip.show();
    strip_8.strip.show();
    strip_9.strip.show();
    strip_10.strip.show();
    strip_11.strip.show();
    strip_12.strip.show();
    strip_13.strip.show();
    strip_14.strip.show();
    strip_15.strip.show();
}

uint8_t strip0_loop0() {
  uint8_t ret = 0x00;
  switch(strip0loop0.currentChild) {
    case 0: 
           ret = strip0_loop0_eff0();break;
  }
  if(ret & 0x02) {
    ret &= 0xfd;
    if(strip0loop0.currentChild + 1 >= strip0loop0.childs) {
      strip0loop0.currentChild = 0;
      if(++strip0loop0.currentTime >= strip0loop0.cycles) {strip0loop0.currentTime = 0; ret |= 0x02;}
    }
    else {
      strip0loop0.currentChild++;
    }
  };
  return ret;
}

uint8_t strip0_loop0_eff0() {
  
    // Strip ID: 0 - Effect: Rainbow - LEDS: 15
    // Steps: 64 - Delay: 32
    // Colors: 3 (50.0.0, 0.50.0, 0.0.50)
    // Options: rainbowlen=16, toLeft=false, 
  if(millis() - strip_0.effStart < 32 * (strip_0.effStep)) return 0x00;
  float factor1, factor2;
  uint16_t ind;
  uint8_t tempR,tempG,tempB;
  for(uint16_t j=0;j<15;j++) {
    ind = 64 - (uint16_t)(strip_0.effStep - j * 4) % 64;
    switch((int)((ind % 64) / 21.33333333)) {
      case 0: factor1 = 1.0 - ((float)(ind % 64 - 0 * 21.33333333) / 21.33333333);
              factor2 = (float)((int)(ind - 0) % 64) / 21.33333333;
              
              tempR = BRIGHT * factor1;
              tempG = BRIGHT * factor2;
              tempB = 0;
              break;
      case 1: factor1 = 1.0 - ((float)(ind % 64 - 1 * 21.33333333) / 21.33333333);
              factor2 = (float)((int)(ind - 21.33333333) % 64) / 21.33333333;
              tempR = 0;
              tempG = BRIGHT * factor1;
              tempB = BRIGHT * factor2;
              break;
      case 2: factor1 = 1.0 - ((float)(ind % 64 - 2 * 21.33333333) / 21.33333333);
              factor2 = (float)((int)(ind - 42.6666666) % 64) / 21.33333333;
              tempR = BRIGHT * factor2;
              tempG = 0;
              tempB = BRIGHT * factor1;
              break;
    }
    strip_0.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_1.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_2.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_3.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_4.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_5.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_6.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_7.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_8.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_9.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_10.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_11.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_12.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_13.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_14.strip.setPixelColor(j, tempR,tempG,tempB);
    strip_15.strip.setPixelColor(j, tempR,tempG,tempB);
 
    
  }
  if(strip_0.effStep >= 64) {strip_0.Reset(); return 0x03; }
  else strip_0.effStep++;
  return 0x01;
}
