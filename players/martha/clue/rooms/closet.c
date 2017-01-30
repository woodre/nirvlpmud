#include "ansi.h"
inherit "room/room";

	void reset(status arg) {
	if (arg) return;
	set_light(0);
	short_desc = HIK+"The Closet"+NORM;
	items = ({
		"closet","This is a walk in closet",
		"linens","Dingy, greyish linens",
		"linen","A dingy, greyish towel",
		"toiletries","Soap, shampoo, toothpaste and other bathroom goodies",
		"floor","The hardwood floor is very dirty",
		"towel","The towel is dingy looking",
		"towels","The towels are dingy looking",
		"light","There is no light, the bulb is missing",
		"fixture","A porcelain fixture with no bulb",
		"bulb","The bulb is missing"});
		
	long_desc =
"	This is a walk in closet.  Linens are kept here, as well as\n\
extra toiletries for guests who forget to bring their own.  The\n\
floor is dirty and the towels folded on the shelves look dingy\n\
and grey.  There is a light fixture in here, however the bulb\n\
seems to be missing.\n";
	dest_dir = ({"players/martha/clue/rooms/hall2","east"});
}