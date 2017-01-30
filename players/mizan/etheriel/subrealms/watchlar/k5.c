#include "room.h"

FOUR_EXIT("players/mizan/etheriel/subrealms/watchlar/k2.c","south",
	"players/mizan/etheriel/subrealms/watchlar/k6.c","northeast",
	"players/mizan/etheriel/subrealms/watchlar/k7.c","west",
	"players/mizan/etheriel/subrealms/watchlar/k8.c","north",
	"A watery courtyard",
"	There is what seems to be a courtyard here, and through a broken\n"+
"  glass dome above you you could barely make out a sliver of light from the\n"+
"  moon above. The current is a bit stronger here, occasionally throwing you\n"+
"  off balance, and pushing you into the wall. A dark archway leads to the \n"+
"  west, while an even darker one lies to the northeast. Ahead of you you can\n"+
"  barely make out some kind of stairway.\n",
	1)

query_realm() { return "NT"; }
