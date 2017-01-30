#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("bat",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/bat.c"), this_object());
	if(!present("bat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/bat.c"), this_object());
	if(!present("bat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/bat.c"), this_object());
	if(!present("bat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/bat.c"), this_object());
	if(!present("bat","this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/bat.c"), this_object());
			}*/
	
	if (arg) return;
	set_light(0);
	short_desc = HIK+"The Attic"+NORM;
	items = ({
		"attic","This darkness is call the attic",
		"dark","If you could see dark, it would be light",
		"dreary","It is too dark to see the dreariness, even with a light",
		"pieces","Various furniture bits are stored here",
		"furniture","It is hard to tell what kind of furniture this is as it is covered",
		"cover","This white sheet covers the furniture",
		"white","This is a white sheet",
		"sheet","This sheet is white and covers the furniture",
		"window","A dilapidated window that has a broken pane",
		"backyard","The everlong backyard looms ahead",
		"dogs","The dogs are too quick to be spotted",
		"dog","The dog is so fast you can't really spot it"});
		
	long_desc =
"	The attic is dark and dreary.  Many find that they need to bring a\n\
light source with them, be it a candle or a flashlight, in order to see\n\
anything at all.  There are a few pieces of furniture covered with white\n\
sheets sitting in the attic, it is otherwise empty. Or is it?  One lonely\n\
window looks out into the backyard where dogs are rumored to scurry\n\
about.  It is also rumored that one is unable to see the dogs.\n";
	dest_dir = ({"players/martha/clue/rooms/stairs2","down"});
}