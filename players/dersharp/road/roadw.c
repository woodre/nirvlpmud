inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="A winding road";
   long_desc= "	The air becomes slightly warmer as you walk into this\n"+
              "area.  To the north a pathway leads into a jumble of \n"+
              "rocks, while to the east you see the road open up.  As\n"+
              "you stand here you get the feeling something is hidden\n"+
              "in this area.\n";
   set_light(1);
   dest_dir =
   ({
		Grey+"enter","east",
                Road+"roadnwsw","north",
   });
}
init() {
   ::init();
   add_action("Track","search");
}
Track(arg){
   if(!arg){
      write("You find some tracks leading to the north....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   if(arg=="room"){
      write("You find some tracks leading to the north....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   write("You cannot search that!\n");
   return 1;
}
