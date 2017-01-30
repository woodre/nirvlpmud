#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Nottingham";
long_desc =
	"  You stand just north of the town of Nottingham.  You can see\n"+
	"the open gates to the city to the southeast.  The forest to the\n"+
	"north looks dark and foreboding.  The tops of a few buildings\n"+
	"are just visible over the high wall surrounding the town.\n";

items = ({
   "town","A large castle surrounded by smaller buildings enclosed by a wall",
	"gates","The entryway into Nottingham",
	"forest","Towering hardwoods of Ash, Walnut and Maple",
	"buildings","They are too far away to make out",
	"wall","High wooden walls erected to protect the citizens",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh18.c","north",
	"players/eurale/Dis/Hood/rh20.c","southeast",
});

}
