/*  Jurassic Park  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Jurassic Park";
long_desc =
	"  The area around you is covered with tall marsh grasses and \n"+
	"large ferns.  The height of the grass makes it impossible to \n"+
	"see more than a few feet in any direction.  The jungle spreads \n"+
	"out from the west all the way to the north north horizon.  The \n"+
	"sounds of wild beasts can be heard off in the distance.\n"+
	"There is a small sign stuck in the ground.\n";

items = ({
	"sign","An 'Exit' sign pointing west",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
	"fronds that reproduce by spores instead of seeds",
	"grasses","Tall, wide marsh grass with sharp edges",
	"jungle","You can see the tops of tall trees off in the distance",
});

dest_dir = ({
	"players/eurale/Park/jp90.c","north",
	"players/eurale/Park/jp99.c","west",
});

}
