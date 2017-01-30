inherit "/room/room";
#include <ansi.h>
int found;

reset(arg)
{
::reset(arg);
found = 0;

if(!present("shinshi_tampon_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/studenttampon.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "A well-made treehouse";
	long_desc =
		/*"A treehouse is a building constructed among the branches of\n"+
		"one or more trees, and is raised above the ground. Treehouses\n"+
		"are great for storing stuff. Maybe you can search through it and\n"+
		"find some treasures that the kids have stashed away.\n";*/
		"The treehouse is very worn down due to the weather of past years.\n"+
		"The floorboards that are still intact creak loudly as a heavy\n"+
		"wind passes by. As a hard wind passes, one of the floorboards\n"+
		"gives in and falls to the ground, leaving a small opening in\n"+
		"the floor.\n";
		
items =

({
	"treehouse",
	"The treehouse is securely built into a tree",
	"tree",
	"The tree stands about six feet high and is full of life",
	"floorboards",
	"Large planks of wood are lined together to form the floor",
	"wood",
	"Rectangular pieces of wood used for the floor",
	"floor",
	"The wooden floorboards creak loudly as a heavy wind passes by",
	"ground",
	"Below the treehouse lies the lush green grass and the playground",
	"opening",
	"Searching through the opening might uncover some treasures hidden by the kids",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/outside5.c",	"out",
});
}

init(){
	::init();
	add_action("search","search");
}

search(str)
{
	object ob;
	
	if(!str)
	{
		write("What would you like to search?\n");
		return 1;
	}
	
	if(str != "opening")
	{
		write("You can only search the treehouse.\n");
		return 1;
	}
	
	if(str == "opening")
	{
		if(found)
		{
			write("You search through the opening and discover the treasure is gone!\n");
		return 1;
		}
		ob = clone_object("/players/shinshi/areas/coining/obj/purse.c");
		move_object(ob, this_player());
		write("You search through the opening and discover a purse.\n");
		found = 1;
	return 1;
	}
}