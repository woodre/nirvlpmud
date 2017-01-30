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
TWO_EXIT("players/ultramagnus/hobvil5.c","north",
"players/ultramagnus/hobbithouse.c", "northwest",
	"Hobbit Ville",
	"You seem to be at the congregation center of the hobbits...\n" +
	"There is a large building looking somewhat like a church here.\n" +
	"The friendly little hobbits are all busily talking...\n" +
	"They seem to talk of Bilbo...\n",1)
in()
{
       call_other(this_player(), "move_player", "in#players/ultramagnus/hobhouse.c");
       return 1;
}
