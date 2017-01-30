#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
  if(!present("bird", TO)) {
  MO(CO("/players/linus/Newbie/NPC/bird.c"),TO);
 }
      if(!present("eeyore",TO)) {
     MO(CO("/players/linus/Newbie/NPC/Eeyore.c"),TO);
}
   if(arg) return;
      set_light(1);
      short_desc = GRN+"An open meadow"+NORM;
      long_desc = GRN+
  "The sun shines brightly on this open meadow.  Lush grass covers\n"+
  "the ground, creating the illusion of a green carpet.  A small stream\n"+
  "trickles nearby, and a small wooden bridge is built over the stream,\n"+
  "linking the meadow with a footpath that leads into the forest.\n"+NORM;
      items = ({
      "sun","It is not wise to stare directly into the sun!",
      "woods","A wooded forest",
      "forest","A wooded forest",
      "rocks","Different sized rocks are in the stream",
      "trees","Trees that grow in the forest",
      "meadow","Lush green grass grows abundantly in the meadow",
      "grass","Lush green grass grows abundantly in the meadow",
      "opening","Lush green grass grows abundantly in the meadow",
      "stream","Clear water that splashes over rocks and weaves throughout the forest",
      "bridge","An old bridge made of misshapen boards.  It still appears to be rather sturdy",
      "path","A small dirt path that travels through the woods",
      "footpath","A small dirt path that travels through the woods",
      "dirt path","A small dirt path that travels through the woods"
    });
    dest_dir = ({
     NEWB+"n5.c","south"  });
   }
init() {
  ::init();
  add_action("Listen","listen");
}
Listen() {
  write("Water as it flows over some rocks in the stream, and the soft whistle\n"+
  "of the wind can be heard.\n");
 return 1;
}
