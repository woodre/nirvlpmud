#include "ansi.h"
inherit "room/room";

reset(arg) {
	if(!present("queenf",this_object())) {
		move_object(clone_object("players/martha/area/mobs/queenf"), this_object());
	}
	
	if (arg) return;
	set_light(1);
	short_desc = YEL+"Ice Cream Sea"+NORM;
	items = ({
		"sea","The sea is overflowing with various flavors of ice cream",
		"chocolate","Brown, billowing piles of chocolate ice cream",
		"vanilla","White, creamy piles of vanilla ice cream",
		"treat","Various ice cream flavors make a yummy for your tummy",
		"strawberry","Pink, thick piles of strawberry ice cream",
		"ice cream","The ice cream is smooth and flowing"});
		
	long_desc = 
"	Oceans of chocolate, vanilla, and strawberry ice cream surround you\n\
as you float along the Ice Cream Sea.  Hopefully you brought a spoon to\n\
dip in the sea, it looks to be a tasty treat!\n";
	dest_dir = ({"players/martha/area/rooms/mswamp", "east",
				 "players/martha/area/rooms/lwoods", "west"});
}
