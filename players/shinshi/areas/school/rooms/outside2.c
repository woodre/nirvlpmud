inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "Doors to the Gymnasium";
	long_desc =
		"You have reached the gymnasium doors. There are large panes of\n"+
		"glass around the building. There's a large bench with phone numbers\n"+
		"written all over it of past students and current students. There\n"+
		"are two dark red doors that lead into the gymnasium.\n";

items =

({
	"doors",
	"Two dark red doors lead into the gymnasium. Try 'enter'ing them",
	"glass",
	"The large panes of glass provide a beautiful scenary of the school"
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/entrance.c",	"southeast",
	});
}

init(){
::init();

add_action("enter","enter");
}

enter(str){
if(!str)
{
	wrote("What would you like to enter?\n");
	return 1;
}

if(str != "doors")
{
	write("You cannot enter that!\n");
return 1;
}
if (str == "doors")
{
call_other(this_player(), "move_player","enter#players/shinshi/areas/school/rooms/gymnasiumlob.c");
return 1; }
}
