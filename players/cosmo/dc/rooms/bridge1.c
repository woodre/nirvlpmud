#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = MAG+"14th Street Bridge"+NORM;
    no_castle_flag = 0;
    long_desc = 
        "   You stand on a large aging bridge which spans across the\n"
        + "rapidly flowing Potomac River.  Cars whiz past you, forcing\n"
        + "you to stay close to the side walls.  Looking out on the\n"
        + "river you see people fishing and boating as well as a few\n"
        + "small sailboats.  Across the bridge, off on the horizon,\n"
	+ "you can see the many monuments that grace the skyline of\n"
	+ "the nation's capital -- Washington D.C.\n"
        + "\n";

    items = ({
	"river", "A filthy polluted river.  Who knows what's down there",
	"bridge", "An old bridge with 3 lanes of traffic in each direction",
	"cars", "A flashy sportscar catches your attention",
    });
    dest_dir = 
        ({
	DCSTR+"s001", "city",
        DCDIR+"rooms/entrance", "back",
         });
}

init() {
	::init();
        add_action("enter","enter");
}

enter(arg) {
   if(!arg) {
      write("What would you like to enter?\n"); return 1; }
   if(arg !="sportscar") {
      write("You can't go there!\n");
      return 1;
   }
   write("You give the driver a wink as you slip into the passenger's seat.\n");
   say(capitalize(TPQN)+" hops into the sportscar.\n");
   TPMP("mysteriously#/players/cosmo/dc/rooms/sportscar.c");
   return 1;
}
