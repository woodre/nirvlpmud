inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg) return;
	set_light(1);
	short_desc = "A local High School entrance";
	long_desc =
	"This is an entrance to a local High School. Students of all sorts\n"+
	"bustling from one building to another in hopes of getting to class\n"+
	"on time. A couple of students walking from the gymnasium building to\n"+
	"the northwest throw paper balls at you as they head to the alley\n"+
	"way to smoke. A huge "+HIR+"sign"+NORM+" is plunged into the ground.\n";

items =

({
	"sign",
	"This is a large sign. Perhaps you should 'read' it",
	"building",
	"The large buildings are built of bricks",
	"bricks",
	"The bricks look brand new, except for a couple which are chipped",
	"students",
	"White kids, black kids, hispanic kids, oh my",
	"entrance",
	"The roadway is blocked off to protect the students traveling across the street",
	"roadway",
	"The blacktop is blocked off by chains going from tree to tree",
	"chains",
	"Chains linked from the two trees block off the street",
	"trees",
	"The large trees have chains wrapped around them creating a blockade",
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/outside1.c",	"northeast",
	"/players/shinshi/entrancehall.c",	"exit",
	});
}

init(){
::init();

add_action("read","read");
}

read(str){
	if(!str)
	{
		write("What would you like to read?\n");
		return 1;
	}
	
	if(str != "sign")
	{
		write("You cannot read that!\n");
		return 1;
	}
	
	if (str == "sign")
	{
		write("                                     \n"+
              "|------------------------------------------------------------\n"+
			  "|The gymnasium is closed off for   \n"+
			  "|reconstruction. The second and\n"+
			  "|third floor is off limits for all          \n"+
			  "|students. Any students that have                       \n"+
			  "|a locker on the third floor will                       \n"+
			  "|have to be re-assigned temporarily.                    \n"+
			  "|------------------------------------------------------------\n");
		return 1;
	}
}
