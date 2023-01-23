#ifndef ADCSetup_h
#define ADCSetup_h

#include <Arduino.h>

void ADC0Setup(bool DacRef, int Res, int Samp, int ADCClk, int ADCDiv, int BaseV, bool Freerun, bool PreDiv);
void ADC1Setup(bool DacRef, int Res, int Samp, int ADCClk, int ADCDiv, int BaseV, bool Freerun, bool PreDiv);
void genericClockSetup(int clk, int dFactor);
void AttachClock(int clk, int clkid);
void AttachADC0(int ADCpin = 0, bool IDACRefon = 0);  
void AttachADC1(int ADCpin = 0, bool IDACRefon = 0);  
void DACSetup(int BaseV);
void AnalogBegin(int resolution = 12, bool midphase = 0, bool Freerun = 0);
void Analog0Begin(int resolution = 12, bool midphase = 0, bool Freerun = 0);
void Analog1Begin(int resolution = 12, bool midphase = 0, bool Freerun = 0);
int FastAnalogRead(int pin);
int Analog0Collect();
int Analog1Collect();
  
#endif
