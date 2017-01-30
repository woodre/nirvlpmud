#include "/players/linus/def.h"
inherit "/room/room.c";
int i;
  reset(arg){
   if(!present("critter",TO)) {
    for(i=0; i<random(5); i++) {
     MO(CO("/players/linus/Newbie/NPC/critter.c"),TO);
}
}
    set_light(1);
    short_desc = GRN+"The hundred acre wood"+NORM;
    long_desc = GRN+
   "A light breeze blows through the forest, making the tall trees\n"+
   "that grow in the forest sway gently.  A small stream flows to the\n"+
   "north, and a dirt footpath follows alongside the stream.  A small\n"+
   "fence surrounding a tall oak tree can be seen to the west.\n"+NORM;
      items = ({
    "trees","Mostly oak trees, but there are others growing here too",
    "path","Brown dirt where grass will no longer grow",
    "forest","The forest consists mostly of trees, many standing for years",
    "footpath","Brown dirt where grass will no longer grow",
    "intersection","The dirt path branches off in different directions further east",
    "stream","Clear water that splashes over rocks and weaves throughout the forest",
    "rocks","Different sized rocks are in the stream",
    "fence","A small wooden fence that surrounds an oak tree to the west",
    "tree","A tall oak tree that stands to the west" });
      dest_dir = ({
       NEWB+"n4.c","east",
       NEWB+"n8.c","west"  });
  }
init() {
 ::init();
 add_action("Listen","listen");
}
Listen() {
 write("The chirping songs of birds and the water as it splashes over some\n");
 write("rocks in the stream can be heard.\n");
 return 1;
}
