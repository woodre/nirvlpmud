#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIK+"The Hall"+NORM;
	items = ({
		"hall","A long, dimly lit hallway",
		"doors","Mahogany doors line the entire hall",
		"door","A beautiful mahogany door that leads elsewhere",
		"doorway","Wood trim outlines the mahogany door",
		"doorways","Wood trim outlines the mahogany doors",
		"floors","Beautiful hard wood floors that are polished to a hilt",
		"floor","A beautiful hard wood floor that has been meticulously polished",
		"wood","Polished and spiffy looking wood lines the floor",
		"portrait","A portrait of a family member who once lived in Hill House",
		"portraits","Portraits of various family members who once roamed this hall",
		"wall","The wall is lined with portraits and various doors",
		"center","The middle of the hall",
		"chandelier","This is the biggest, most beautiful chandelier ever",
		"walls","These walls are lined with portraits and various doors",
		"speck","Surely you jest, there is not a speck of dust to be seen",
		"dust","The hall is so clean there is no dust to look at"});
		 
	long_desc = 
"	The grand hall of the old Hill House is long and wide.  Doors\n\
line the entire hall, making one wonder how many rooms are there\n\
inside this ancient mansion?  The floor is all wood and shines as\n\
if it has just been polished.  Portraits line the walls between\n\
doorways and there is not one speck of dust to be seen.  In the\n\
center of the hall there is an extremely elegant and enormous\n\
chandelier hanging, perhaps the biggest one ever! Someone has\n\
given much care and attention to the hall to make it welcoming\n\
to invited guests and strangers as well.\n";
	dest_dir = ({"players/martha/clue/rooms/ballroom","north",
				 "players/martha/clue/rooms/conservatory","northeast",
				 "players/martha/clue/rooms/billiard","east",
				 "players/martha/clue/rooms/kitchen","southeast",
				 "players/martha/clue/rooms/droom","south",
				 "players/martha/clue/rooms/study","southwest",
				 "players/martha/clue/rooms/library","west",
				 "players/martha/clue/rooms/lounge","northwest",
				 "players/martha/clue/rooms/stairs1","up",
				 "players/martha/clue/rooms/stairs3","down",
				 "players/martha/clue/rooms/door1","door1",
				 "players/martha/clue/rooms/door2","door2"});	 
	}
	