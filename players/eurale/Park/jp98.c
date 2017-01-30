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
	"out from the west all the way to the northern horizon.  The \n"+
	"sounds of wild beasts can be heard off in the distance.  There \n"+
	"is an old weather-beaten sign laying on it's side in the grass.\n"+
	"Another small arrow is stuck in the ground beside the path.\n";

items = ({
	"arrow","An 'Exit' arrow pointing north",
	"sign","The sign reads..... \n"+
		"  Welcome to Jurassic Park.  The animals here have been \n"+
		"genetically reproduced, some with surprising results. \n"+
		"BEWARE!! Not all of our experiements were successful. \n"+
		"Those that choose to enter the park do so at their own \n"+
		"risk.  The park assumes no responsibility for whatever \n"+
		"happens to those who choose to explore here.... \n"+
		"                        Jurassic Park Management \n",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
	"fronds that reproduce by spores instead of seeds",
	"grasses","Tall, wide marsh grass with sharp edges",
	"jungle","You can see the tops of tall trees off in the distance",
});

dest_dir = ({
	"players/eurale/Park/jp88.c","north",
	"players/eurale/Park/jp99.c","east",
	"players/eurale/Park/jp97.c","west",
});

}
