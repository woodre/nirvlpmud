#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
   if(!present("christopher",TO)) {
   MO(CO("/players/linus/Newbie/NPC/Christopher.c"),TO);
}
      set_light(1);
      short_desc = "A small yard";
      long_desc =
 "The dirt path ends here, and the forest opens up to a small yard.\n"+
 "Neatly trimmed grass grows all around here, and several small trees\n"+
 "grow here and there throughout the yard.  A small white house stands\n"+
 "to the north, and a small red and white checkered blanket is laid out\n"+
 "on the grass, with a small basket nearby.  The trees of the forest\n"+
 "stand to the south, where the chatter of animals can be heard from\n"+
 "within.\n";
   items = ({
       "path","A small dirt path that travels through the forest",
       "dirt path","A small dirt path that travels through the forest",
       "yard","Neatly trimmed grass grows throughout the yard",
       "grass","Neatly trimmed grass grows throughout the yard",
       "house","A small white house stands to the north",
       "blanket","A "+HIR+"red"+NORM+" and "+HIW+"white"+NORM+" checkered blanket laid out to form a picnic area",
       "basket","A small wicker picnic basket",
       "trees","Various types and sizes of trees.  Some grow in the forest, some in the yard",
       "forest","The hundred acre wood"
});
   dest_dir = ({
 NEWB+"n11.c","south" });
 }
init() {
 ::init();
add_action("Listen","listen");
add_action("Enter","enter");
}
Listen() {
 write("The sound of animals chattering from within the forest can be heard.\n");
 return 1;
}
Enter(str) {
 if(!str || str!="house") { FAIL("Enter what?\n");return 0; }
  write("You cannot enter the house.\n"+
        "Perhaps sometime in the future you will be able to.\n");
return 1; }
