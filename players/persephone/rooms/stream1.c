inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset(arg){
 if(!present("piranha")) {
  for(t=0;t<2;t++){
  move_object(clone_object("players/persephone/monster/pira"), TOB);
  }
 }
 if(!arg){
  set_light(1);
  short_desc="Stony Brook";
  long_desc="You are wandering along a small peaceful stony brook that meanders\n" +
            "down Blueberry Hill. On either side of the brook are some reeds and\n" +
            "a couple of large trees. To the north you can just make out the top\n" +
            "of the hill and to the south the brook appears to get larger.\n" +
  "\n";
  dest_dir=({"players/persephone/rooms/bhillt","north",
             "players/persephone/rooms/stream2","south"
  });
 }
}
realm(){ return "NT"; }
