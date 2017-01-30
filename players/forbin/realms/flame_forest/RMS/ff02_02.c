/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Room
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.07 -Forbin
 *  Notable Changes:
 */

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/forbin/closed/std/flame_forest_baseroom.c"; 

object wiz;

reset(arg) {
  if(!present("ff_mob") && !random(2)) add_object(NPC+"forestmob.c");
  if(arg) return;

  wiz = clone_object("/players/forbin/realms/keats/NPC/wizard.c");
  switch(random(4))
  {
  	case 0:
      "/players/forbin/realms/flame_forest/RMS/ff06_06.c"->load_it();
      move_object(wiz, "/players/forbin/realms/flame_forest/RMS/ff06_06.c");
      break;
  	case 1:
      "/players/forbin/realms/flame_forest/RMS/ff02_08.c"->load_it();
      move_object(wiz, "/players/forbin/realms/flame_forest/RMS/ff02_08.c");
      break;
  	case 2:
      "/players/forbin/realms/flame_forest/RMS/ff03_09.c"->load_it();
      move_object(wiz, "/players/forbin/realms/flame_forest/RMS/ff03_09.c");
      break;
  	case 3:
      "/players/forbin/realms/flame_forest/RMS/ff05_07.c"->load_it();
      move_object(wiz, "/players/forbin/realms/flame_forest/RMS/ff05_07.c");
      break;                        
  }  
  
  short_desc = FLAMEFOREST;
  long_desc = "  A small clearing forms where ashen dirt has been pushed aside to\n"+
              "make a rough circular area.  Trees grow high about the perimeter of\n"+
              "this place, yet no other plant life can be seen.  Heavy pieces of ash\n"+
              "float around on the strong breeze and swirl about a strange circle of\n"+
              "stone inscribed in the center of the clearing.  Eight crystals hang\n"+
              "suspended above the circle.\n";
  add_item(({"clearing","area"}),
    "This area, with all the carefully done work, was almost surely built by\n"+
    "someone with a purpose");
  add_item("ash",
    "Large pieces of ash are carried about on the wind");
  add_item("dirt",
    "The dirt, piled high around the circle of stone is blackened with ash");
  add_item(({"tree","trees"}),
    "Several different species of trees tower over the area");
  add_item(({"circle","stone circle","stone"}),
    "The stone circle creates an enclosure almost 10 feet in diameter");
  add_item(({"rune","runes","symbol","symbols"}),
    "Though very strange looking, you believe you could read them");
  set_light(1);
  if(!random(3)) add_property("NT");
  add_exit(RMS+"ff01_02","north");
  add_exit(RMS+"ff02_03","east");
  add_exit(RMS+"ff03_02","south");
  add_exit(RMS+"ff02_01","west");
  add_object("/players/forbin/realms/crystals.c");
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
}

okay_follow() { return 1; }
