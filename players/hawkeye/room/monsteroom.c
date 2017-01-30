#include "room.h"
object alchemist;

#undef EXTRA_RESET
#define EXTRA_RESET\

   extra_reset();
extra_reset() {
	alchemist = clone_object("players/hawkeye/alchemist.c");
move_object(alchemist, this_object());

}

ONE_EXIT("players/gorgan/workroom.c","home",
	"House of Beers",
"   There is a putrid stench of smelly alchemists here... \n"+
" You can barely hear yourself over the wimpering and heaving.\n",
	1)
