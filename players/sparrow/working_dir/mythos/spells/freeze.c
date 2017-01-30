/* 03/13/06 Earwax:  This is illegal as hell, changing duration from
 * random(50)+50 seconds to 1+r3, may eliminate from pk altogether, 
 * but this at least makes it worth something.
 */

#include "/players/mythos/closed/ansi.h"
int k;

id(str) {return str == "freeze.c"; }

reset(arg) {
  if(arg) return;
  /*
  call_out("check",50+random(50));
  */
  call_out("check", 1+random(3)); /* 1-3 seconds, Earwax */
}

drop() {return 1;}
init() {
  add_action("quiet");add_xverb("");
}

quiet() {
  write(BLU+"You are frozen!\n"+NORM); 
  return 1;}

check() {
  destruct(this_object());
return 1;}
