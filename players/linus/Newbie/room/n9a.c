#include "/players/linus/def.h"
inherit "room/room";
reset(arg) {
      if(!present("Heffalump",TO)) {
   MO(CO("/players/linus/Newbie/NPC/Heffalump.c"),TO);
}
      set_light(0);
      short_desc = GRN+"In the bushes"+NORM;
      long_desc = HIK+
 "Tightly clumped branches and leaves do a surprisingly good job\n"+
 "of preventing light from getting here.  Some dead leaves cover\n"+
 "the otherwise bare ground.  The sound of chirping birds can be\n"+
 "heard from overhead.\n"+NORM;
      items=({
              "branches","Small wooden branches that make up the bush",
              "leaves","Small green leaves that make up the bush",
              "dead leaves","Brown leaves that have fallen from the bush",
              "ground","Slightly moist dirt.  Some dead leaves are present" });
      dest_dir=({
        NEWB+"n9.c","out" });
}
init() {
 ::init();
 add_action("Listen","listen");
}
Listen() {
 write("The sound of birds chirping can be heard from overhead.\n");
 return 1;
}
