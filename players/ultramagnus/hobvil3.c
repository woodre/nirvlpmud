#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("in","in");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
object hobbit,hobhouse;
if(!present("hobhouse")){
       hobhouse = clone_object("players/ultramagnus/hobhouse.c");
       move_object(hobhouse, this_object());
	hobbit = clone_object("players/ultramagnus/hobbit.c");
	move_object(hobbit,this_object());
}
}
TWO_EXIT("players/ultramagnus/hobvil1.c","north",
	"players/ultramagnus/hobvil5.c", "west",
	"Hobbit Ville",
	"You're in the outskirts of the beautiful Hobbit Ville. \n" +
	"There is a hut nearby with the door wide open as if inviting \n"+
	"you in.  But don't go in, it might be a TRAP!!!!\n",1)
in()
{
       call_other(this_player(), "move_player", "in#players/ultramagnus/hobhouse.c");
       return 1;
}
