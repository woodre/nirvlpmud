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
	short_desc = "The Four Year Olds Classroom";
	long_desc =
		"The colors in this room are almost an assault to the senses.  Bright\n"+
		"posters hang all over the walls, and the floor space is filled with\n"+
		"shorter than average furniture.  One wall is covered in shelves,\n"+
		"which are filled with toys and books.  Above the shelves there is\n"+
		"a large banner which reads \"Fours are FUN!\"  Another wall has\n"+
		"cubbies and coat hooks at one end.  In one corner there is a neat\n"+
		"stack of mats for nap time.\n";

items =

({
	"colors", "All the colors of the rainbow",
	"posters", "Posters with time lines, rules, and numbers",
	"floor", "The floor is covered up with furniture",
	"furniture", "The furniture is all shorter than average",
	"wall", "The different walls each hold different shelves",
	"shelves", "The shelves hold many different toys and books",
	"books", "Many different Dr. Seuss stories",
	"toys", "Fire trucks, toy cars, and dolls",
	"banner", "Fours are FUN",
	"cubbies", "Different cubbies labeled with the owner's names",
	"coat hooks", "Places for the kiddies to put their stuff",
	"hooks", "Places for the kiddies to put their stuff",
	"corner", "Where two walls come together",
	"mats", "Blue and pink mats for nap time",
	"stack", "A stack of blue and pink mats for nap time",
});

dest_dir =
({
	"/players/shinshi/areas/coining/rooms/rm2.c",	"west",
});
}
