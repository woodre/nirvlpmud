/*
File: wepshop.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A weapon shop.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if(!present("shopkeeper"))
    move_object(clone_object(PATH+"shpkpr2"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="Eagle's Claws";
  long_desc=
"    This immaculate shop is lined with racks of various weapons.\n"+
"Behind frosted windows you see thick iron bars, and the sturdy\n"+
"door looks like it could hold off an army until reinforcements\n"+
"arrived.  To the left of the door is a wooden counter where the\n"+
"shopkeeper usually sits.\n";
  items=({
    "racks","They've been knicked and scratched by hundreds of weapons\n"+
            "but they're still standing",
    "windows","You can't make out anything through the thick frosted windows",
    "bars","Thick bars made out of black iron",
    "door","A thick oak door with banded iron hinges and a bar",
    "counter","A sturdy counter for placing goods while they're being haggled over"
  });
  dest_dir=({
    PATH+"bronze1","east"
  });
}   

init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_buy","buy");
}

cmd_list(string str) {
  if(!str) {
    write("Read what?\n");
    return 1;
  }
  if(str!="sign") {
    write(
      "=====================================================\n"+
      "=                 Eagle's Claws                      =\n"+
      "=       1. Quarterstaff...........1000 coins         =\n"+
      "=       2. Spear..................1200 coins         =\n"+
      "=       3. Pike...................1500 coins         =\n"+
      "=       4. Halberd................2000 coins         =\n"+
      "=                                                   =\n"+
      "=====================================================\n"
    );
    say(this_player()->query_name()+" looks at the sign.\n");
  }
}

cmd_buy(string str) {
  int result;
  if(!present("shopkeeper"))
    return 0;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  switch(str) {
    case "1": case "staff":
    case "quarterstaff": result=checked_buy(WEP_PATH+"staff.c",2,1000);break;
    case "2": case "spear": result=checked_buy(WEP_PATH+"spear.c",2,1200);break;
    case "3": case "pike": result=checked_buy(WEP_PATH+"pike.c",3,1400);break;
    case "4": case "halberd": result=checked_buy(WEP_PATH+"halberd.c",4,2500);break;
    default: write("The shopkeeper says: We don't have that.\n");
             return 1;
  }
  if(result) {
    write("You buy a "+str+".\n");
    say(this_player()->query_name()+" buys a "+str+".\n");
    return 1;
  }
  else
    return 1;
}
