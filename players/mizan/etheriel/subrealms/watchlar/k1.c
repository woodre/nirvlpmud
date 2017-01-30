#include "room.h"

FOUR_EXIT("players/mizan/etheriel/subrealms/watchlar/w3.c","out",
	"players/mizan/etheriel/subrealms/watchlar/k2.c","north",
	"players/mizan/etheriel/subrealms/watchlar/k3.c","east",
	"players/mizan/etheriel/subrealms/watchlar/k4.c","west",
	"Keep of Etheriel",
"	You arrive in a gloomy place. It seems rather odd that there is a keep\n"+
"  here, in the sea like this. You imagine what this place could have looked\n"+
"  like in with the full glory and color of the regal decor that it seemingly\n"+
"  once had... It would have been beautiful. Now, it is a faded reminder of\n"+
"  what it once was. The hall is silent here, but you feel the voice calling\n"+
"  you to the north, while short corridors lead east and west.\n",
	1)

query_realm() { return "NT"; }
