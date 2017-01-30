#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(26, 15, "ice", "ice_lajatang.c", "lajatang");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   Beyond the secret wall you find yourself in a skillfully crafted\n"+
"hallway.  This area seems completely untouched by the ravages that\n"+
"befell the outside structure.  A short hallway leads south to a well\n"+
"lit room\n";

items = ({
  "wall",
  "It has sealed itself shut, leaving no trace at all of its\n"+
  "existence, although you know at anytime you can leave",
  "hallway",
  "The hallway here has been spared the torment of the ruins, its\n"+
  "stone walls holding strong against the evil that pervades this\n"+
  "cursed place"
});

dest_dir = ({
  
  RMS+"r09.c","wall",
  RMS+"r18.c","south",
  
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}
