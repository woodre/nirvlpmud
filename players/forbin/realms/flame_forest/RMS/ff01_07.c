/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Room
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.10 -Forbin
 *  Notable Changes:
 */

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/forbin/closed/std/flame_forest_baseroom.c"; 

int Found;

reset(arg) {
  if(!present("ff_mob") && !random(2)) add_object(NPC+"forestmob.c");    
  if(!present("ooomani_rutuu")) add_object(NPC+"ooomani.c");
  if(arg) return;
  short_desc = FLAMEFOREST;
  long_desc = 
    "  The charred forest clears into a small opening as trees on both\n"+ 
    "sides grow thickly into a sheer cliff wall.  The ashen ground is\n"+
    "void of any kind of growth, except for several thicket-like bushes.\n"+
    "The stars above cast a pale light across the area, while a gentle\n"+
    "breeze swirls about.\n";
  add_item("forest",
           "The forest, along with the cliff wall creates a safe, open area");
  add_item(({"tree","trees"}),
           "The trees grow right up closely to the cliff wall");
  add_item(({"cliff","wall","cliff wall"}),
           "Slick as glass, the cliff wall towers straight up into the sky");
  add_item("ground",
           "The ground is covered with a dark black ash");
  add_item(({"bush","bushes","thicket"}),
           "Very thorny and tightly tangled, the bushes look oddly out of place");
  add_item("stars",
            "The stars shine brightly as small pinpoints of light");
  add_listen("main", 
             "A breeze whistles by your ear.\n");
  set_light(1);
  if(!random(3)) add_property("NT");
  add_exit(RMS+"ff02_07","south");
  add_exit(RMS+"ff02_06","southwest");
  Found = 0;  
}

query_ffroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ffroom() && this_player()->query_level() < 40) return HBRED+HIW+FLAMEFOREST+NORM+NORM; 
      else { 
        sh = HBRED+HIW+short_desc+HBRED+HIW+" [";
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HBRED+HIW+"]";
        return sh+NORM+NORM; 
      }
    }
    else return HBRED+HIW+FLAMEFOREST+NORM+NORM;   
  }
  else return "Dark room";     
}

init() {
  ::init();
  add_action("cmd_enter","enter");
  add_action("cmd_search","search");
}

okay_follow() { return 1; }

cmd_enter(string str) {
  if(!Found) { 
    notify_fail("What?\n"); 
      return 0; 
  }
  if(!str || (str != "cave")) { 
    notify_fail("Enter what?\n"); 
      return 0; 
  }
  write(HIK+"You carefully duck your head as you enter the cave.\n"+NORM);
  say(HIK+this_player()->query_name()+" enters the cave.\n"+NORM);
  move_object(this_player(),"/players/forbin/realms/salam/RMS/cots01.c");
  command("look",this_player());
  say(this_player()->query_name()+" enters the hallway.\n");
#ifdef SALLOG
  log_this(SALLOG, "entered the Caves of the Salaminte.");
#endif  
    return 1; 
}

cmd_search(string str) {
  if(str == "bush" || str == "bushes") {
    if(!Found) {
      write(HIK+"Carefully searching the bushes, you toss them aside to reveal a cave.\n"+NORM);
      say(HIK+this_player()->query_name()+" searches the bushes.\n"+NORM);
      found_it();
      return 1;
    }
    write(HIK+"You search the "+str+", but find nothing.\n"+NORM);
    say(HIK+this_player()->query_name()+" searches the bushes.\n"+NORM);
      return 1;
  }
  if(str == "cave") {
    if(!Found) {
      write("You don't see a cave here.\n");
      say(this_player()->query_name()+" looks around confused.\n");
        return 1;
    }
    write(HIK+"You search the opening of the cave, and notice faint light that flickers\n"+
          "deeper within the cave.\n"+NORM);
    say(HIK+this_player()->query_name()+" looks carefully at the cave.\n"+NORM);
      return 1;
  }
}

found_it() {
  long_desc = 
    "  The charred forest clears into a small opening as trees on both\n"+ 
    "sides grow thickly into a sheer cliff wall.  The ashen ground is\n"+
    "void of any kind of growth, except for several thicket-like bushes\n"+
    "that have been tossed into a pile.  The stars above cast a pale\n"+ 
    "light across the area; you can barely make out the darkened opening\n"+
    "of a cave in the face of the cliff.\n";
  add_item(({"cave","opening","darkened opening"}), 
           "A small cave has been carved into the side of a rocky cliff.  The\n"+
           "opening is perfectly square, though one can tell it has been carved\n"+
           "by hand.  A faint light can be seen flickering deeper within");
  Found++;
    return 1;
}



