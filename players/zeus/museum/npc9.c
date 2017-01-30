/*  The Museum of Legendary Warriors  - npc9 */

inherit "room/room";
#include "/players/zeus/closed/all.h"

reset(arg){
	if(arg) return;

	MO(CO("/players/zeus/museum/OBJ/p-ani.c"), TO);

 short_desc="The Museum";
 long_desc=
"This is a beautiful side room of the museum.  All of the walls are\n"+
"perfectly clear, allowing you to see many stars.  In the center of\n"+
"the room is a hologram of Ani.  There is some text being displayed\n"+
"in the air to her right.  A soft light is being eminated from the\n"+
"ceiling.  The exit leads to the north, into the main hallway.\n";
 set_light(1);
 items =({
	"stars", 
"The distant stars have never looked more beautiful",
	"ceiling",
"The ceiling is eminating a soft light upon the room.  It is perfectly\n"+
"clear, made of a material unknown to you",
	"text",
"The green text is being projected in the air to Ani's right.\n"+
"It can be 'read'",
	"walls",
"The walls are all perfectly clear, allowing for a beautiful view\n"+
"of outer space.  They are made of a material unknown to you",
	});
 dest_dir=({
	 "/players/zeus/museum/hall2.c", "north",
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
"Ani became a legend in her own time.  She was blessed from birth as\n"+
"one of the true holders of power.  Very few people have ever become\n"+
"complete masters of magic, Ani is one of them.  We say 'is' because\n"+
"she is still alive today, her strength is an immortal force that will\n"+
"never cease.  She has always been more of a leader than a fighter,\n"+
"however her skills in combat are now some of the best.\n");
		say(TP->QN+" reads the text.\n");
		return 1;
	}
	else return 0;
	return 1;
}