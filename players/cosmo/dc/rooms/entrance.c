#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = HIY+"Entrance to D.C."+NORM;
    no_castle_flag = 0;
    long_desc = 
        "   Welcome to Washington D.C. -- the capital of the U.S.\n"
        + "The city provides many opportunities for tourists and\n"
        + "adventurers.  Be sure to visit the many museums and monuments\n"
        + "which have grown over the years.  See the home of our\n"
        + "President, view the legislative power of Congress, shop\n"
	+ "along the streets of Georgetown, and much more.  A warning\n"
        + "to weak travelers:  Beware of the danger in "+RED+"Anacostia"
	+ NORM+".\n\n"
	+ MAG+"Three bridges"+NORM+" lie in front of you which lead"
	+ " to various parts\n"
	+ "of the city.  Choose your own destiny.\n\n";

    items = ({
          "bridges", "You see the 14th Street, Memorial, and Key Bridges",
    });

    dest_dir = ({
        DCDIR+"rooms/bridge1", "14th",
        DCDIR+"rooms/bridge2", "memorial",
        DCDIR+"rooms/bridge3", "key",
        "room/plane1", "out",
    });

   if(!present("wall", this_object())){
      move_object(clone_object(DCDIR+"dc_board.c"), this_object());
   }
   if(!present("sign", this_object())){
      move_object(clone_object(DCDIR+"dc_sign.c"), this_object());
   }
}
