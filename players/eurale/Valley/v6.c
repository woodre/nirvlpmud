/*  The Park Valley  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hidden valley";
long_desc =
	"  This is a flat, rocky area.  There are no trees in this area \n"+
	"because of all the stone.  Boulders of different sizes lay all \n"+
	"over.  You can see the treeline of the forest off in the distance.\n";

items = ({
	"boulders","Large, beautiful rocks with colors in them from the \n"+
		"minerals, no doubt",
});

dest_dir = ({
	"players/eurale/Valley/v7.c","east",
	"players/eurale/Valley/v22.c","southeast",
	"players/eurale/Valley/v21.c","south",
	"players/eurale/Valley/v20.c","southwest",
	"players/eurale/Valley/v5.c","west",
});

}
realm() { return "NT"; }
