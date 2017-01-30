#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {

  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   You find yourself in a large dark tunnel. The walls here are scorched\n"+
"and melted, parts of it pooled and lumped onto the floor.  A hole in the\n"+
"ceiling leads up to the ruins. The tunnel continues to the east.\n";

items = ({
  "walls",
  "They look to have been shaped by intense heat, as does\n"+
  "the entire room",
  "hole",
  "A hole that leads up to the ruins",
  "floor",
  "It is smooth to the touch, and seems to have been formed by melting",
  
});

dest_dir = ({
  RMS+"r11.c","up",
  RMS+"r13.c","east",
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
