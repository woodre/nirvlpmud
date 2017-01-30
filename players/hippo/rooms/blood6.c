#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
object hiv;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("ery")){
/* Changed from 3 to 1  -Snow */
   for(j=0;j<1;j++) {
   move_object(clone_object("/players/hippo/c/ery.c"),this_object());
}
}
if(!present("thrombo")){
   move_object(clone_object("/players/hippo/c/thrombo.c"),this_object());
}
if(!present("hiv")){
  move_object("/players/hippo/c/hiv.c",this_object());
}
}
FOUR_EXIT("/players/hippo/rooms/liver","liver",
   "/players/hippo/rooms/thick_colon2","diffuse",
   "/players/hippo/rooms/blood5","up",
   "/players/hippo/rooms/blood7","down",
   "A blood vessel",
   "You are in a blood vessel, that's for sure. But what should"+BS+
   "be next to the vessel? colon? rectum? stomach? urine? fat? balls?"+BS+
   "you really don't know, but you have to get outta here!"+BS,
         1)
