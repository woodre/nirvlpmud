#include "room.h"
object tyme, sign;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
	tyme = clone_object("players/dragnar/tyme.c");
move_object(tyme, this_object());
sign=clone_object("/players/dragnar/sign.c");
move_object(sign, this_object());

}
THREE_EXIT("room/sunalley2","back",
	"players/dragnar/rooms/arena.c" , "north",
	"players/dragnar/rooms/healshop.c","south",
	"Entrance to the Wastelands",
"As you look to the sky you notice that the sun is blocked by what seems\n" +
"to be a huge cloud.  As you look north the land looks almost barren\n" +
"and you wonder what could have caused the land to turn into these wastelands.\n" +
"Maybe you should go back to a time were things are safe and secure...\n",
	1)
