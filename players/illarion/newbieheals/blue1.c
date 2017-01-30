/* 10 hp/sp heal, 4 tox, stuffed, at 240 coins. */
/*  Modified to 10 hp only, 8 tox, stuff, cost 160 coins
    Softly January, 2001

cleaned up some code issues
 - illarion - august 2009
    */
#include "/players/softly/closed/ansi.h"
#define MASTER "/players/softly/nhall/healmaster"

int uses;

id(str) { 
  return str == "balm" || str == "blue"; 
}
short() { return "Healing Balm "+BLU+"(blue)"+NORM+" ["+uses+"]"; }  
long(){
   write(
"  This is a small container of healing balm. It is\n"+
"made of steel. To use the balm inside, 'apply_blue'.\n"+
"It has "+HIB+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value() { 
  return (uses * 50); 
}
query_save_flag() { 
  return 1; 
}
set_uses(arg) {
  uses=arg;
}
reset(arg) {
  if(arg) return;
  uses = 3;      
}
  
init() {
  add_action("use_it", "apply_blue");
}
   
use_it() {
	return MASTER->use_heal(this_object(),this_player(),uses);
}


get() { 
  return 1; 
}

query_weight() {
  return 1;
}	
