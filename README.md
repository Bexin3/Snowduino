Compatible with SAMC21, more description will be added soon, check examples to use the code. Its still in alpha.

This is to make SAMC21 functions faster same way as the SAMD21 speeduino, however it is not yet complete nor tested on a board as i am still waiting for one. Some features are also missing, while you can take advantage of two ADCs.


With centered analog read you can have relative ground on A0 which is half of supply voltage to compare against.

Function descriptions and time they take:
Simplified:

AnalogBegin(); - starts the ADC0 and attaches it to clock number 3. You can add one number inside to set resolution, deffault is 12 bit, possible are 8 10 and 12, then if you add one it will enable mode that centers values at half of the supply voltage, which now appears at pin A0, so you have negative and positive values, and after if you add 1 ADC will run in a freerun mode - it will keep taking reads again and again. Full form is AnalogBegin(Resolution, Centering, Freerun) ~ 30us

AnalogBegin0(); - starts ADC0

AnalogBegin1(); - starts ADC1

FastAnalogRead(pin); - Attaches the Analog pin and reads it, returns an integer. ~ 3us

AttachADC0(pin, centering) - Attaches to an analog pin and sets gain ~ 20us

AttachADC1(pin, centering) - Attaches to an analog pin and sets gain ~ 20us

Analog0Collect() - Reads and collects an analog value from last attached pin to ADC0 ~ 3us, but bit less than FastAnalogRead

Analog1Collect() - Reads and collects an analog value from last attached pin to ADC1 ~ 3us, but bit less than FastAnalogRead

PWMBegin(pin, frequency) - begins running a pin at a specified frequency while attaching it to clock 8, minimum is 1 hz - calls PWMSetup. ~ 87us

PWMDuty(pin, dutycycle) - Sets the duty cycle at a specified number, in fractions. ~ 7us

PWMFrequency(pin, frequency) - changes the frequency, minimum 1 hz, if the pin previously had lower frequency selected may cause issues. ~40us

PWMSetup(pin, frequency, clock, Interrupts) - enables PWM, at a specidied pin, frequency which can go down to 0.00281 but it changes clock divisions, use clock 3-8. Enabling interrupts will make it call to Tch(); where you return duty cycle so it changes every cycle. ~ 124us, ~ 80us with frequency above 1hz


