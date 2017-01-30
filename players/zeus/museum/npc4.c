/*  The Museum of Legendary Warriors  - npc4 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-jerek.c"), TO);

 short_desc="The Museum";
 long_desc=
"You are in a side room of the museum.  Directly in the center of the\n"+
"room is a life size holographic projection of the legendary warrior\n"+
"Jerek.  All of the walls are perfectly clear, allowing you to see the\n"+
"stars.  A window of text is being displayed to the side of Jerek.  A\n"+
"soft glow is eminating from the ceiling.\n";
 set_light(1);
 items=({
	 "chip",
"The little electronic chip is mounted to the floor, and is projecting\n"+
"the image of Jerek, as well as the text to its right",
     "text",
"The text is a dark green color, and is scrolling by slowly.  It is\n"+
"giving information about the great warrior Jerek.  It is obviously\n"+
"readable",
	"walls",
"All of the walls are perfectly clear, allowing you to see the stars\n"+
"outside the museum.  It is a very beautiful sight",
     "ceiling",
"The ceiling is perfectly clear, through which the blackness of space\n"+
"can be seen.  A soft glow is coming from the ceiling, providing light\n"+
"for the room",
	"stars",
"The stars look beautiful out there in space",
    "space",
"Outer space is black, and very beautiful.  It is scattered with stars",
 });
 dest_dir=({
	 "/players/zeus/museum/hall2.c", "south",
 });
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
"Jerek became known during the twenty-second century on Earth during the\n"+
"mutant slave rebellion.  Outfitted by a team of refugee doctors with\n"+
"strong metal plates beneath his skin, and razor sharp claws on his hands,\n"+
"he was able to lead the mutants against the humans and cyborgs.  He went\n"+
"down in history as one of the many leaders who was willing to stand up\n"+
"against tyranny and oppression.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}
