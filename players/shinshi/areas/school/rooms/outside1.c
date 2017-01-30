inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Doors of the Main Building";
	long_desc =
		"As you approach the building, you come along three seperate\n"+
		"sets of dark red " +HIR+ "doors " +NORM+ "leading into the main building. Above the\n"+
		"doors are large windows where teachers whom are on hall duty can\n"+
		"have a full view of the students crossing the street to get to\n"+
		"the main building.\n";

items =

({
	"doors",
	"Three sets of doors lead into the large building. Try 'enter'ing them",
	"windows",
	"Large windows lie above the doors of the school"
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/entrance.c",	"southwest",
	});
}

init(){
::init();

add_action("enter","enter");
}

enter(str)
{
	if(!str)
	{
		write("What would you like to enter?\n");
		return 1;
	}
	
	if(str != "doors")
	{
		write("You cannot enter that!\n");
		return 1;
	}
	
	if (str == "doors")
	{
		call_other(this_player(), "move_player","enter#players/shinshi/areas/school/rooms/floor1/lobby.c");
		say(this_player()->query_name()+" enters the doors.\n");
	return 1;
	}
}
