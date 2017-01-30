#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_scythe.c", "scythe");
    move_object(angel, this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   Following the tunnel you find that instead of a dead-end it veers\n"+
"sharply to the west, leading to a dark room.  A small trickle of vile\n"+
"black water drips from a crack in the blackened walls.  The tunnel also\n"+
"leads back to the north.\n";

items = ({
  "water",
  "Disgusting stagnant water that reeks of sulfur",
  "crack",
  "A small crack that has formed in the blackened wall",
  "walls",
  "Blackened from some unknown source of great heat, they seem\n"+
  "to have been formed by melting"
});

dest_dir = ({
  RMS+"r14.c","north",
  RMS+"r16.c","west",
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