inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "A Rickety Seesaw";
	long_desc =
		"The seesaw, otherwise known as the teeter-totter, is a\n"+
		"long, narrow board suspended in the middle so that, as\n"+
		"one end goes up, the other goes down. This one, however,\n"+
		"looks like it would break if anyone would try to use it.\n"+
		"There is a ladder nearby that leads up into a tree.\n";

items =

({
	"board",
	"It looks like it is about to snap in half",
	"ladder",
	"It looks like you could climb the ladder if you wanted",
	"seesaw",
	"It looks like it is about to snap in half",
	"tree",
	"A large tree, full of life",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/outside4.c",	"east",
});
}

init(){
	::init();
	add_action("climb","climb");
}

climb(str){
	if(!str)
	{
		write("What would you like to climb?\n");
	return 1;
	}
	
	if(str != "ladder")
	{
		write("You cannot climb that!\n");
	return 1;
	}
	
	if (str == "ladder")
	{
		call_other(this_player(), "move_player","up the ladder#players/shinshi/areas/coining/rooms/outside6.c");
		say(this_player()->query_name()+" climbs the ladder.\n");
	return 1;
	}
}