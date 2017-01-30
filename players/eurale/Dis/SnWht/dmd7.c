#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Diamond Mine Drive";
long_desc =
	"  This is a wonderful bark path.  It wanders through the thick \n"+
	"forest and among the tall timber.  The rustling of the leaves \n"+
	"as the wind caresses the branches creates a soothing and serene \n"+
	"atmosphere.  Queen Anne's Lace grows in abundance all along the \n"+
	"edges of the path.  A stone castle, grey and ominous lies just \n"+
	"off the path to the west.\n";

items = ({
	"path","Chopped and shredded bark from felled trees",
	"lace","Large, white, delicate flowerheads on tall stems",
	"castle","This stone structure, shrouded in grey mist, is the \n"+
		"fortress of the evil queen",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd6.c","north",
	"players/eurale/Dis/SnWht/dmd8.c","enter",
});

}
