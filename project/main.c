#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "libTimer.h"

int main(void){
  configureClocks();
  led_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();

  or_sr(0x18);
}
