/*  The Museum of Legendary Warriors  - npc8 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-light.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a side room of the museum.  Directly in the center of the room\n"+
"is a holographic projection of a creature made of pure light.  All of\n"+
"the walls are perfectly clear, allowing you to see the stars.  There\n"+
"is a window of text being displayed to the side of the creature.\n";
 set_light(2);
 items=({
	 "walls",
"The walls are made of a clear material similar to glass.  They are\n"+
"perfectly clear.  As you look through them you can see the infinite\n"+
"blackness of space, scattered with many distant stars",
	"chip",
"There is a tiny electronic chip embedded in the floor, projecting\n"+
"the image of the light, as well as the text",
     "space",
"Outer space looks very beautiful",
     "stars",
"The distant stars are twinkling in space.  They are truly beautiful",
     "ceiling",
"The ceiling is perfectly clear, and through it space can be seen.  The\n"+
"ceiling itself is glowing softly, providing light for the museums halls",
	"text",
"The window of text, which can be 'read', is being projected to the\n"+
"side of the projection of the creature",
 });
 dest_dir=({ "/players/zeus/museum/hall5.c", "west", });
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
"The creature that you see before you has come to be called 'enchanted\n"+
"'light.  It is a very unique being, made from pure light.  It's exact\n"+
"origin is not known, what is known is the destruction caused by this\n"+
"monstrosity.  Whenever it would encounter an inhabited planet, it would\n"+
"slowly work its way across the entire thing, destroying everything in\n"+
"its path.  There is no known way to fight it, however it is able to\n"+
"be trapped in an ice prison.  Fortunatly for you, if you should choose\n"+
"to fight this monster, it will be slightly 'toned down' for you.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}