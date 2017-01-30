#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Shade Lane";
long_desc =
	"The fields of grain stretch off to the west while to the east \n"+
	"you can make out the edge of the forest.  The land is relatively\n"+
	"flat with very little to break the horizon.\n";

items = ({
	"fields","Golden waves of wheat, swaying in the breeze",
});

dest_dir = ({
	"players/eurale/Dis/Slpy/sl5.c","east",
	"players/eurale/Dis/Slpy/sl3.c","west",
});

}
