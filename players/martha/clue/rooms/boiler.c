#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("rat",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/rat.c"), this_object());
	if(!present("rat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/rat.c"), this_object());
	if(!present("rat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/rat.c"), this_object());
	if(!present("rat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/rat.c"), this_object());
	if(!present("rat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/rat.c"), this_object());
			}*/
	
	if (arg) return;
	set_light(0);
	short_desc = HIY+"The Boiler Room"+NORM;
	items = ({
		"boiler","A tank that holds and warms water",
		"room","A dark, musty room",
		"steam","White tendrils of smoke",
		"tank","A rusty tub that holds water",
		"top","The top of a rusty boiler",
		"floor","The floor is cold, hard, and dusty gray cement",
		"mound","A pile of rat poop",
		"feces","It's shit, what did you expect!",
		"decay","This is a rotten pile of shit",
		"layer","A covering of dust",
		"dust","Not a lot, just a thin layer",
		"light","An empty socket",
		"ceiling","You can see nails from the first floor",
		"bulb","Duh, there is no bulb!",
		"socket","This is where the bulb would be"});
		
	long_desc =
"	The boiler room is hot and musty.  Steam billows out of the top\n\
of the rusty tank, like a man blowing smoke from a pipe.  On the\n\
floor near the tank there is a mound of feces that appears to be\n\
decaying.  The cement floor is cold and hard.  A thin layer of dust\n\
has settled on the floor only to be disturbed by some sort of rodent.\n
It seems there was once a light hanging down from the ceiling, but\n\
where the bulb should be is just an empty socket\n";
	dest_dir = ({"players/martha/clue/rooms/basement","south"});
}
