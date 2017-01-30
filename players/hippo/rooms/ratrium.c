#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contraction_wave;
object valvula, trabeculae;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("contraction_wave")){
move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
if(!present("valvula")){
/* Changed from 2 to 1  -Snow */
   for(i=0;i<1;i++){
   move_object(clone_object("/players/hippo/c/valvula.c"),this_object());
}
}
}
TWO_EXIT("/players/hippo/rooms/rventr","south",
   "/players/hippo/rooms/liver","up",
   "Right atrium",
   "Normally, you can't reach the liver from this place. But for you\n"+
   "this friendly body makes an exception. I'd like you to go south, though"+BS,
         1)
