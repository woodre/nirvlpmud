inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="An opening";
   long_desc= "	You are now in an opening among the rocks.  You see a\n"+
              "shimmering piece of circular obsidian in the middle.  You\n"+
              "have a sense of dread about the circle of stone.  But\n"+
              "perhaps you might be able to figure out what it is if you\n"+
              "look at it.\n";
   set_light(1);
   dest_dir =
   ({
		Road+"roadnw","southeast",
   });
   items=
   ({
		"circle","	The stone is as smooth as glass and you\n"+
                         "feel yourself slowly drawn into it, until you\n"+
                         "finally pull yourself back quickly\n",
		"stone","	The stone is as smooth as glass and you\n"+
                         "feel yourself slowly drawn into it, until you\n"+
                         "finally pull yourself back quickly\n",
		"rock","	The stone is as smooth as glass and you\n"+
                         "feel yourself slowly drawn into it, until you\n"+
                         "finally pull yourself back quickly\n",
   });
}
init(){
   ::init();
   add_action("Touch","touch");
   add_action("Touch","enter");
}
Touch(arg){
   if(!arg){
      write("What do you wish to do?\n");
      return 1;
   }
   if(arg=="stone" || arg=="circle" || arg=="portal"){
      write("You feel yourself sucked into the obsidian circle with a\n"+
            "power that astonishes you.\n");
      write("You close your eyes and suddenly you feel yourself hit a surface.\n");
      say(Tpn +" is sucked into the obsidian portal!\n");
      write("I am truly sorry but I have yet to complete Greyhawk.\n");
     /* move_object(tp, Grey+"greyhawke");*/
      return 1;
   }
   write("Not here you don't!!\n");
   return 1;
}
