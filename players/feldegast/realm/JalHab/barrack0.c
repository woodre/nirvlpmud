#include "defs.h"

inherit ROOM;

int cell;

void reset(int arg) {
  object guard;
  if(!present("guard")) {
    move_object(clone_object(MON_PATH+"goldcloak2.c"),this_object());
  }
  cell=0;
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This is a long corridor beneath the tower.  At the beginning of\n"+
"the hall, a creaky old chair sits beneath a softly glowing lamp.\n"+
"A cell at the end of the corridor appears to be the only one that\n"+
"is occupied.\n";
  items=({
    "corridor", "A long corridor with about six cells along its length",
    "chair", "A creaky old chair sits beneath the lamp",
    "lamp", "The lamp gives off a paltry glow",
    "cell", "The cell door is locked",
  });
  dest_dir=({
    PATH+"barrack2.c","up",
  });
}

void init() {
  ::init();
  add_action("cmd_unlock", "unlock");
  add_action("cmd_open", "open");
}

int cmd_unlock(string str) {
  object key;
  if(str!="cell" && str!="door") {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(cell > 0) {
    notify_fail("It is already unlocked.\n");
    return 0;
  }
  key=present("key#301",TP);
  if(!key) {
    notify_fail("You don't have the right key.\n");
    return 0;
  }
  write("You unlock the cell door.\n");
  say(TPN+" unlocks the cell door.\n");
  destruct(key);
  cell=1;
  return 1;
}

int cmd_open(string str) {
  if(str!="cell" && str!="door") {
    notify_fail("Open what?\n");
    return 0;
  }
  if(cell == 0) {
    notify_fail("It is locked.\n");
    return 0;
  }
  if(cell == 2) {
    notify_fail("It is already open.\n");
    return 0;
  }
  cell=2;
  write("You open up the cell and a pale green p'kalian creeps out of\n"+
        "it.  He says, \"Thank you for rescuing me.  I must flee now,\n"+
        "across the desert, but I would appreciate it if you would give\n"+
        "this token to my sister if you should see her.\"\n");
  write("P'silin gives you a charm.\n");
  write("P'silin leaves up.\n");
  move_object(clone_object(OBJ_PATH+"token.c"), TP);
  TP->recalc_carry();
  return 1;
}
