#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You follow the roadway curving east and squeeze past the large \n"+
	"rock formation.  The roadway dead-ends here with solid rock walls \n"+
	"climbing straight up on all sides..... a very secluded place. \n"+
	"There is an old covered wagon sitting here that appears to be in \n"+
	"very good shape for such a desolate place. \n";

items = ({
	"walls","The straight-up rock walls are unclimbable and provide \n"+
		"shelter and protection to this area",
	"wagon","This covered wagon is intact with it's cloth covering",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs6.c","west",
	"/players/eurale/Drygulch/wagon.c","enter",
});

}
