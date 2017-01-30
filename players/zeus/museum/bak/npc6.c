/*  The Museum of Legendary Warriors  - npc6 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-golem.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a circular shaped side room of the museum.  The smooth walls\n"+
"are all perfectly clear, allowing for a great view of space.  In the\n"+
"center of the room is the projection of a towering granite golem, with\n"+
"two miniature golems at its feet.  A window of text is being displayed\n"+
"to their side.  A soft light is being eminated by the ceiling.\n";
 set_light(1);
  items=({
	"walls",
"The walls are made of a perfectly clear material, quite similar to glass.\n"+
"Looking through the walls, the infinite blackness of space can be seen",
	"stars",
"Space is scattered with many tiny stars, all millions of miles away",
	"space",
"Outer space is so black and scatted with stars.  It is very beautiful",
	"ceiling",
"The ceiling is glowing softly, providing light for the room.  It is\n"+
"perfectly clear, allowing you to see straight though it",
    "text",
"The green text is is being projected a few feet above the ground to\n"+
"the right of the three golems.  It can be 'read'",
 });
 dest_dir=({ "/players/zeus/museum/hall5.c", "south", });
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
"The granite golem is one of the most powerful, and most horrific\n"+
"magical creations ever to be seen.  Known for its uncanny ability\n"+
"to produce miniature duplicates of itself, these golems have been\n"+
"known to take control of entire planets in very short amounts of\n"+
"time.  They are one of the many tools of destruction which have\n"+
"shown their ugly faces over the centuries of recorded history.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}

