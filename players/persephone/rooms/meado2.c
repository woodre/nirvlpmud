inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int i;
int t;
 reset (arg){
 if(!present("ant")) {
  for(t=0;t<4;t++){
   move_object(clone_object("players/persephone/monster/ant"), TOB);
  }
 }
 if(!present("bee")){
  for(i=0;i<3;i++){
   move_object(clone_object("players/persephone/monster/bbee"), TOB);
  }
 }
if(!arg){
  set_light(1);
  short_desc="Meadow of Love";
  long_desc="You are walking through the beautiful Meadow of Love. All around you\n" +
            "you see beautiful wildflowers blooming all around you. To the south\n" +
            "there appears to be a hill while the meadow continues to the north.\n";
  dest_dir=({"players/persephone/rooms/meado1","north",
             "players/persephone/rooms/bhillb","south",
  });
 }
}
realm() { return "NT"; }
