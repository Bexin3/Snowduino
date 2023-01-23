#include "ClockSetup.h"

void genericClockSetup(int clk, int dFactor) {


GCLK->GENCTRL[clk].bit.IDC;
GCLK->GENCTRL[clk].bit.DIV = dFactor;
GCLK->GENCTRL[clk].bit.GENEN;
GCLK->GENCTRL[clk].bit.SRC = GCLK_GENCTRL_SRC_OSC48M_Val;


}



void AttachClock(int clk, int clkid) {
GCLK->PCHCTRL[clkid].bit.GEN = clk;
}
