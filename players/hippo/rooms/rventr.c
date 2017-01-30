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
   move_object(clone_object("/players/hippo/c/valvula.c"),this_object());
}
if(!present("trabeculae")){
   for(i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object());
}
}
}
TWO_EXIT("/players/hippo/rooms/ratrium","north",
   "/players/hippo/rooms/lungartery","down",
   "Right ventricle",
   "This is the right ventricle. You can enter the small circulation"+BS+
   "from here. What should you find in the lungs?"+BS,
         1)
