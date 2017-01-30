#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("mouse",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mouse.c"), this_object());
	if(!present("mouse",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mouse.c"), this_object());
	if(!present("mouse",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mouse.c"), this_object());
	if(!present("mouse",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mouse.c"), this_object());
	if(!present("mouse",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/mouse.c"), this_object());
		}*/
	
	if (arg) return;
	set_light(1);
	short_desc = HIM+"The Bedroom"+NORM;
	items = ({
		"bedroom","This is an unused bedroom",
		"furniture","There is no furniture, it was removed",
		"water","The water is dingy, with a thin film covering the top",
		"window","The window has blinds covering it",
		"blinds","The blinds are pulled shut and one is broken",
		"light","A beam of light coming through the broken blind",
		"pile","Eww, it's mouse turds",
		"feces","Eww, it's mouse poop",
		"corner","The corner has a small pile of crap in it"});
		
	long_desc =
"	This was once a spare bedroom.  All of the furniture has been removed\n\
and there is a bucket of dingy water underneath the window.  Someone must\n\
have been in the middle of cleaning when they were interrupted, leaving\n\
the room uncleaned.  The window has blinds that are drawn and one of them\n\
is cracked, letting one steam of light shine through.  There seems to be\n\
a small pile of mouse feces in the corner.\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","northeast"});
}
