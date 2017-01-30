#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_sword.c", "sword");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   The hallway here ends and T's leading to the north and south.  The\n"+
"walls and floor here are deeply scorched and blasted.  The ceiling is\n"+
"mostly intact with only a few cracks on its surface. The hallway also\n"+
"leads back to the west.\n";

items = ({
  "walls",
  "You're not sure what could have done such damage, but it is\n"+
  "extensive",
  "floor",
  "It is blackened and torn up in several places, the stones tossed about"+
  "the room haphazardly",
  "stones",
  "Torn from the floor, it seems from the looks of them that great claws"+
  "were used to tear them away",
  "ceiling",
  "It seems to be in good shape considering the condition of the rest of\n"+
  "of this place",
  "cracks",
  "Most likely formed from weathering and the heat that was in this place"
  
});

dest_dir = ({
  RMS+"r10.c","north",
  RMS+"r09.c","south",
  RMS+"r06.c","west",
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
