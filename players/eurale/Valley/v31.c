/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  You push your way through the dense underbrush and find yourself \n"+
	"on a very steep path leading down the side of the valley to the floor \n"+
	"below.  The ferns nearly conceal the path.  You can hear the faint \n"+
	"sound of huge beasts off in the distance below. \n";

items = ({
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"path","This path, though narrow and well hidden, looks like it \n"+
		"has been used recently",
});

dest_dir = ({
	"players/eurale/Park/jp46.c","up",
	"players/eurale/Valley/v32.c","down",
});

}
