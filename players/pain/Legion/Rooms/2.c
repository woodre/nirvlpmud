inherit "room/room";
#include "/players/pain/NEW/Guild/Rooms/defs.h"

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = BOLD+RED+"The Citadel's First Floor"+END;
    long_desc = 
            "Young legionaires shuffle about the grand hall of the "+CIT+".\n"+
	    "The hall is expansive, like a covered arena, along every wall banners\n"+
	    "and battle flags from campaigns fought long ago hang down. The floors\n"+
	    "are spotless, evidence of the famed discipline of the Legionaires.\n"+
            "Standing in the center of the room is a statue dressed in armor.\n";

items = ({
	"statue","An impressive statue of a Legionaire in full battle regalia",
	"floor","The stone pavers that make up the floor are immaculate",
	"legionaires","Young men and women dedicated to duty, honor and their Master",
	"banners","The banners and flags hung about the hall are glorious reminders of victory",
	"flags","The banners and flags hung about the hall are glorious reminders of victory",
});
dest_dir = ({
	PATH+"3.c", "north",
	PATH+"1.c", "south",
	PATH+"4.c", "east",
	PATH+"5.c", "west",
	PATH+"6.c", "up",
	PATH+"26.c", "down",
});


}
