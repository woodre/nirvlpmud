/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  You are about half way between the valley ridge and the floor. \n"+
	"The temperature is quite a bit warmer.  The ferns that hide the \n"+
	"path are giving way to some fairly large boulders.  The tops of \n"+
	"the trees below hide the valley floor but you sense that you are \n"+
	"not going to be alone down there. \n";

items = ({
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"boulders","Very large stones, large enough to climb on",
});

dest_dir = ({
	"players/eurale/Valley/v31.c","up",
	"players/eurale/Valley/v10.c","down",
});

}
