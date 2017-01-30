#include "room.h"
object master;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
	master = clone_object("players/dragnar/master.c");
move_object(master, this_object());

}

ONE_EXIT("room/sunalley2","out",
	"An Evil place",
	"Here lies the ultimate challange and biggest evil.  If you destroy the\n" +
	"evil maybe it will stop it from taking over your mind.  If you can't\n" +
	"stand up to such power you should flee as fast as you can, for the\n" +
"power here is great as it entangles with the darkness.\n",
	1)
