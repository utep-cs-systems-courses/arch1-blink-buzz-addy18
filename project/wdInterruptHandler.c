#include <msp430.h>
#include "statemachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char button_state = 0;

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  
  if(++blink_count == 125 && button_state == 1){
    state1();
    blink_count = 0;
  }else if(++blink_count == 250 && button_state == 2){
    state2();
    blink_count = 0;
  }else if(++blink_count == 250 && button_state = 3){
    state3();
    blink_count = 0;
  }else if(++blink_count == 250 && button_state == 4){
    state4();
    blink_count = 0;
  } 
}
