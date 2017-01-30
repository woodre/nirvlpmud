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
   move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object());
}
}
TWO_EXIT("/players/hippo/rooms/lventr","south",
   "/players/hippo/rooms/lungvene","down",
   "Left atrium",
   "From the lung-circulation, you reached the left atrium. You have"+BS+
   "to follow the blood to go to the main circulation from here."+BS+
   "The blood passes some valvulae every heartbeat."+BS,
         1)
