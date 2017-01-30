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
	"edges of the path.\n";

items = ({
	"path","Chopped and shredded bark from felled trees",
	"lace","Large, white, delicate flowerheads on tall stems",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd11.c","east",
	"players/eurale/Dis/SnWht/dmd9.c","west",
});

}
