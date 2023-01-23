#include "ADCSetup.h"

bool mp = 0;
int16_t anv = 0;



void ADC0Setup(bool DacRef, int Res, int Samp, int ADCClk, int ADCDiv, int BaseV, bool Freerun, bool PreDiv) {

/*  genericClockSetup(ADCClk, ADCDiv);        //Sets up ADC clock and divides it
  AttachClock(ADCClk, 0x1E);

  if (DacRef) {
  DACSetup(BaseV);  //Setup DAC if needed
  };
*/
ADC0->CALIB.reg = ADC_CALIB_BIASCOMP(0x7) | ADC_CALIB_BIASREFBUF(0x7);

  ADC0->REFCTRL.bit.REFSEL = ADC_REFCTRL_REFSEL_INTVCC1_Val;
  


if (PreDiv) {
if (Res == 8) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_8BIT_Val;
} else if (Res == 10) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_10BIT_Val;
} else if (Res == 12) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_12BIT_Val;
} else {
  Serial.println("Unsupported resolution, change the value res to 8 10 or 12");
};
} else {
if (Res == 8) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_8BIT_Val;
} else if (Res == 10) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_10BIT_Val;
} else if (Res == 12) {
  ADC0->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV8_Val;
  ADC0->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_12BIT_Val;
} else {
  Serial.println("Unsupported resolution, change the value res to 8 10 or 12");
};
};
  
  if (DacRef) {
  ADC0->CTRLC.bit.DIFFMODE = 1;
  };


  ADC0->AVGCTRL.bit.SAMPLENUM = log2(Samp);

  ADC0->CTRLC.bit.FREERUN = 0;

  ADC0->CTRLA.bit.ENABLE = 1;


}


void AttachADC0(int ADCpin, bool IDACRefon) {


  if (IDACRefon) {
ADC0->INPUTCTRL.bit.MUXNEG = 0;
ADC0->INPUTCTRL.bit.MUXPOS = g_APinDescription[ADCpin].ulADCChannelNumber;
  } else {
ADC0->INPUTCTRL.bit.MUXNEG = 0x18;
ADC0->INPUTCTRL.bit.MUXPOS = g_APinDescription[ADCpin].ulADCChannelNumber;
  };
  
}

void AnalogBegin(int resolution, bool midphase, bool Freerun) {
Analog0Begin(resolution, midphase, Freerun);
}
void Analog0Begin(int resolution, bool midphase, bool Freerun) {

  ADC0Setup(midphase, resolution, 1, 3, 1, 512, Freerun, 1);
  mp = midphase;

}


int Analog0Collect() {
ADC0->SWTRIG.bit.START = true;           //Start reading again
while (ADC0->INTFLAG.reg == ADC_INTFLAG_RESRDY) {};  //Wait for new analog value to be ready
anv = ADC0->RESULT.reg;
return(anv);
}


int FastAnalogRead(int pin) {

  if (mp) {
ADC0->INPUTCTRL.bit.MUXNEG = 0;
ADC0->INPUTCTRL.bit.MUXPOS = g_APinDescription[pin].ulADCChannelNumber;
  } else {
ADC0->INPUTCTRL.bit.MUXNEG = 0x18;
ADC0->INPUTCTRL.bit.MUXPOS = g_APinDescription[pin].ulADCChannelNumber;
  };
//while (ADC->STATUS.bit.SYNCBUSY) {};
ADC0->SWTRIG.bit.START = true;           //Start reading again
while (ADC0->INTFLAG.reg == ADC_INTFLAG_RESRDY) {};  //Wait for new analog value to be ready
anv = ADC0->RESULT.reg;
return(anv);               //Write it down
}






void ADC1Setup(bool DacRef, int Res, int Samp, int ADCClk, int ADCDiv, int BaseV, bool Freerun, bool PreDiv) {

/*  genericClockSetup(ADCClk, ADCDiv);        //Sets up ADC clock and divides it
  AttachClock(ADCClk, 0x1E);

  if (DacRef) {
  DACSetup(BaseV);  //Setup DAC if needed
  };
*/
ADC1->CALIB.reg = ADC_CALIB_BIASCOMP(0x7) | ADC_CALIB_BIASREFBUF(0x7);

  ADC1->REFCTRL.bit.REFSEL = ADC_REFCTRL_REFSEL_INTVCC1_Val;
  


if (PreDiv) {
if (Res == 8) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_8BIT_Val;
} else if (Res == 10) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_10BIT_Val;
} else if (Res == 12) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_12BIT_Val;
} else {
  Serial.println("Unsupported resolution, change the value res to 8 10 or 12");
};
} else {
if (Res == 8) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_8BIT_Val;
} else if (Res == 10) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV2_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_10BIT_Val;
} else if (Res == 12) {
  ADC1->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV8_Val;
  ADC1->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_12BIT_Val;
} else {
  Serial.println("Unsupported resolution, change the value res to 8 10 or 12");
};
};
  
  if (DacRef) {
  ADC1->CTRLC.bit.DIFFMODE = 1;
  };


  ADC1->AVGCTRL.bit.SAMPLENUM = log2(Samp);

  ADC1->CTRLC.bit.FREERUN = 0;

  ADC1->CTRLA.bit.ENABLE = 1;


}


void AttachADC1(int ADCpin, bool IDACRefon) {

  if (IDACRefon) {
ADC1->INPUTCTRL.bit.MUXNEG = 0;
ADC1->INPUTCTRL.bit.MUXPOS = g_APinDescription[ADCpin].ulADCChannelNumber;
  } else {
ADC1->INPUTCTRL.bit.MUXNEG = 0x18;
ADC1->INPUTCTRL.bit.MUXPOS = g_APinDescription[ADCpin].ulADCChannelNumber;
  };
  
}


void Analog1Begin(int resolution, bool midphase, bool Freerun) {

  ADC1Setup(midphase, resolution, 1, 3, 1, 512, Freerun, 1);
  mp = midphase;

}


int Analog1Collect() {
ADC1->SWTRIG.bit.START = true;           //Start reading again
while (ADC1->INTFLAG.reg == ADC_INTFLAG_RESRDY) {};  //Wait for new analog value to be ready
anv = ADC1->RESULT.reg;
return(anv);
}


