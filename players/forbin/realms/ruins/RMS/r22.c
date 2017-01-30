#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";
int manes;
reset(arg) {
  if(!present("archangel")) {
    move_object(clone_object(NPC+"shadowangel.c"), this_object()); 
  }
  if(!present("shadowmane")) {
    for(manes = 0; manes < 3;  manes++) {
      move_object(clone_object(NPC+"shadowmane.c"), this_object());
    }  
  }
  if(arg) return;
set_light(1);

short_desc = RUINS;
long_desc =
"  This room looks to once have been a war room. A large map carved in\n"+
"stone stands against one wall. The rest of the room looks to have been\n"+
"burned and mutilated as badly as the hallway before it. An opening in\n"+
"the ceiling reveals the sky beyond and a torrent of dark clouds whipping\n"+
"by. This room has the feel of evil about it.\n";

items = ({
  "map",
  "Looking closely you see that the map shows detailed elements of the\n"+
  "land beyond",
  "wall",
  "It is burned badly and cracked",
  "sky",
  "Dark and foreboding, you wonder what could have such an effect on the\n"+
  "weather",
  "clouds",
  "They are dark and ugly, allowing very little light to filter through",
  "opening",
  "Too small to climb through, it seems to have been a result of damage\n"+
  "suffered by the building",
  "ceiling",
  "It is broken and partially torn down in multiple places"
  
});

dest_dir = ({
  RMS+"r21.c","west",
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
