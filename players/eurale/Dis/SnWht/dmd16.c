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
	"edges of the path.  To the east, cut into the stone, is the mouth\n"+
	"of what appears to be a mine going down.\n";

items = ({
	"path","Chopped and shredded bark from felled trees",
	"lace","Large, white, delicate flowerheads on tall stems",
	"mine","It's a fairly steep decline and too dark to see",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd17.c","enter",
	"players/eurale/Dis/SnWht/dmd15.c","south",
});

}
