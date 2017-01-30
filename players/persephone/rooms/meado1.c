inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int i;
int t;
reset (arg){
 if(!present("bee")){
  for(i=0;i<3;i++){
   move_object(clone_object("players/persephone/monster/bbee"), TOB);
  }
 }
 if(!present("ant")) {
  for(t=0;t<4;t++){
   move_object(clone_object("players/persephone/monster/ant"), TOB);
  }
 }
 if (!arg){
  set_light(1);
  short_desc="Meadow of Love";
  long_desc="You are walking through the beautiful Meadow of Love. All around you\n" +
            "there are lovely wildflowers and you feel quite at ease walking through\n" +
            "the gorgeous flowers. To the north you see a fabulous valley unfortunately\n" +
            "it is fenced off for some unexplained reason and to the south the meadow\n" +
            "continues on.\n";
  dest_dir=({"players/persephone/rooms/clifft","north",
             "players/persephone/rooms/meado2","south",
  });
 }
}
realm() { return "NT"; }
