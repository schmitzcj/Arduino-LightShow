#include <FastLED.h>
#define LED_LOW 2
#define LED_MID 8
#define LED_TOP 10
#define NUM_LEDS 60

CRGB lowLED[NUM_LEDS];
CRGB midLED[NUM_LEDS];
CRGB topLED[NUM_LEDS];

//Vars 
int delayAmt = 84;
int brightLvl = 255;
int stripCnt = 60;

//Counters
int countTop = 0;
int countMid = 0;
int countLow = 0;
bool cycleComplete = false;
bool boolInit = false;

void setup() {
  delay(1500);
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_LOW, GRB>(lowLED, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_MID, GRB>(midLED, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, LED_TOP, GRB>(topLED, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void loop() {
  if (boolInit == false){
    FastLED.setDither(0);
    for (int intCount = 0; intCount < NUM_LEDS; intCount++) {
      lowLED[intCount] = CRGB::Black;
      midLED[intCount] = CRGB::Black;
      topLED[intCount] = CRGB::Black;
    }
    boolInit = true;
  }
  cycleComplete = false;
  pulseUp();
}




void pulseUp(){
  do{
    //Low LEDs start
    if (countLow < brightLvl){
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        lowLED[intCount] = CHSV(122, 173, countLow);
      }
      countLow++;
    }
    else if(countLow == brightLvl){
      //Maintain on
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        lowLED[intCount] = CHSV(122, 173, countLow);
      }
    }
    
    //Mid LEDs start
    if (countLow > delayAmt && countMid < brightLvl){
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        midLED[intCount] = CHSV(152, 173, countMid);
      }
      countMid++;
    }
    else if(countMid == brightLvl){
      //Maintain on
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        midLED[intCount] = CHSV(152, 173, countMid);
      }
    }
    else{
      //Maintain off
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        midLED[intCount] = CRGB::Black;
      }
    }
  
    //Top LEDs start
    if (countMid > delayAmt && countTop < brightLvl){
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        topLED[intCount] = CHSV(216, 173, countTop);
      }
      countTop++;
    }
    else{
      //Maintain off
      for (int intCount = 0; intCount < stripCnt; intCount++) {
        topLED[intCount] = CRGB::Black;
      }
    }
    
    //Fade all LEDs when the top has reached brightness
    if (countTop == brightLvl){
      int intTime = 0; 
      while (intTime < 1500){
        for (int intCount = 0; intCount < stripCnt; intCount++) {
          lowLED[intCount] = CHSV(122, 173, brightLvl);
          midLED[intCount]= CHSV(152, 173, brightLvl);
          topLED[intCount] = CHSV(216, 173, brightLvl);
        }
        delay(1);
        FastLED.show(); 
        intTime++;  
      }
      
      for (int intDimming = brightLvl; intDimming > 0; intDimming--) {
        for (int intCount = 0; intCount < stripCnt; intCount++) {
                lowLED[intCount] = CHSV(122, 173, intDimming);
                midLED[intCount]= CHSV(152, 173, intDimming);
                topLED[intCount] = CHSV(216, 173, intDimming);
            }
        delay(2);
        FastLED.show();
      }
      countTop = 0;
      countMid = 0;
      countLow = 0;
      cycleComplete = true;
    }
    
    delay(10);
    FastLED.show();
  }while (cycleComplete != true);
}
