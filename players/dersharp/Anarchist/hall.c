inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="The Guild hall";
   long_desc= "	You find yourself in a cavern of dense black rocks.\n"+
              "You see the vortex and there is also a sign that you\n"+
              "should read.\n"+
              "You see the vortex.\n";
   set_light(1);
   dest_dir =
   ({
   });
   items=
   ({
		"sign","	This sign is a listing of the things available\n"+
                       "to do in this room.  It includes `Anarchist' and `list'\n",
   });
}
init() {
   ::init();
   add_action("Ana_Promo","list");
   add_action("Ana","Anarchist");
   add_action("Enter","enter");
}
Enter(arg){
   if(arg=="vortex"){
      write("You enter the vortex once again..........\n");
      write("You are able to keep your eyes open this time!\n");
      write("You see horrors beyond description as you are buffeted\n"+
            "time and space.\n");
      write("You scream!!!!!\n");
      write("You find yourself in the pool room.....\n");
      say(Tpn+" is sucked into the vortex.\n");
      move_object(tp, Road+"anarch");
      return 1;
   }
   write("Say again?\n");
   return 1;
}
Ana_Promo(){
   cat("/players/dersharp/Anarchist/news");
   write("For more information....type Anarchist\n");
   return 1;
}
Ana(){
   cat("/players/dersharp/Anarchist/Promo");
   return 1;
}
