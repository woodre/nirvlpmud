#include "/players/stark/defs.h"

healing_rain(){
	write("You cast healing rain.\n");
	MOCO("/players/stark/druid/obj/healing_rain.c"),environment(this_player()));
	return 1;
}

