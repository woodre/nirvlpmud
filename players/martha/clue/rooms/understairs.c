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
	short_desc = HIC+"The Room Under the Stairs"+NORM;
	items = ({
		"room","This is the room under the stairs",
		"stairs","The backside of the stairwell",
		"cobwebs","Big stringy webs made by dust and spiders",
		"broom","An old, chipped wooden broom",
		"dustpan","An old metal dustpan",
		"turds","These are jellybean shaped pieces of shit",
		"floor","A gray cement floor covered in shit"});
		
	long_desc =
"	This is a small room underneath the stairs.  There is only room\n\
for a short person to stand or a tall person to crouch down.  There\n\
is no furniture in this room, only cobwebs.  A broom and dustpan are\n\
in the corner.  There are rat turds all over the floor.\n";
	dest_dir = ({"players/martha/clue/rooms/basement","east"});
}
