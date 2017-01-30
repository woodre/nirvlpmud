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

reset(arg) {
  if(!present("salamite") && !random(3)) add_object(NPC+"salamite2.c");    
  if(arg) return;
  short_desc = COTS;
  long_desc = 
    "  The pitch darkness seems to close in.  Barely able to see more than\n"+
    "a few inches, the features of the dark room are impossible to make out\n"+
    "in such utter gloom.  Swirling darker and darker, the sinister\n"+
    "murkiness appears to move with a life of its own.\n";
  set_light(-1);
  add_item(({"dark","darkness","feature","features","room","gloom",
             "murkiness","area","place","here","around","cave","caves",
             "pitch","path","pitch darkness"}),
    "You can't see anything in this darkness...");  
  set_chance(random(5));
    add_msg("Did something just brush past you?");
    add_msg("The darkness seems to close in on you...");
    add_msg("You tremble with fear...");
    add_msg("You hear a shrill scratching further into the blackness...");
    add_msg("You spin around, swearing that something just breathed on your neck...");
    add_msg("An mournful wail fills your head...");
    add_msg("You hear something move just ahead in the darkness...");
    add_msg("Shadows swirl about the room...");
    add_msg("A dark wind whistles through the area...\n");
  add_listen("main", 
    "You listen closely and hear a slight scream.\n");
  add_listen("scream",
    "From deeper within the caves you hear a bloodcurddling scream.\n");
  add_smell("main", "You smell the acrid stench of sulfar.\n"); 
  add_exit(RMS+"cots02","north");
  add_exit(RMS+"cots04","east");
  add_object(NPC+"salamite2.c");
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
  add_action("block_movement","east");
}

/* 
 *  ***********************************************************************
 *  Function:    block_movement 
 *  Description: blocks players progress when a mob is in the room
 *  Arguments:   none
 *  ***********************************************************************
 */

block_movement() {
  object mob;
  if(mob = present("salamite")) {
    write("The "+mob->query_name()+" blocks your way.\n");
    return 1;
  }
}

