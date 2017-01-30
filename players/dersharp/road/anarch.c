inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="The portal";
   long_desc= "	As you enter this room a suffusion of absolute evil rushes\n"+
              "through your soul.  You sense that this may be a temple to\n"+
              "some evil god or the like.  You feel your mind getting tired\n"+
              "and you want to leave this place now!  In the middle of the\n"+
              "chamber is a pool of some kind of liquid.\n"+
              "You also notice a near invisible vortex of some sort of energy....\n";
   set_light(1);
   dest_dir =
   ({
		Road+"roadnwsw","west",
   });
   items=
   ({
		"pool","	As you gaze into the calm pool you begin\n"+
                       "to see a large city.  Lights everywhere, strange\n"+
                       "moving contraptions and people dressed in outlandish\n"+
                       "clothing.  You could touch it.....",
                "vortex","	The air seems to be charged with some black\n"+
                         "energy.  Perhaps you could enter it?",
   });
}

/*  removed 5/7/00 (no longer in play) -Eurale
init(){
   ::init();
   add_action("Touch","touch");
   add_action("Touch","enter");
}
*/

Touch(arg){
   if(!arg){
      write("What do you wish to do?\n");
      return 1;
   }
   if(arg=="pool" || arg=="portal"){
      write("You feel yourself slowly sinking into the pool.\n");
      write("You close your eyes and suddenly you feel yourself hit a surface.\n");
      say(Tpn +" slowly sinks into the pool!\n");
      write("the portal does not seem to function as of yet.\n");
     /* move_object(tp, Quest+"swelch");*/
      return 1;
   }
   if(arg=="vortex"){
      write("You find yourself being flung in all directions at once.\n");
      write("Just as you think your mind is going to explode you feel your\n"+
            "body hit hard, cold stone.....\n");
      say(Tpn+" is sucked into the swirling vortex!\n");
      move_object(tp, Anarch+"hall");
      return 1;
   }
   write("I bet you would!\n");
   return 1;
}
