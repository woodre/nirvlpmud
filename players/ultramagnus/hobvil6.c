#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("in","in");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object hobbit;
if(!present("hobbit")){
       hobbit = clone_object("players/ultramagnus/hobbit.c");
       move_object(hobbit, this_object());
}
}
FOUR_EXIT("players/ultramagnus/hobvil4.c","north",
	"players/ultramagnus/hobvil5.c", "south",
"players/ultramagnus/hobvil1.c", "east",
	"players/ultramagnus/hobbithouse.c","west",
	"Hobbit Ville",
	"You are in downtown Hobbit Ville.\n"+
	"You see a large building with a sign saying city hall and another pointin west saying :Bilbo's Place, all are welcome, except orcs and goblins...\n",1)
in()
{
       call_other(this_player(), "move_player", "in#players/ultramagnus/hobhouse.c");
       return 1;
}
