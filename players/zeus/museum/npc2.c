/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-tolbrehn.c"), TO);  

 short_desc="The Museum";
 long_desc=
"You are standing in a small room in the museum.  To the north is a life\n"+
"size holographic projection of Tolbrehn.  A small computer chip in the\n"+
"floor is projecting the image, as well as some text just to it's side.\n"+
"The walls of the room are perfectly clear, allowing a beautiful view of\n"+
"outer space.  The ceiling is glowing softly.\n";
 set_light(1);
 items=({
	 "chip",
"The tiny computer chip is embedded in the floor.  It is projecting the\n"+
"image of Tolbrehn, as well as the text to his side",
	 "floor",
"The floor is perfectly clear, allowing you to see straight through it",
	 "text",
"The text seems like it's floating in mid air.  It can be 'read'",
	 "walls",
"The walls of the room are perfectly clear, allowing you to see straight\n"+
"through them",
	 "ceiling",
"The ceiling is perfectly clear, and glowing softly",
	 "space",
"Outer space is very black.  It is a beautiful sight to see",
	 "stars",
"There are many stars scattered across the blackness of space",
 });
 dest_dir=({
	 "/players/zeus/museum/hall1.c", "south",
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
"Tolbrehn was the master of the Shadowninja Clan during the early 21st\n"+
"century on planet Earth.  Trained in one of the deadliest hand to hand\n"+
"fighting styles known, he was admired and revered by almost all.  If it\n"+
"was not for his untimely death at the tender age of twenty-eight, he\n"+
"would have gone down in history as much more than a great fighter.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}
