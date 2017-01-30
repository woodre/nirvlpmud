#include "def.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("gate");
  set_alias("death gate");
  set_short("The "+BOLD+BLK+"Death"+NORM+" Gate");
  set_long("This is the infamous 'death' gate, called such because you can enter it\n"+
           "only if you've either killed all of your opponents, or if you yourself\n"+
           "are dead.\n");
  set_weight(999);
  set_value(15000);
}
get() { return 0; }
init() {
  add_action("cmd_enter","enter");
}
cmd_enter(str) {
  object *world;
  int i;
  int is_open;
  notify_fail("Enter what?\n");
  if(!str) return 0;
  if(!id(str)) return 0;
  world=users();
  is_open=1;
  if(TP->query_ghost())
    is_open=1;
  else
  for(i=0; i<sizeof(world);i++) {
    if(environment(world[i]) && environment(world[i])->query_grand_arena() &&
       !environment(world[i])->is_arena_central() &&
       !(world[i]->query_ghost()) &&
      world[i]->query_level() < 20 && world[i]!=TP)
      is_open=0;
  }
  if(is_open) {
    write("You step into the death gate.\n");
    say(TPN+" steps into the death gate.\n");
    move_object(TP,PATH+"central");
    command("look",TP);
    say(TPN+" steps out of the vortex.\n");
    if(TP->query_ghost()) TP->remove_ghost();
    if(TP->query_pl_k() > 1) TP->rm_spar();
    return 1;
  }
  else {
    write("You cannot enter the death gate yet.\n");
    say(TPN+" tries to enter the death gate, but fails.\n");
    return 1;
  }
}
