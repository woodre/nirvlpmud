inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset(arg){
 if(!present("ant")) {
  for(t=0;t<4;t++){
   move_object(clone_object("players/persephone/monster/ant"), TOB);
  }
 }
 if(!present("woodpecker")){
  move_object(clone_object("players/persephone/monster/bird"), TOB);
 }
 if (!arg){
  set_light(1);
  short_desc="Blueberry Hill";
  long_desc="You are at the bottom of a small hill and by all appearences you guess\n" +
            "that this must be Blueberry Hill as there are berries growing all around\n" +
            "and there seems to be some willows around the hill as well. Perhaps\n" +
            "you might be lucky enough to find your thrill around here. There is\n" +
            "a path leading south up the hill and going north towards a meadow.\n" +
  "\n";
  dest_dir=({"players/persephone/rooms/meado2","north",
             "players/persephone/rooms/bhillm","south",
  });
 }
}
realm(){ return "NT";}
