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

reset(arg) {
  if(!present("ff_mob") && !random(3)) add_object(NPC+"forestmob.c");  
  if(arg) return;
  short_desc = FLAMEFOREST;
  long_desc = "/players/forbin/realms/flame_forest/RMS/ffbase.c"->get_random_descrip(); 
  set_light(1);
  if(!random(3)) add_property("NT");
  add_exit(RMS+"ff02_01","north");
  add_exit(RMS+"ff03_02","east");
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




