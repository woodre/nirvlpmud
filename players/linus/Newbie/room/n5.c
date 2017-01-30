#include "/players/linus/def.h"
inherit "/room/room.c";
int i;
   reset(arg){
  if(!present("amphib",TO)) {
  for(i=0; i<random(3); i++) {
  MO(CO("/players/linus/Newbie/NPC/frog_turtle.c"),TO);
}
}
      set_light(1);
      short_desc = "A small bridge";
      long_desc =
  "The weathered boards creak and groan underfoot.  Guarding both sides\n"+
  "of the bridge are small wooden railings.  A stream splashes over some\n"+
  "rocks as it flows beneath the bridge.  To the north is a meadow, and\n"+
  "a footpath leads into a forest to the south.\n";
      items = ({
         "boards","Wooden boards that make up the bridge.  They are weathered, but sturdy",
         "forest","A small wooded forest",
         "meadow","Lush green grass grows abundantly in the meadow",
         "grass","Lush green grass grows abundantly in the meadow",
         "stream","Clear water that splashes over rocks and weaves throughout the forest",
         "bridge","An old bridge made of misshapen boards.  It still appears to be rather sturdy",
         "water","Clear water",
         "rocks","Different sized rocks are in the stream",
         "footpath","Brown dirt where grass will no longer grow",
         "path","Brown dirt where grass will no longer grow",
         "railings","Wooden railings that appear to be weathered",
         "railing","A wooden railing that appears to be weathered",
        });
       dest_dir = ({
           NEWB+"n6.c","north",
           NEWB+"n4.c","south"  });
 }
init() {
  ::init();
  add_action("Listen","listen");
}
Listen() {
 write("The creaking and groaning of the old boards as well as water splashing\n"+
       "over some rocks as it flows under the bridge can be heard.\n");
 return 1;
}
