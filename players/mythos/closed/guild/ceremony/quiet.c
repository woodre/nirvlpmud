#include "/players/mythos/closed/ansi.h"
#define user environment(this_object())

id(str) {return str == "quiet"; }

drop() {return 1;}
init() {
  if(living(user)) {
    write("Do nothing till you are told....\n"); }
#ifndef __LDMUD__
  add_action("quiet");add_xverb("");
#else
add_action("quiet", "", 3);
#endif
  call_out("check",100);
}

quiet() {
  write("Shhhh!  You are being initiatied!\n"); 
  return 1;}

check() {
  destruct(this_object());
return 1;}
