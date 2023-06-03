/*
* LED 8x8 DotMarix using Arduino
* Created by TheCircuit
*/

#include <LedControl.h>

int DIN = 11; 
int CS =  7;
int CLK = 13; 

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
    byte a[8] = {0x00,0x18,0x28,0x08,0x08,0x08,0x3C,0x00};
    printByte(a);
    delay(1000);
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
