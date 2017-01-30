inherit "/room/room";
#include "/players/pain/color.h"

int murder;

set_murder(str) { murder = str; }
query_murder() { return murder; }

reset() {
	short_desc = "The Childrens' "+BOLD+GREEN+"Clearing"+END;
	long_desc = "As you enter the "+BOLD+GREEN+"Clearing"+END+" the children run\n"+
		"in fright, having seen the murder of the guard. The peaceful play\n"+
		"area of the Elven Children has been tainted with the murder of their\n"+
		"guard. The once peaceful "+BOLD+GREEN+"Vale"+END+" has been irrevocably changed.\n"+
		"You wonder what this change might mean for the fragile peace that exists\n"+
		"between the Dwarves, Elves and Humans.\n\n"+
		"You see that you can leave the clearing by going <south>.\n";

	set_light(1);
	
	items = ({
		"children", "A scared group of Elven children",
		});
	if(!present("elf_child")) {
		move_object(clone_object("/players/pain/NEW/flet/Mon/elf_c.c"),this_object());
		move_object(clone_object("/players/pain/NEW/flet/Mon/elf_c.c"),this_object());	
		move_object(clone_object("/players/pain/NEW/flet/Mon/elf_c.c"),this_object());	
	}
	call_out("noises",10);
}

init() {
	::init();
	add_action("south","south");
}

south() {
	if(!present("elf_child")) {
		this_object()->set_murder(1);
		this_player()->move_player("out of the clearing#/players/pain/NEW/flet/f2path2");
		return 1;
	}
this_player()->move_player("out of the clearing#/players/pain/NEW/flet/f2path2");
return 1;
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
	number = random(3);
if(present("elf_child")) {
	if(number == 0) {
		/* noise 1 */
		tell_room(this_object(),"One of the Elven children cries quietly in fear.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"An Elven child sobs and sniffles.\n");
	}
}
if(!present("elf_child")) {
	if(query_murder() < 1) { this_object()->set_murder(1); }
	if(number == 0) {
		tell_room(this_object(),"The silence serves as a memorial to the murdered children.\n");
	}
	if(number == 1) {
		tell_room(this_object(),"All of nature around you seems to echo, \""+RED+"MURDER"+END+"\"\n");
	}
}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"The wind softly blows through the clearing.\n");
	}
	call_out("noises",20);
	return 1;
}
