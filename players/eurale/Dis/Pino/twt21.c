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
	"they need to camp for a bit.\n";

items = ({
	"trees","Beautiful, healthy Poplar trees",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt22.c","east",
	"players/eurale/Dis/Pino/twt7.c","west",
});

}
