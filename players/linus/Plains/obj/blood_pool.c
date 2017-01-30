#define ENVQN environment()->query_name()
#include "/players/linus/def.h"
inherit "/obj/treasure";
id(str) { return str=="blood" || str=="puddle" || str=="linus_blood"; }
reset(arg) {
 if(arg) return;
 set_short("A puddle of "+RED+"blood"+NORM);
 set_long(
  "A small puddle of blood that has dripped out of an abomination.\n");
 set_value(0);
 call_out("dry_up",5+random(10));
}
 
get() { return 0; }
 
dry_up() {
 tell_room(ENV(),"The "+RED+"blood"+NORM+" dries up and disappears into the ground.\n");
  MO(TO,"/room/void");
 destruct(TO);
}
