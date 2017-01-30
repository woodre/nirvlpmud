/*  The Museum of Legendary Warriors  - npc5 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-sd.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a beautiful room in the museum.  All of the walls, including\n"+
"the floor and ceiling are crystal clearing, allowing you to see the\n"+
"stars and outer space.  In the center of the room is a holographic\n"+
"projection of the Smasher/Devourer.  It is taking up most of the\n"+
"room.  A panel of text is being displayed on each side of it.\n";
 set_light(1);
 items =({
	"stars", 
"The stars look incredibly beautiful",
	"space",
"The infinite blackness of outerspace is captivating",
	"ceiling",
"The ceiling is eminating a soft light upon the room.  You are able"+
"to see straight through it",
	"text",
"The green text is being projected in the air to the right of the\n"+
"holographic projection.  It can be 'read'",
	"walls",
"The walls are all perfectly clear, allowing for a beautiful view\n"+
"of outer space.  They are made of an unknown material",
	});
 dest_dir=({ "/players/zeus/museum/hall4.c", "north", });
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
"The mighty machine before you is a Smasher/Devourer module.  They\n"+
"were developed by the Humans in the mid 21st century by the gov.\n"+
"to 'help keep the peace'.  Their only purpose was to kill, and they\n"+
"proved to be one of the deadliest creations ever to be produced by\n"+
"the humans, up until the ill-fated global peace pact of 2113.  It is\n"+
"not known just how many deaths were caused by these monsters, but\n"+
"it is in the hundreds of millions to be sure\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}