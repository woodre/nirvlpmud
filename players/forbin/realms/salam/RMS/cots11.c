/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Function:     Caves of the Salamite
//  Create Date:  2004.06.05
//  Last Edit:    2004.08.02 -Forbin
//  Notable Changes:
//    2004.08.02 -modified short()
*/

#include "/players/forbin/realms/salam/salamdefine.h"
inherit "/players/forbin/closed/std/room.c";

int Found;

reset(arg) {
  if(!present("salamite")) add_object(NPC+"salamite4.c");  
  if(arg) return;
  short_desc = COTS;
  long_desc = 
    "  A small, squarish room has been carved out of the black rock.  A\n"+
    "small sleeping pad lies in one corner, partially hidden by a ragged\n"+
    "old blanket.  Dirt and dust cover the floor.  A small doorway leads\n"+
    "to a staircase leading upwards.\n";
  set_light(0);
  add_item("room",
    "A square room carved from solid rock"); 
  add_item("rock",
    "The black rock looks to be obsidian");
  add_item(({"pad","sleeping pad","blanket","old blanket"}),
    "A woolen gray blanket, full of holes, has been tossed onto a thin\n"+
    "sleeping pad.  It looks very uncomfortable");
  add_item(({"dirt","dust","floor"}),
    "The floor is so dirty that you are uncomfortable just walking on it");
  add_item(({"door","doorway"}),
    "A darkened opening where you can barely make out a some stairs");
  add_item(({"stairs","stairway"}),
    "The stairs lead up, out of the room");
  add_exit(RMS+"cots10","up");
  Found = 0;
}

query_salamroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_salamroom() && this_player()->query_level() < 40) return RED+COTS+NORM; 
      else { 
        sh = RED+short_desc+RED+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += RED+"]";
        return sh+NORM; 
      }
    }
    else return RED+COTS+NORM;   
  }
  else return "Dark room";     
}

init() {
  ::init();
   add_action("cmd_search","search");
}

/* 
 *  ***********************************************************************
 *  Function:    search 
 *  Description: player can find 110+random(200) coins
 *  Arguments:   string str, where str is item player wishes to search
 *  ***********************************************************************
 */

cmd_search(string str) {
  int amount;
  amount = 100+random(200);
  if(str == "blanket" || str == "pad" || str == "sleeping pad") {
    if(!Found) {
      write("You carefully search the "+str+".  You find "+amount+" coins.\n");
      say(this_player()->query_name()+" searches the "+str+".\n");
      Found = 1;
    }
    write("You search the "+str+", but find nothing.\n");
    say(this_player()->query_name()+" searches the area.\n");
      return 1;
  }
}