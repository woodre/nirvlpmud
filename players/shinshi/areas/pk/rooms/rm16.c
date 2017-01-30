inherit "/players/shinshi/areas/pk/rooms/tourney_room.c";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	long_desc =
		"The Colosseum measures fourty-eight meters high, one hundred and eighty-eight\n"+
		"meters long, and one hundred and fifty-six meters wide. The wooden arena floor\n"+
		"is eighty-six meters by fifty-four meters, and covered by sand. Its elliptical\n"+
		"shape keeps the players from retreating to a corner, and allows the spectators\n"+
		"to be closer to the action than a circle would.\n";

dest_dir =
({
	"/players/shinshi/areas/pk/rooms/rm12.c",	"north",
	"/players/shinshi/areas/pk/rooms/rm15.c",	"west",
});
}