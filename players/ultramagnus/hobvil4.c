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
THREE_EXIT("players/ultramagnus/hobvil6.c","south",
"players/ultramagnus/hobvil2.c", "east",
"players/ultramagnus/hobshop.c","west",
	"Hobbit Ville",
	"You are in the outskirts of Hobbit Ville.  To the west, you see\n" +
	"the dark mountains of Mordor and the Dark Tower where Sauron\n" +
	"resides among his dark soldiers.\n" +
	"\n"+
	"To the west is also the entrance of the town shop where you can buy the\n"+
	"equipment you'll need to defeat Sauron...\n",1)
in()
{
       call_other(this_player(), "move_player", "in#players/ultramagnus/hobhouse.c");
       return 1;
}
