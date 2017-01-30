#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("mercenary"))
    move_object(clone_object(MON_PATH+"mercenary1.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Mercenary Hall";
  long_desc = 
"  This is a hiring hall for mercenaries that is maintained by the\n"+
"Sultan to supplement the Goldcloaks who are constantly short on\n"+
"manpower.  Merchants hire mercenaries here to guard their caravans\n"+
"and shops.  In the back of the hall, you see a board with a list of\n"+
"jobs.\n";
  items=({
    "board", "There are three notes posted on the board",
  });
  dest_dir=({
    PATH+"smark.c", "out",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  switch(str) {
    case "1": write("The Merchant Abdullah Sakadi will bring rich rewards to whomever\n"+
                    "rescues the cargo of one of his caravans which was ambushed\n"+
                    "somewhere in the western desert.\n");
              break;
    case "2": write("Desperate men are required for a dangerous mission with rich\n"+
                    "rewards.  Seek Juletane at the Bloated Toad for more information.\n");
              break;
    case "3": write("Brave, strong, and intelligent adventurers wanted, for a\n"+
                    "dangerous quest.  For more information, seek the Hooded\n"+
                    "Man in the city of Sudakan.\n");
              break;
    default: write("Which note do you wish to read?  1, 2, or 3?\n");
             notify_fail("");
             return 0;
  }
  return 1;
}
