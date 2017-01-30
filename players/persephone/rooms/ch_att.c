inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(0);
  short_desc="Large Attic";
  long_desc="You are standing in a large attic that is used as a storage area\n" +
            "scattered all around the room you can see various bits of bricabrac \n" +
            "and a small mattress in the middle of this vast room.\n" +
            "\n";
   items=({"bricabrac","Mostly junk that has no obvious value. Much of it seems\n" +
                       "to be broken and you doubt that searching would reveal\n" +
                       "anything of interest",
           "mattress","A lumpy old mattress that look oddly out of shape",
         });
 }
}
realm(){ return "NT";}
