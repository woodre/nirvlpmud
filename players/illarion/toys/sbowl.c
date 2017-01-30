/*
 * sbowl.c - a dispenser for strawberry objects- see strawberry.c
 * Illarion 4/00
 */

inherit "obj/treasure";
#include "/players/illarion/dfns.h"
#define BERRY "/players/illarion/toys/strawberry"

void reset(status arg) {
  if(arg) return;
  
  set_id("bowl");
  set_short("A large bowl of strawberries");
  set_long("A wide clay bowl with a blue glaze so like the sky it seems\n"+
           "as though there should be clouds blowing across it.  It is\n"+
           "nearly to overflowing with large, ripe strawberries, that\n"+
           "seem to beg you to "+BLD("pluck")+" them from the bowl and eat\n"+
           "them.\n");
  set_value(0);
  set_weight(1);
}
void init() {
  ::init();
  add_action("cmd_pluck","pluck");
}
status cmd_pluck(string str) {
  if(str != "strawberry from bowl")
    FAIL("Pluck what from where?\n");
  write("You take a strawberry out of the bowl.\n");
  say(TPN+" takes a strawberry from the bowl.\n");
  transfer(clone_object(BERRY),TP);
  return 1;
}
status get() { return 0; }
