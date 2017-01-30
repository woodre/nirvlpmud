inherit "/room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = "Deeper into the "+BOLD+GREEN+"Vale"+END;
	long_desc = "As you venture further into the "+BOLD+GREEN+"Vale"+END+" you begin\n"+
		"to think that perhaps this section is dedicated to the children.\n"+
		"All around the path you see small footprints, and ahead you think you\n"+
		"can make out a clearing amongst the trees. The joyous feeling around you\n"+
		"fills you with a sense of hope and youth. You begin to wonder if you\n"+
		"should continue on, and risk spoiling the childrens' fun, or if you\n"+
		"should turn back now.\n\n"+
		"You see you can go <north> into the clearing.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/flet/f2path1", "south",
		});

	items = ({
		"path", "Small footprints surround the dirt path going in both directions",
		"footprints", "Small footprints which you know were made by no adult.\n"+
			"You think that whoever made them was skipping",
		"clearing", "A rather large clearing up ahead, you think you can make out\n"+
			"some elvish forms moving about up there",
		});
	if(!present("elf_guard")) {
		move_object(clone_object("/players/pain/NEW/flet/Mon/elf_g.c"),this_object());
		return 1;
	}
	call_out("noises",10);
}

init() {
	::init();
	add_action("north","north");
}

north() {
	if(present("elf_guard")) {
		write("The guard orders you to stop, saying: \"This area is for our children\n"+
			"only, all others are not allowed.\"\n");
		return 1;
	}
	write("Satisfied at having murdered the dutiful guard, you move on.\n");
	this_player()->move_player("into the clearing#/players/pain/NEW/flet/f2path3");
	return 1;
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
	number = random(3);
if(present("elf_guard")) {
	if(number == 0) {
		tell_room(this_object(),"The guard clears his throat, hoping to get your attention.\n");
	}
	if(number == 1) {
		tell_room(this_object(), "The guard eyes younot wanting harm to come to the \n"+
			"children of the "+BOLD+GREEN+"Vale"+END+".\n");
	}
}
if(!present("elf_guard")) {
	if(number == 0) {
		/* noise 1 */
		tell_room(this_object(),"The silence echoes the murder of the faithful Elven Guard.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"You think you hear nature about you echoing, \""+RED+"MURDERER"+END+"\".\n");
	}
}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"You hear children playing happily in the clearing ahead.\n");
	}
	call_out("noises",20);
	return 1;
}
