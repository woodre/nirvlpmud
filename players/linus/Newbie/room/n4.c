#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
      if(!arg) {
      set_light(1);
      short_desc = GRN+"The hundred acre wood"+NORM;
      long_desc = GRN+
  "The sound of water flowing can be heard here.  A small wooden\n"+
  "bridge crosses a stream to the north, where the forest opens into an\n"+
  "open meadow. A footpath forms an intersection here, allowing travel to\n"+
  "the west and east, as well as to the south.\n"+NORM;
       items = ({
      "trees","Mostly oak trees, but there are others growing here too",
      "forest","The forest consists mostly of trees, many standing for years",
      "intersection","The footpath branches into several different directions forming the intersection",
      "meadow","Lush green grass grows abundantly in the meadow",
      "grass","Lush green grass grows abundantly in the meadow",
      "stream","Clear water that splashes over rocks and weaves throughout the forest",
      "bridge","An old bridge made of misshapen boards.  It still appears to be rather sturdy",
      "rocks","Different sized rocks are in the stream",
      "path","Brown dirt where grass will no longer grow",
      "footpath","Brown dirt where grass will no longer grow"  });
 dest_dir = ({
         NEWB+"n3.c","south",
         NEWB+"n5.c","north",
         NEWB+"n9.c","east",
      NEWB+"n7.c","west"  });
  }
 }

init() {
 ::init();
 add_action("Listen","listen");
}
Listen() {
 write("The chirping songs of birds and the water as it splashes over some\n");
 write("rocks can be heard.\n");
 return 1;
}
