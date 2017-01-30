#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_mace.c", "mace");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   Crawling down into the hole you find that the sides of the tunnel\n"+
"are smooth, as if the rock had melted then cooled as it ran.  The\n"+
"tunnel ends just a few feet away and opens up into darkness.  The\n"+
"tunnel also leads back up to the surface.\n";

items = ({
  "sides",
  "Smooth to the touch, what could have melted them in\n"+
  "this way?",
  "darkness",
  "You cannot see through it, especially from this angle",
  
});

dest_dir = ({
  RMS+"r10.c","up",
  RMS+"r12.c","down",
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