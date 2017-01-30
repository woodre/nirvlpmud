/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     room
//  Create Date:  2005.02.18
//  Last Edit:    2005.02.18 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(arg) return;
  
  if(!present("sfp_miniquest_fire")) 
    add_object("players/forbin/realms/cave/OBJ/fire.c");  
  if(!present("sfp_miniquest_portal")) 
    add_object("players/forbin/realms/cave/OBJ/invisportal.c");    
  
  short_desc = "???";
  long_desc = 
    "The cave has opened up into a smoothy walled and floored domed\n"+
    "room.  The single blemish in the even walls is a large crack that\n"+
    "cuts through it, while only a perfectly square-cut hole above mars\n"+
    "the high domed ceiling.  A carefully bricked fire pit is erected\n"+
    "directly under the hole, and dark tufts of smoke float slowly up\n"+
    "through it.  Off to one side of the room, an ivory portal of some\n"+
    "sort stands idle, its rectangular plane lifelessly void.\n";
  set_light(0);
  add_item(({"wall","walls"}),
    "Smooth and curving gently inward, they disappear into the ceiling");  
  add_item("floor",
    "The floor is smooth and uncluttered");  
  add_item("ceiling",
    "The ceiling is a perfectly smooth dome, unmarked except by a single\n"+
    "hole cut into its center");      
  add_item(({"crack","blemish"}),
    "A large crack runs from the floor to several tens of feet high\n"+
    "along the cave wall");      
  add_item("hole",
    "A small, square hole in the ceiling allows smoke to rise up");      
  add_item(({"pit","fire pit"}),
    "A fire pit has been built in the center of the room.\n"+
    "It has a fire burning at the current moment");      
  add_item("smoke",
    "Dark grey puffs of smoke float upward and out of the cave");      
  add_smell("main", "The smell of smoke dominates the room.\n"); 
  add_smell("smoke", "You take a big whiff of the smoke and being to cough.\n");   
}


short() { return "???"; }    

init() {
  ::init();
  if(!present("sfp_miniquest_fire")) 
    add_object("players/forbin/realms/cave/OBJ/fire.c");  
  if(!present("sfp_miniquest_portal")) 
    add_object("players/forbin/realms/cave/OBJ/invisportal.c");   
  add_action("cmd_search", "search");
  add_action("cmd_squeeze", "squeeze");
}

int cmd_search(string arg) {
  if(arg == "crack") {
    tell_object(this_player(), 
      "You carefully search the crack in the cave wall.  You find that you\n"+
      "could 'squeeze' out of the 'crack'.\n");
    tell_room(this_player(),  
      (string)this_player()->query_name()+" carefully searches the crack in the cave wall.\n");
    return 1;
  }
}

int cmd_squeeze(string arg) {
  if(!arg || arg != "crack") {
    tell_object(this_player(), "Squeeze where?\n");
    return 1;
  }
  tell_object(this_player(), 
    "You turn sideways and carefully squeeze into the narrow crack...\n");
  this_player()->move_player("into the darkness#players/forbin/realms/cave/RMS/entry.c");
  return 1;  
}

void portal_on() {
  long_desc =   
    "The cave has opened up into a smoothy walled and floored domed\n"+
    "room.  The single blemish in the even walls is a large crack that\n"+
    "cuts through it, while only a perfectly square-cut hole above mars\n"+
    "the high domed ceiling.  A carefully bricked fire pit is erected\n"+
    "directly under the hole, and dark tufts of smoke float slowly up\n"+
    "through it.  Off to one side of the room, an ivory portal crackles\n"+
    "with power, a bright purple energy shimmering inside it.\n";
}

void portal_off() {
  long_desc =   
    "The cave has opened up into a smoothy walled and floored domed\n"+
    "room.  The single blemish in the even walls is a large crack that\n"+
    "cuts through it, while only a perfectly square-cut hole above mars\n"+
    "the high domed ceiling.  A carefully bricked fire pit is erected\n"+
    "directly under the hole, and dark tufts of smoke float slowly up\n"+
    "through it.  Off to one side of the room, an ivory portal of some\n"+
    "sort stands idle, its rectangular plane lifelessly void.\n";
}
  