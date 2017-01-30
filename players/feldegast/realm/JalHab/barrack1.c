#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object guard;
  if(!present("goldcloak")) {
    guard=clone_object(MON_PATH+"goldcloak.c");
    guard->load_chat("The Goldcloak asks: Can I help you?\n");
    move_object(guard,this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This is the entry hall to the Tower of the Righteous.  Between\n"+
"two rows of sandstone pillars, a sumptuous red carpet leads to\n"+
"a chest high desk behind which is a heavy oak door.\n";
  items=({
    "pillars","Tall sandstone pillars that are meant to be both decorative\n"+
              "and support the tower's weight",
    "carpet","A fine red carpet, somewhat dusty in spots leads up to\n"+
             "the sergeant's desk",
    "door","The heavy oak door is slightly ajar",
  });
  dest_dir=({
    PATH+"sroy.c","out",
    PATH+"barrack2.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_block","east");
}

int cmd_block(string str) {
  if(present("goldcloak")) {
    write("The guard says: You're not allowed in there!\n");
    return 1;
  }
}
