/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Phish - Fee Area
//  Function:     Room
//  Create Date:  2004.09.02
//  Last Edit:    2004.09.02 -Forbin
//  Notable Changes:
*/

#include "/players/forbin/realms/ph/phdefine.h"
inherit "/players/forbin/closed/std/room.c";

#define SHORT "A Peruvian Bar"

reset(arg) {
  if(arg) return;
  short_desc = SHORT;
  long_desc = 
    "A sprawling monastery stands on a mountain clearing.  Situated on\n"+
    "a rocky plain, the entire compound is surrounded by a high stone\n"+
    "wall except for a large entryway.  A wide expanse of steps dozens\n"+
    "of treads high leads up to a long stone platform, where thick\n"+
    "columns support a thatched roof and provide protection from the\n"+
    "elements for the massive set of double doors that lead inside.\n";
  set_light(1);
  add_item(({"monastery","compound"}),
    "The tops of buldings peek above the encircling stone wall.  Most of\n"+
    "architecture looks similar to the main entryway.  Flags and penants\n"+
    "flap noisily about in the breeze");
  set_chance(3);
    add_msg("A strong wind rips across the area.");
    add_msg("Beautiful chimes bathe the monastery with a sweet sound");
    add_msg("Dirt and loose sand blow across the ground.");
  add_listen("main", 
    "Wind whips across the rocky plain.\n");
  add_listen("wind",
    "A roaring wind floats across the area from the southwest.\n");
  add_smell("main", 
    "The sweet smell of jasmine and vanilla hang in the air.\n"); 
  add_smell("jasmine",
    "You catch a strong whiff of jasmine.  It seems to be coming from\n"+
    "within the monastery.\n");
  add_smell("vanilla",
    "The scent of vanilla floats out from the monastery doors.\n");
  add_exit(RMS+"a_sdeck","out");
  add_property("NT");
  add_property("NF");  
}

okay_follow() { return 1; }

query_phroom() { return 1; }

query_ph_fee_room() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ph_fee_room() && this_player()->query_level() < 40) return HIM+SHORT+NORM; 
      else { 
        sh = HIM+short_desc+HIM+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIM+"]";
        return sh+NORM; 
      }
    }
    else return HIM+SHORT+NORM;   
  }
  else return "Dark room";     
}

init() {
  ::init();
  add_action("block_movement","out");
}

block_movement() {
  object mob;
  if(mob = present("monkey")) {
    write("The "+mob->query_name()+" blocks your way.\n");
    return 1;
  }
}