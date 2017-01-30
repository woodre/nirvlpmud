inherit "room/room";
#include "/players/pain/NEW/Guild/Rooms/defs.h"

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = BOLD+RED+"Road to the Citadel"+END;
    long_desc = 
            "The road to the famed "+CIT+" meets the path about citadel\n"+
	    "here at the towering gates. The citadel rises up out of the plains\n"+
	    "disruption admidst the peaceful surroundings. The ebon hue of the\n"+
	    "walls of the citadel seem to absorb the light around it. The huge\n"+
            "maw of the gates is most compelling.\n";

items = ({
	"road","The road is wide enough for 12 men to walk abreast and terminates at the "+CIT,
        "pattern","The cobblestones pave the road in a tight, precise pattern",
	"path","A well-worn patrol path encompasses the citadel",
	"gates","A HUGE iron gate stands open beckoning new recruits to enter the "+CIT,
});
dest_dir = ({
	PATH+"2.c", "north",
	PATH+"0.c", "south",
	PATH+"35.c", "east",
	PATH+"4.c", "northeast",
	PATH+"5.c", "northwest",
});


}
