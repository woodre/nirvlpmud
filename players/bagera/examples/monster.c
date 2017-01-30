#include "room.h"
object demon;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
  int a;
  object demon;   a=0;
  if(!present("demon")) {
    while(a < 5){
      demon=clone_object("/players/mathiast/monsters/demon.c");
      move_object(demon, this_object());
      a++;
    }
  }
}

TWO_EXIT("/players/mathiast/rooms/cave/demon0.c","west",
	"/players/mathiast/rooms/cave/demon2.c","east",
         "Demons' cave",
         "You enter the cave and are shocked to find...\n"+
         "A room full of deadly demons!\n",
         1)
