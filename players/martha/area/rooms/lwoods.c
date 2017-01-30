#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("plolly",this_object())) {
		move_object(clone_object("/players/martha/area/mobs/plolly"), this_object());
	}

	if (arg) return;
	set_light(1);
	short_desc = HIM+"Lollipop Woods"+NORM;
	items = ({
		"trees","Trees shaped like lollipops loom overhead",
		"tree","This tree looks like a gigantic lollipop",
		"grape","An enormous grape flavored lollipop tree",
		"cherry","An enormous cherry flavored lollipop tree",
		"orange","An enormous orange flavored lollipop tree",
		"lemon","An enormous lemon flavored lollipop tree",
		"lime","An enormous lime flavored lollipop tree",
		"blueberry","An enormous blueberry flavored lollipop tree",
		"woods","The woods are full of lickety, stickety fun",
		"flowers","Small flowers shaped like lollipops",
		"ground","The ground is covered in what appears to be lollipops"});
		
	long_desc = 
"   Large lollipop shaped trees form the Lollipop Woods.  Grape,\n\
Cherry, Orange, Lemon, Lime, and Blueberry lollipop trees are\n\
scattered around the woods.  Little lollipop shaped flowers are\n\
dispersed along the ground.  The trees and flowers look so\n\
appealing that you are tempted to stick out your tongue and\n\
run from tree to tree, licking each as you pass by.\n";
	dest_dir = ({"players/martha/area/rooms/pbhouse", "south",
				 "players/martha/area/rooms/icsea", "east"});
}
