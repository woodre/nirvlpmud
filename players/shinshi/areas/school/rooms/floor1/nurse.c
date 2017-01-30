inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("haffey")) {
        move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/haffey.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "The Nurses' Office";
	long_desc =
		"The nurse's office has a large window that looks out into the hallway.\n"+
		"In the middle of there room there is a desk with a computer and a lot\n"+
		"of notes on it.  Multiple filing cabinets line the walls, and there is\n"+
		"also a medicine cabinet for storing students' prescriptions. In the\n"+
		"front of the office there are a few chairs where students can wait to\n"+
		"see the nurse, and a curtain in one corner partially hides a bed where\n"+
		"ill students can lie down.\n";

items =

({
	"test",
	"Test this",
});

dest_dir =
({
	"/players/shinshi/areas/school/rooms/floor1/hallwayr3.c",	"west",
});
}
