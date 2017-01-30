#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=RED+"Sportscar"+NORM;
   long_desc=
   "You hop into the flashy red sportscar.  Much to your disappointment,\n"+
   "the car is empty.  There is nothing to do here.\n"+
   "\n"+
   "UNDER CONSTRUCTION\n"+
   "\n"+
   "\n"+
   "\n",

   items=
   ({
     "i1","x",
     "i2","x",
     "i3","x",
     "i4","x\n"+
          "x",
    });

   dest_dir=
   ({
       DCDIR+"rooms/bridge1", "out",
   });

/*   if(!present("mon1", this_object())){
      move_object(clone_object("/players/cosmo/dc/mon/xx.c"), this_object());
   }
   if(!present("mon2", this_object())){
      move_object(clone_object("/players/cosmo/dc/mon/xx2.c"), this_object());
   }
*/
}

