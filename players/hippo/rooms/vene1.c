#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contraction_wave;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("contraction_wave")){
move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
}
TWO_EXIT("/players/hippo/rooms/blood8","up",
   "/players/hippo/rooms/ratrium","heart",
   "Veins",
   "You dwarl through a hell of a lot of veins....all leading to the heart."+BS,
         1)
