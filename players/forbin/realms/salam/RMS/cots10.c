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
#undef COTS
#define COTS "Throne Room"
inherit "/players/forbin/closed/std/room.c";

int Found;

reset(arg) {
  int a;
  if(!present("salamite")) add_object(NPC+"king.c");
  if(!present("guardsman")) {   
    for(a = 0; a < 2+random(2); a++) add_object(NPC+"salamite3.c");
  }    
  if(arg) return;
  short_desc = COTS;
  long_desc = 
    "  Here the tunnel system opens up into a vast chamber.  A soaring\n"+
    "ceiling towers above; stalactites of obsidian hang down from above.\n"+
    "The cave walls are of the darkest black rock.  A thin pathway leads\n"+
    "across an open pit to a wide stone area.  Lava bubbles and pops on\n"+
    "either side of the path, while a stiffling heat rises from the pit.\n"+
    "A large throne sits in the center of the area.  Several torches line\n"+
    "the walls and light the chamber.\n";   
  add_item(({"tunnel","tunnel system"}),
    "The tunnel heads out from the room and back into darkness");
  add_item("ceiling",
    "The ceiling high above is covered in dripping stalactites");
  add_item(({"stalactite","stalactites"}),
    "Far above the the chamber floor, stalactites drip molten rock");
  add_item(({"wall","walls"}),
    "The cave walls of darkest obsidian shine like glass");
  add_item("cave",
    "The cave opens up into a large chamber here");
  add_item(({"rock","black rock","obsidian","stone"}),
    "The rock here is the blackest obsidian, shiny and void of any color");
  add_item(({"path","pathway"}),
    "The pathway leads over an open pit of lava");
  add_item("pit",
    "The pit below the path is a boiling bath of bubbling lava");
  add_item("lava",
    "Bright red lava flows in the pit beneath the pathway; molten rock\n"+
    "drops from the ceiling above");
  add_item("area",
    "A stone area fans out across the pathway");
  add_item("throne",
    "A large throne of black obsidian has been carved from the room itself");
  add_item(({"torch","torches"}),
    "There are several torches that light the room.  One beside the throne\n"+
    "is slightly turned");
  add_listen("main", 
    "The lava below you cracks and pops with a terrifying sound.\n");
  add_touch("lava",
    "Now that wouldn't be a smart thing to do.\n");
  set_light(1);
  add_exit(RMS+"cots07","west");
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
  add_action("cmd_descend","descend");
}

/* 
 *  ***********************************************************************
 *  Function:    search 
 *  Description: player can find hidden staircase
 *  Arguments:   string str, where str is item player wishes to search
 *  ***********************************************************************
 */

cmd_search(string str) {
  if(str == "torch" || str == "torches") {
    if(!Found) {
      write("You search the "+str+" and find one loose.\n"+
        "You twist the torch and find a staircase.\n");
      say(this_player()->query_name()+" searches the "+str+".\n");
      found_it();
      return 1;
    }
    write("You search the "+str+" and find one loose.\n");
    say(this_player()->query_name()+" searches the "+str+".\n");
    return 1;
  }
}

/* 
 *  ***********************************************************************
 *  Function:    found_it() 
 *  Description: resets room description after player finds hidden stairs
 *  Arguments:   none
 *  ***********************************************************************
 */

found_it() {
  long_desc = 
    "  Here the tunnel system opens up into a vast chamber.  A soaring\n"+
    "ceiling towers above; stalagtites of obsidian hang down from above.\n"+
    "The cave walls are of the darkest black rock.  A thin pathway leads\n"+
    "across an open pit to a wide stone area.  Lave bubbles and pops on\n"+
    "either side of the path, while a stiffling heat rises from the pit.\n"+
    "A large throne sits in the center of the area.  Several torches line\n"+
    "the walls and light the chamber.  A staircase beside the throne leads\n"+
    "downward.\n";
  add_item(({"stairs","staircase"}), 
    "A set of stairs is partially hidden beside the throne.  The stairs\n"+
    "lead down into darkness.  You could descend them");
  Found = 1;
    return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    descend 
 *  Description: player descend stairs if they have been found
 *  Arguments:   string str, where str is item player wishes to search
 *  ***********************************************************************
 */

cmd_descend(string str) {
  if(!Found) return 0; 
  if(!str || (str != "stairs" && str != "staircase")) return 0; 
  write("You push the painting aside and start down the "+str+".\n");
  say(this_player()->query_name()+" leaves down the "+str+".\n");
  move_object(this_player(),RMS+"cots11.c");
  command("look",this_player());
  say(this_player()->query_name()+" enters the room.\n");
    return 1; 
}