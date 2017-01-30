#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
FOUR_EXIT("/players/hippo/rooms/liver","liver",
   "/players/hippo/rooms/thin_colon3","diffuse",
   "/players/hippo/rooms/blood3","up",
   "/players/hippo/rooms/blood5","down",
   "A blood vessel",
   "You are in a blood vessel, that's for sure. But what should"+BS+
   "be next to the vessel? colon? rectum? stomach? urine? fat? balls?"+BS+
   "you really don't know, but you have to get outta here!"+BS,
         1)
