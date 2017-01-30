inherit "room/room";
#include "/players/pain/NEW/Guild/Rooms/defs.h"

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = BOLD+RED+"Road to the Citadel"+END;
    long_desc =
            "The road to the famed "+CIT+" runs north and south.\n"+
            "Rising up out of the plains to the north stands the Citadel, a large\n"+
            "archiac structure made to look even more menacing by contrast to its\n"+
            "surroundings. The road is cobblestone of the finest construction, the\n"+
            "tightly knit pattern a fine display of discipline. Discipline, the\n"+
	    "mark of the Legion.\n";
items = ({
	"road","The road is wide enough for 12 men to walk abreast and terminates at the "+CIT,
	"pattern","The cobblestones pave the road in a tight, precise pattern",
});
dest_dir = ({
	PATH+"1.c", "north",
});


}
