/*  The Museum of Legendary Warriors  */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-mage.c"), TO);  

 short_desc="The Museum";
 long_desc=
"This is a small side room of the museum.  The walls are all crystal clear,\n"+
"providing a spectacular view of outer space.  Twinkling stars can be seen\n"+
"all around.  In the south end of the room stands a tall holographic image\n"+
"of a woman in a long robe.  Some text is being projected next to her.\n";
 set_light(1);
 items=({
	 "chip",
"The tiny computer chip is embedded in the floor.  It is projecting the\n"+
"image of Heldurabhoricka, as well as the text to her side",
	 "floor",
"The floor is perfectly clear, allowing you to see straight through it",
	 "text",
"The text is being projected to Heldurabhoricka's side.  It can be 'read'",
	 "walls",
"The walls of the room are perfectly clear, allowing you to see straight\n"+
"through them",
	 "ceiling",
"The ceiling is perfectly clear, and glowing softly",
	 "space",
"Outer space is a beautiful sight to see",
	 "stars",
"There are many stars scattered across the blackness of space",
 });
 dest_dir=({
	 "/players/zeus/museum/hall1.c", "north",
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
"Heldurabhoricka was a supreme mage who spent her days in the Gol'ba\n"+
"system.  She was a master of the ice magiks, and her skills won her\n"+
"many prizes, including the legendary Lifeblood Trials award when she\n"+
"was 130 years old.  According to legend, her robe was created by a\n"+
"cult of invisible monks who could speak with their minds.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}

