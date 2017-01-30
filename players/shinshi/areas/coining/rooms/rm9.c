inherit "/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(!present("shinshi_reg_mob")) {
	move_object(clone_object("/players/shinshi/areas/coining/mobs/student.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "The Teacher's Lounge";
	long_desc =
		"This room has been painted a soft blue color to make it a very\n"+
		"relaxing environment. There is a table in the middle of the room\n"+
		"that is surrounded by chairs.  Different household accessories sit\n"+
		"on the counter beneath a small cupboard.  There is a refrigerator\n"+
		"at one end of the counter, and a television bolted to one wall.\n";

items =

({
	"table", "A very sturdy table for the teachers",
	"chairs", "Wooden chairs are pushed into the table",
	"coffee maker", "A Black and Decker coffee maker",
	"counter", "A long white counter with different household accessories",
	"accessories", "A toaster, a coffee maker, and a microwave",
	"toaster", "A nice fancy silver toaster",
	"microwave", "A brand new microwave oven",
	"cupboard", "A cupboard that holds sugar, creamer, etc. for the coffee",
	"refrigerator", "A refrigerator that holds the teachers' lunches",
	"television", "A Magnavox TV is bolted into the wall",
	"tv", "A Magnavox TV is bolted into the wall",
	"wall", "One of the soft blue colored walls has a TV bolted to it",
	"sugar", "Mmmmm.. Domino's Sugar",
	"creamer", "Mmmmm.. CoffeeMate",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm4.c",	"east",
});
}
