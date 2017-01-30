#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_spear.c", "spear");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   You enter into a black room, its walls deeply scorched and melted. The\n"+
"west wall seems to be especially blasted, some of its rock still smoldering\n"+
"with a faint glow.  The tunnel leads back to the east.\n";

items = ({
  "walls",
  "As with the other areas of the tunnels they are blasted\n"+
  "and shaped by way of intense heat",
  "west wall",
  "It appears upon closer inspection that it has been\n"+
  "recently shaped by fire. It glows with a cooling heat",
  "wall",
  "It appears upon closer inspection that it has been\n"+
  "recently shaped by fire. It glows with a cooling heat"
});

dest_dir = ({
  RMS+"r15.c","east",
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
