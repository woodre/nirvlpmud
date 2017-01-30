#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
int i;
object bilbo, rider;
if(!present("rider")){
i = 0;
	while (i<8){
	i +=1;
       rider = clone_object("players/ultramagnus/rider.c");
	move_object(rider, this_object());
}
}
if(!present("bilbo")){
	bilbo = clone_object("players/ultramagnus/bilbo.c");
       move_object(bilbo, this_object());
}
}
TWO_EXIT("players/ultramagnus/hobvil6.c","east",
"players/ultramagnus/hobvil7.c", "southeast",
	"Bilbo's House",
	"You are in a neatly kept house which belongs to the famed adventurer Bilbo Baggins.\n" +
	"You see Bilbo with one of his friends in the rear of the house.\n",1)
