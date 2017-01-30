#include "room.h"
#include "/players/hippo/bs.h"
int i;
object tobacco;
object hiv;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("tobacco")){
   move_object(clone_object("/players/hippo/c/tobacco.c"),this_object());
}
if(!present("hiv")){
   move_object(clone_object("/players/hippo/c/hiv.c"),this_object());
}
}
TWO_EXIT("/players/hippo/rooms/lungartery","west",
   "/players/hippo/rooms/lungvene","north",
   "The lung",
   "Yes.. this is the lung. You see what happens to you when you smoke."+BS+
   "All over, you see black spots and ugly malformations of the little"+BS+
   "thin structures in here. You suppose the tobacco mozaic is responsible."+BS+
   "Maybe try to kill him, although he looks tough."+BS,
         1)
