inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="A winding road";
   long_desc= "	You make your way among the fallen rock formations\n"+
              "and find yourself in a chamber of rock.  You sense a\n"+
              "a hidden evil to the east.  To the northeast and south\n"+
              " you see the chamber open to the sky. \n";
   set_light(1);
   dest_dir =
   ({
		Road+"anarch","east",
		Road+"roadnw","northeast",
                Road+"roadw","south",
   });
}
init() {
   ::init();
   add_action("Track","search");
}
Track(arg){
   if(!arg){
      write("You find some tracks leading to the east....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   if(arg=="room"){
      write("You find some tracks leading to the east....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   write("You cannot search that!\n");
   return 1;
}
