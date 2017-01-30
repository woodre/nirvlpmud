#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("ery")){
/* Changed from 3 to 1  -Snow */
   for(j=0;j<1;j++) {
   move_object(clone_object("/players/hippo/c/ery.c"),this_object());
}
}
if(!present("leuco")){
   move_object(clone_object("/players/hippo/c/leuco.c"),this_object());
}
if(!present("thrombo")){
   move_object(clone_object("/players/hippo/c/thrombo.c"),this_object());
}
}
FOUR_EXIT("/players/hippo/rooms/liver","liver",
   "/players/hippo/rooms/stomac","diffuse",
   "/players/hippo/rooms/aorta","up",
   "/players/hippo/rooms/blood2","down",
   "A blood vessel",
   "You are in a blood vessel, that's for sure. But what should"+BS+
   "be next to the vessel? colon? rectum? stomach? urine? fat? balls?"+BS+
   "you really don't know, but you have to get outta here!"+BS,
         1)
