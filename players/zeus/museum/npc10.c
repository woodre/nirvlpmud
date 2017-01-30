/*  The Museum of Legendary Warriors  - npc10 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-blob.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is one of the smaller side rooms of the museum.  To the south is\n"+
"the exit that leads to the main hallway.  In the center of the room is\n"+
"a very monsterous looking projection of a green blob.  All of the walls\n"+
"are pefectly clear, and a soft glow is coming from the ceiling.  A\n"+
"window of text is being displayed in the room as well.\n";
 set_light(1);
 items=({
	 "chip",
"The little electronic chip is mounted to the floor, and is projecting\n"+
"the image of the King, as well as the text to its right",
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
"for the rooms of the museum",
	"stars",
"The distant stars look beautiful",
    "space",
"Outer space is very beautiful scattered with stars",
 });
 dest_dir=({
	 "/players/zeus/museum/hall4.c", "south",
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
"King Boul-Goruk was the most powerful leader of the mighty empire of\n"+
"Asytaine.  Over the 669 years that he ruled, he conquered over eleven\n"+
"quadrants of space, more than any other being had at the time.  His\n"+
"empire grew into one of the most powerful forces in the known universe.\n"+
"If not for the mysterious plague that paralyzed him, his reign of terror\n"+
"over the universe might never have ended.  His mace, which is one of a\n"+
"kind, was made with a substance whose origin is officially unknown.  It\n"+
"was a very powerful weapon of destruction.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}
