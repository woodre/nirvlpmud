#include "/players/stark/defs.h"

sky_mana(){
	write("WOO!");
	MOCO("/players/stark/druid/obj/sky_mana.c"),environment(this_player()));
	return 1;
}
