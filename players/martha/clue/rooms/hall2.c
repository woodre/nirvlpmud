#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIB+"The Second Floor Hall"+NORM;
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
		"chandelier","This is a smaller version of the chandelier in the Grand Hall",
		"walls","These walls are lined with portraits and various doors",
		"speck","Surely you jest, there is not a speck of dust to be seen",
		"dust","The hall is so clean there is no dust to look at"});
		 
	long_desc = 
"	The second floor hall of the old Hill House is long and wide.\n\
Doors line the entire hall, making one wonder how many rooms there\n\
are on the second floor.  The floor is all wood and shines as if\n\
it has just been polished.  Portraits line the walls between\n\
doorways and there is not one speck of dust to be seen.  In the\n\
center of the hall there is a smaller version of the main halls\n\
chandelier hanging, smaller, but just as beautiful! Someone has\n\
given much care and attention to the hall.\n";
	dest_dir = ({"players/martha/clue/rooms/bed1","north",
				 "players/martha/clue/rooms/bed2","northeast",
				 "players/martha/clue/rooms/bed3","east",
				 "players/martha/clue/rooms/bed4","southeast",
				 "players/martha/clue/rooms/bathroom","south",
				 "players/martha/clue/rooms/bed5","southwest",
				 "players/martha/clue/rooms/closet","west",
				 "players/martha/clue/rooms/lounge2","northwest",
				 "players/martha/clue/rooms/stairs2","up",
				 "players/martha/clue/rooms/stairs1","down"});	 
	}
	