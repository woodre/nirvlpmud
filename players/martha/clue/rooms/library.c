#include "ansi.h"
inherit "room/room";

reset(arg) {
/*	if(!present("cop",this_object())) {
		move_object (clone_object("/players/martha/clue/mobs/cop.c"), this_object());
	}*/
	
	if (arg) return;
	set_light(1);
	short_desc = MAG+"The Library"+NORM;
	items = ({
		"rows","Various books in lines adorn the shelves",
		"row","A shelf lined with various books",
		"books","Various hard and soft covered books line the shelves",
		"book","A large hard covered book",
		"library","A beautifully preserved library",
		"door","The door looks much like the rest of the room, covered in books",
		"rolltop","This desk has the old fashioned rolltop to conceal what is inside",
		"desk","This in an old fashioned rolltop desk",
		"center","The center of the room",
		"papers","Various papers clutter the desk",
		"telephone","An older looking dial telephone",
		"carpet","Cream colored carpeting with vacuum marks up and down it",
		"shelves","Built into the wall, these shelves are packed with books",
		"dust","Ha! There is no dust here!",
		"brown","Brown leather armchairs and a couch",
		"leather","The leather is polished and brown",
		"armchair","A brown leather armchair",
		"armchairs","Brown leather armchairs",
		"couch","A brown leather couch that seats four people",
		"room","The room is dimly lit and full of books",
		"floor","The floor is carpeted",
		"lamps","Tall floor lamps with shades that contain the light",
		"lamp","A tall floor lamp that has a low wattage bulb in it",
		"hook","The telephone should be resting here and yet it is not"});
		
	long_desc =
"	Rows upon rows of books line the shelves of this well preserved\n\
library.  When the door is closed it is hard to find the way out as\n\
the door itself is also lined with rows of books.  There is an old\n\
rolltop desk in the center of the room.  The desk has various papers,\n\
books and a telephone on top of it.  The carpet is freshly vacuumed\n\
and the shelves are dust free and spotless.  Brown leather armchairs\n\
are scattered throughout the room and there is even a couch on the\n\
other side of the desk.  The room is lit by strategically placed\n\
floor lamps, which cause the room to seem dim.  The telephone is\n\
off the hook as though someone was interrupted halfway through a\n\
phone call.\n";
	dest_dir = ({"players/martha/clue/rooms/lounge","north",
				 "players/martha/clue/rooms/hall","east",
				 "players/martha/clue/rooms/study","south"});
}
			 