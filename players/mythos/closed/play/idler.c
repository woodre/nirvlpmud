#include "/players/mythos/closed/ansi.h"


id(str) {return str == "idler"; }

get() { return 0;}
drop() {return 1;}

init() {
  add_action("release","heinlein");
#ifndef __LDMUD__
  add_action("quiet");add_xverb("");
#else
  add_action("quiet", "", 3);
#endif
  call_out("check",50+random(50));
}

quiet(str) {
  if(str != "dance" && str != "heinlein") {
    write("You are idling...Type pword to release self.\n");
  return 1;}
}

check() {
  command("dance",environment(this_object()));
    call_out("check",50+random(50));
return 1;}

release() {
  write("You are released.\n");
  destruct(this_object());
return 1;}
