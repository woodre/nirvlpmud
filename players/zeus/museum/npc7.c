/*  The Museum of Legendary Warriors  - npc7 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-bug.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a side room of the museum.  Located directly in the center\n"+
"of the room is a holographic projection of a large mass of black bugs.\n"+
"There are also many holographic bugs flying around the room haphazardly.\n"+
"There is a some text being display to the right of the mass of bugs.\n"+
"A soft light is coming from the ceiling, providing light for the room.\n"+
"All the walls are perfectly clear.\n";
 set_light(1);
 items=({
	 "chip",
"The tiny computer chip is embedded in the floor.  It is projecting the\n"+
"image of the bug storm and all the bugs, as well as the text",
	 "floor",
"The floor is perfectly clear, allowing you to see straight through it",
	 "text",
"The text seems like it's floating in mid air.  It can be 'read'",
	 "walls",
"The walls of the room are perfectly clear, allowing you to see straight\n"+
"through them.  They are made of a material unknown to you",
	 "ceiling",
"The ceiling is perfectly clear, and glowing softly.  It is made of a\n"+
"material unknown to you",
	 "space",
"Outer space is very black.  It is a beautiful sight to see",
	 "stars",
"There are many stars scattered across the blackness of space",
 });
 dest_dir=({ "/players/zeus/museum/hall5.c", "north", });
}

void init(){
	::init();
	add_action("read_cmd", "read");
}

status read_cmd(string str){
	if(!str) return 0;
	if(str == "text")
	{
		write("The text reads:\n"+
"What stands before you is the mighty bug storm.  What the bug storm is,\n"+
"is a giant group of insects controlled by one single consciousness.\n"+
"While these bugs are not your typical fighters, they have been credited\n"+
"with destruction all across the known galaxy.  Once they have spent\n"+
"some time on any planet, their numbers grow so incredibly fast that\n"+
"their pestilence can not be stopped, until the entire planet is devoid\n"+
"of life.  As far as we know, no more of these creatures exist outside\n"+
"of captivity.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}
