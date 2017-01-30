inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
 if(!present("goat")){
  for(t=0;t<2;t++){
   move_object(clone_object("players/persephone/monster/goat"), TOB);
  }
}
 if (!arg) {
  set_light(1);
  short_desc="Cliff Path";
  long_desc="You are scrambling along a very rough and narrow path. Below you can\n" +
            "see the waves crash against the base of the cliff. As you gaze \n" +
            "towards the top of the cliff the way looks easier.\n\n";
  dest_dir=({"players/persephone/rooms/cliff_f2","up",
             "players/persephone/rooms/cliffb","down",
  });
 }
}
realm(){ return "NT";}
