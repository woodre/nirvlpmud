#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
    set_light(1);
    short_desc = GRN+"The hundred acre wood"+NORM;
    long_desc = GRN+
  "A gentle breeze blows through the forest, causing some leaves to\n"+
  "gently fall from the trees that grow here.  A small stream meanders\n"+
  "through the forest to the north.  A bush stands near a small footpath\n"+
  "that runs alongside the stream.\n"+NORM;
    items = ({
      "trees","Mostly oak trees, but there are others growing here too",
      "stream","Clear water that splashes over rocks and weaves throughout the forest",
      "path","Brown dirt where grass will no longer grow",
      "footpath","Brown dirt where grass will no longer grow",
      "rocks","Different sized rocks are in the stream",
      "forest","The forest consists mostly of trees, many standing for years",
      "leaves","Green leaves that grow on trees and bushes",
      "bush","A small green bush, full of leaves.  It appears that\n"+
      "it could be 'enter'd",
});
    dest_dir = ({
     NEWB+"n10.c","east",
     NEWB+"n4.c","west" });
  }
init() {
 ::init();
 add_action("Listen","listen");
 add_action("Enter","enter");
}
Listen() {
 write("The chirping songs of birds and the water as it splashes over some\n");
 write("rocks in the stream.\n");
 return 1;
}
Enter(string str){
   if(!str || str!="bush") { FAIL("Enter what?\n"); return 0; }
   if(str=="bush"){
  write("You push your way into the bush.\n");
  TP->move_player("into the bush#"+NEWB+"n9a.c");
 return 1;
}
}
