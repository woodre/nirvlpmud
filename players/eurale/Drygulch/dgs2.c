#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  The road meanders it's way through the boulders and sagebrush \n"+
	"and rarely levels out long enough to see very far.  As you \n"+
	"approach a barely visible fork in the road, you can hear the \n"+
	"howl of a coyote off in the distance. \n";

items = ({
	"boulders","These large rocks seem to sparkle in the sun.  Their\n"+
		"size alone is impressive",
	"sagebrush","The scrub of the desert.  Thin, dry firewood but \n"+
		"not good for much else",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs1.c","north",
	"/players/eurale/Drygulch/dgs5.c","south",
	"/players/eurale/Drygulch/dgs3.c","west",
});

}
