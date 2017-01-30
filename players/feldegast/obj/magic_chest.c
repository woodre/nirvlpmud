/*
A one-shot object, with possible re-use.
atm, This is so James can pick up his prize because he left too
soon after the tourney.
*/
#include "/players/feldegast/defines.h"
#define FILE "/players/wocket/turtleville/OBJ/regen_potion"
#define NAME "vital"

int full;

reset(arg) {
  if(arg) return;
  full=1;
  restore_object("players/feldegast/obj/chest");
}
short() { return "A magic chest"; }
long(str) {
  write("An antique wood paneled chest bound with sturdy metal.\n");
}
id(str) { return str=="chest" || str=="magic chest"; }

get() { return 0; }
drop() { return 1; }

init() {
  add_action("cmd_open","open");
}

cmd_open(str) {
  if(TP->query_real_name()!=NAME) {
    notify_fail("You cannot open this chest.\n");
    return 0;
  }
  if(!full) {
    write("You can only open this box once.\n");
    return 1;
  }
  if(!str || str!="chest") {
    notify_fail("Open what?\n");
    return 0;
  }
  write("You open the chest and find something of value inside.\n");
  move_object(clone_object(FILE),TP);
  TP->recalc_carry();
  full=0;
  save_object("players/feldegast/obj/chest");
  return 1;
}
