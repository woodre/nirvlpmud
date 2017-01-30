#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("thrombo")){
   move_object(clone_object("/players/hippo/c/thrombo.c"),this_object());
}
}
FOUR_EXIT("/players/hippo/rooms/liver","liver",
   "/players/hippo/rooms/thick_colon3","diffuse",
   "/players/hippo/rooms/blood6","up",
   "/players/hippo/rooms/blood8","down",
   "A blood vessel",
   "You are in a blood vessel, that's for sure. But what should"+BS+
   "be next to the vessel? colon? rectum? stomach? urine? fat? balls?"+BS+
   "you really don't know, but you have to get outta here!"+BS,
         1)
