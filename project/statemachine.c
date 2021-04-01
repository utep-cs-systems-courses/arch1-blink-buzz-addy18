#include <msp430.h>
#include "statemachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char state1(){ //trigger red
  static char state = 0;
  switch(state){
  case 0: red_on = 1; state = 1; break;
  case 1: red_on = 0; state = 0; break;
  }
  return 1;
}

char state2(){ //trigger green 
  static char state = 0;
  switch(state){
  case 0: green_on = 1; state = 1; break;
  case 1: green_on = 0; state = 0; break;
  }
  return 1;
}

char state3(){ //toggle red and green lighst 
  char changed = 0;
  static enum{R=0, G=1} color = G;
  switch(color){
  case R: changed = state1(); color = G; break;
  case G: changed = state2(); color = R; break;
  }
  led_changed = changed;
  led_update();
}

char state4(){ //off
  green_on = 0;
  red_on = 0;
  led_changed = 1;
  led_update();
  return 1;
}

void state_advance(){
  char changed = 0;
  switch(switch_state_changed){
  case 1:
    changed = state1();
    break;
  case 2:
    changed = state2();
    break;
  case 3:
    changed = state3();
    break;
  case 4:
    changed = state4();
    break;
  }
  led_changed = changed;
  led_update();
}
