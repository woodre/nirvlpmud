/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     area entrance
//  Create Date:  2005.02.18
//  Last Edit:    2005.02.18 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("cave");
  set_short(HIK+"A small cave"+NORM);
  set_long(
    "A small cave is marked by the absolute darkness of its opening.\n"); 
}

get() { return 0; }

init() {
  ::init();
  add_action("cmd_search", "search");
  add_action("cmd_enter", "enter");
}


int cmd_search(string str) {
  if(str == "cave") {
    tell_object(this_player(), 
      "You carefully search the opening of the cave and find that it is\n"+
      "much larger inside than you thought. You could 'enter' it.\n");
    tell_room(this_player(),  
      (string)this_player()->query_name()+" carefully searches the opening of the cave.\n");
    return 1;
  }
}

int cmd_enter(string arg) {
  if(!arg || arg != "cave") {
    tell_object(this_player(), "Enter what?\n");
    return 1;
  }
  this_player()->move_player("into the cave#players/forbin/realms/cave/RMS/entry.c");
  return 1;  
}