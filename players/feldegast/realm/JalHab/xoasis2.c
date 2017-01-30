#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc=CYN+"Oasis"+NORM;
  long_desc=
"  A pool of crystal blue water lies amidst a thick tangle of foliage.\n\
The foliage holds back the encroaching sand of the Jal-Hab desert.\n\
A dead palm tree has fallen across the pool.\n";
  items=({
    "foliage", "The foliage is a fecund bush with long tendrils covered in sharp\n"+
               "prickly thorns.  It oozes a disgusting sap",
    "tree", "You notice the skeleton of some animal next to the fallen tree",
    "pool", "The stiflingly hot air makes you thirsty.  The water looks\n"+
            "extremely inviting",
    "sign", "You notice a sign hidden among the foliage",
  });
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

init() {
  ::init();
  add_action("cmd_search", "search");
  add_action("cmd_read", "read");
  add_action("cmd_drink", "drink");
}

cmd_drink(str) {
  if(str!="from pool" && str!="water") {
    notify_fail("Drink what?\n");
    return 0;
  }
  if(!this_player()->drink_soft(10)) {
    write("You aren't thirsty.\n");
    return 1;
  }
  this_player()->heal_self(15);
  write("You drink deeply from the pool.\n");
  move_object(clone_object(OBJ_PATH+"poison2.c"),TP);
  return 1;
}

cmd_search(str) {
  write("You find a wooden sign among the waterthorn vines.\n");
  return 1;
}

cmd_read(str) {
  if(str!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write(BOLD+"Poison!\n"+NORM);
  return 1;
}
