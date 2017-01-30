inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
 if (!arg) {
 if(!present("troll")){
  for(t=0;t<2;t++){
   move_object(clone_object("players/persephone/monster/stroll"), TOB);
  }
 }
  set_light(1);
  short_desc="Cliff Base";
  long_desc="You are at the base of a limestone cliff to the East you see a beach\n" +
            "while at your feet there is a narrow path that seems to be passable\n" +
            "leading up the cliff face. Splashing around your feet and to the North\n" +
            "is the cold Sea of Fate.\n";
  dest_dir=({"players/persephone/rooms/beach6","east",
             "players/persephone/rooms/cliff_f1","up",
  });
 }
}
realm(){ return "NT";}
