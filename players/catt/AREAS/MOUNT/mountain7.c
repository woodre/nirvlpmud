#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object hobgoblin;

int i;
i = 0;
   if(!present("hobgoblin")) {

     while(i < 2) {
        i += 1;
   hobgoblin = clone_object(NPC+"hobgoblin");
   move_object(hobgoblin, this_object());
                 }
   }
}

TWO_EXIT(MOUNT+"mountain5","out",
         MOUNT+"mountain10","south",
           "goblin mountain",
            "you are now in goblin mountain... you can hear the wild\n" +
            "shouts and cries of thousands of goblins and their assorted\n" +
            "cousins.\n", 1)


