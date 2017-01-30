#include "/players/mythos/closed/ansi.h"


id(str) {return str == "freeze.c"; }

reset(arg) {
  if(arg) return;
  call_out("check",6+random(15));
}

drop() {return 1;}
init() {
#ifndef __LDMUD__
  add_action("quiet");add_xverb("");
#else
  add_action("quiet", "", 3);
#endif
}

quiet() {
  write(BLU+"You are frozen!\n"+NORM); 
  return 1;}

check() {
  destruct(this_object());
return 1;}
