#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Poplar Grove";
long_desc =
	"  You wind your way through this dense grove of Poplar trees. \n"+
	"The trees, though tall and somewhat wispy, provide protection \n"+
	"from the elements and are a favorite spot of the gypsies when \n"+
	"they need to camp for a bit.  There is a covered wagon nestled\n"+
	"back here now.\n";

items = ({
	"trees","Beautiful, healthy Poplar trees",
	"wagon","A gypsy wagon",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt23.c","enter",
	"players/eurale/Dis/Pino/twt21.c","west",
});

}
