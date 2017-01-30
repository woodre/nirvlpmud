inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("wasielewski")) {
	move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/wasielewski.c"),this_object());
}

if(arg) return;

set_light(1);

short_desc = "Mr. Wasielewski's Classroom";
long_desc =
	"According to the sign on the door, this is Mr. W's room.  To the left,\n"+
	"there is a small stand with drill papers resting on the top of it.\n"+
	"Underneath there are slots from which stacks of papers are sticking out.\n"+
	"The room has blackboards in both the front and the back of the room, as\n"+
	"well as an overhead projector pointing toward the front.  The main space\n"+
	"in the room is filled with thirty-two student desks.\n";

items =
({
	"sign",
	"Mr. Wasielewski's Social Studies Classes",
	"stand",
	"A small stand with papers on it",
	"drill papers",
	"Papers with todays drill",
	"slots",
	"Slots that seperate the different classes paperwork",
	"blackboards",
	"Two large blackboards are linked together on both walls",
	"overhead projector",
	"A overhead projector that is current turned off",
	"desks",
	"Small wooden desks for students",
	});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr1.c",	"south",
	});
}
