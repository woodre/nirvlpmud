#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  object angel;
  if(!present("archangel")) {
    angel = clone_object(NPC+"angel.c");
    angel->set_up(29, 13, "fire", "flaming_maul.c", "maul");
    move_object(angel, this_object()); 
  }
  if(!present("mane")) {
    move_object(clone_object(NPC+"shadowmane.c"), this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"   The tunnel here is very narrow, its walls crudely cut and\n"+
"blackened.  Straight ahead to the south the tunnel seems to\n"+
"dead-end. To the north is a large dark room.\n";

items = ({
  "walls",
  "Blasted and formed from intense heat, they are shaped\n"+
  "closer together than the other tunnels in the network",
  
});

dest_dir = ({
  RMS+"r13.c","north",
  RMS+"r15.c","south",
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
