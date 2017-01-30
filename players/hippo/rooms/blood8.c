#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
object hiv;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("hiv")){
  move_object(clone_object("/players/hippo/c/hiv.c"),this_object());
}
}
FOUR_EXIT("/players/hippo/rooms/liver","liver",
   "/players/hippo/rooms/rectum","diffuse",
   "/players/hippo/rooms/blood7","up",
  "/players/hippo/rooms/vene1.c","down",
   "A blood vessel",
   "You are in a blood vessel, that's for sure. But what should"+BS+
   "be next to the vessel? colon? rectum? stomach? urine? fat? balls?"+BS+
   "you really don't know, but you have to get outta here!"+BS,
         1)
