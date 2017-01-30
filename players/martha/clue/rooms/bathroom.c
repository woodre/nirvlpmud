#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(1);
	short_desc = HIY+"The Bathroom"+NORM;
	items = ({
		"bathroom","This is a bathroom, it is bright and cheery",
		"bathtub","The bathtub is porcelain and old fashioned",
		"toilet","The toilet is white and has a wooden seat",
		"sink","The sink is porcelain and has beautiful faucets",
		"legs","These are the legs of the bathtub",
		"seat","This is a wooden toilet seat",
		"wooden","This is the wooden toilet seat",
		"porcelain","The porcelain is white and sparkling",
		"faucet","The faucet is porcelain with a blue flower design",
		"faucets","The faucets are porcelain with a blue flower design",
		"blue","Blue is the color of the design on the faucets",
		"design","This is a blue, floral design",
		"yellow","Yellow is the color of many things in this room",
		"bathmat","The bathmat is furry and yellow",
		"floor","The floor is made of ceramic tiles that are a pale shade of yellow",
		"hugger","This is like a bathmat, only it goes around the bottom of the toilet",
		"bottom","This is the bottom of the toilet",
		"wall","The wall is yellow",
		"walls","The walls are yellow",
		"tiles","The tiles are a pale shade of yellow",
		"tile","The tile is a pale shade of yellow",
		"mirror","The mirror is oval shaped",
		"room","This is the bathroom"});
		
	long_desc =
"	The bathroom is big enough to hold an old fashioned bathtub, a\n\
toilet and a sink.  The bathtub is porcelain and stands high on it's\n\
four legs.  The toilet is white as well, with a wooden seat.  The\n\
sink is porcelain as well and has beautiful porcelain faucets with\n\
a blue flower design.  There is a yellow bathmat on the floor next\n\
to the bathtub, as well as a toilet hugger around the bottom of the\n\
toilet.  The walls are bright yellow and the floor tiles are a paler\n\
shade of yellow.  There is an enormous oval mirror that hangs\n\
above the sink.  This is the cleanest room in the house!\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","north"});
}
