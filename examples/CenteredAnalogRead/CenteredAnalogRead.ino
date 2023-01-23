#include "Snowduino.h"

void setup() {
Analog0Begin();
AttachADC0(2, 1);
Serial.begin(9600);
}

void loop() {
Serial.println(Analog0Collect());
}