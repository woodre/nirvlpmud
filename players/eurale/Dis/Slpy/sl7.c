#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Shade Lane";
long_desc =
	"  The lane travels through the twisted forest here.  The large\n"+
	"old trees with their roots sticking up out of the ground and \n"+
	"their gnarly bark make them often look like sinister figures.\n"+
	"Their huge branches block out the sun making it a dark and\n"+
	"forboding place.\n";
items = ({
	"trees","Very old hardwoods",
	"branches","Large branches that overhang the lane",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl8.c","north",
	"players/eurale/Dis/Slpy/sl10.c","east",
	"players/eurale/Dis/Slpy/sl6.c","west",
});

}
