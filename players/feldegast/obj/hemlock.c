#include "/players/feldegast/defines.h"
inherit "obj/treasure";

int doses;

reset(arg) {
  if(arg) return;
  set_id("hemlock");
  set_alias("vial");
  set_short("A "+BLK+BOLD+"glass"+NORM+" vial");
  set_long(
"This is a tiny glass vial with crystal clear glass and a menacing\n"+
"black liquid inside.\n"
  );
  set_weight(1);
  set_value(2000);
  doses=4;
}
init() {
  ::init();
  add_action("cmd_drink","drink");
  add_action("cmd_drink","sip");
}
cmd_drink(str) {
  notify_fail("Drink what?\n");
  if(!str) return 0;
  if(!id(str)) return 0;
  write("You open the vial and take a sip of the oily black liquid it contains.\n");
  say(TPN+" sips from a "+BLK+BOLD+"glass"+NORM+" vial.\n");
  move_object(clone_object("/players/feldegast/obj/poison2.c"),TP);
  doses--;
  if(doses<=0) destruct(this_object());
  return 1;
}
