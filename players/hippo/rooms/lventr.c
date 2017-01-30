#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contraction_wave;
object valvula, trabeculae;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
/* Don't know if one of these is necessary in every room...
if(!present("contraction_wave")){
move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
*/
if(!present("valvula")){
/* Changed from 2 to 1  -Snow */
   for(i=0;i<1;i++){
   move_object(clone_object("/players/hippo/c/valvula.c"),this_object());
}
}
if(!present("trabeculae")){
   move_object(clone_object("/players/hippo/c/trabeculae.c"),this_object());
}
}
TWO_EXIT("/players/hippo/rooms/latrium","north",
   "/players/hippo/rooms/aorta","northeast",
   "left ventricle",
   "This is the left ventricle. You can enter the body circulation"+BS+
   "from here. You know that would be dangerous, though."+BS,
         1)
