#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
   if(!present("critter",TO)) {
    MO(CO("/players/linus/Newbie/NPC/critter.c"),TO);
}
      set_light(1);
      short_desc = GRN+"The hundred acre wood"+NORM;
      long_desc = GRN+
  "A tall maple tree stands to the south of a small footpath.  A\n"+
  "gentle breeze blows through the area, making the trees sway ever so\n"+
  "slightly.  Some boards have been nailed to the tree, forming steps.\n"+
  "Looking up, a small house built in the tree can be seen.\n"+NORM;
      items = ({
       "tree","A large maple tree.  Some boards are nailed to it",
       "boards","Some boards nailed to the tree to form steps.  You could\n"+
                "'climb' the 'steps' to get to Owl's house",
       "steps","Some boards nailed to the tree to form steps.  You could\n"+
               "'climb' the 'steps' to get to Owl's house",
       "trees","Mostly oak trees, but there are others growing here too",
       "footpath","Brown dirt where grass will no longer grow",
       "path","Brown dirt where grass will no longer grow",
       "walkway","A small dirt walkway.  It connects the footpath with a\n"+
      "large maple tree",
       "house","A small house built into the tree"  });
      dest_dir = ({
       NEWB+"n11.c","east",
      NEWB+"n9.c","west" });
  }
 init() {
   ::init();
     add_action("climb_steps","climb");
    add_action("Listen","listen");
 }
 climb_steps(string str) {
    if(!str || str !="steps") { FAIL("Climb what?\n"); return 0; }
     if(str=="steps") {
     write("You climb up the wooden steps.\n");
     TP->move_player("up the wooden steps#"+NEWB+"n10a.c");
 return 1;
  }
}
Listen() {
 write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
