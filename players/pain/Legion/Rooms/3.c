inherit "room/room";
#include "/players/pain/NEW/Guild/Rooms/defs.h"

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = BOLD+RED+"The Path about the Citadel"+END;
    long_desc = 
            "The well worn path about the "+CIT+" looks out over\n"+
	    "plains here. To the south, the north gates of the Citadel rise up\n"+
	    "to meet the sky. The dark fortress seems to suck all light into it\n"+
	    "generating a menacing aura about it. Young legionaires guard the\n"+
            "north gates with dedication and discipline.\n";

items = ({
	"path","A well worn path winding about the "+CIT,
	"gates","A HUGE iron gate stands open beckoning new recruits to enter the "+CIT,
});
dest_dir = ({
	PATH+"2.c", "south",
	PATH+"4.c", "southeast",
	PATH+"5.c", "southwest",
});


}
