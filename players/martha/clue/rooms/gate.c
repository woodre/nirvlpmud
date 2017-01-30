#include "ansi.h"
inherit "room/room";

	void reset (status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIR+"The Gate"+NORM;
	items = ({
		"driveway","Freshly paved asphalt",
		"house","The infamouse Hill House",
		"gate","Tall and wrought iron",
		"rain","Wet and beating down hard",
		"lightning","Streaks of lightning light up the sky"});
		
	long_desc =
"	A tall, wrought iron gate looms before you.  Within the gate is\n\
the infamous Hill House.  Rain beats down, lightning flashes across\n\
the sky and a loud clap of thunder booms.  Hearts skip a beat and it\n\
makes one wonder what is going on inside that creepy house?  Is it\n\
worth the risk to find out?  If so, drive on in, otherwise you might\n\
want to speed away!\n";
	dest_dir = ({"players/martha/clue/rooms/driveway","drive_in",
				 "players/martha/castle","speed_away"});
}
