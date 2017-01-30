#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contraction_wave;
object bread_piece;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("contraction_wave")){
move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
if(!present("bread_piece")){
for(i=0;i<3;i++) {
   move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object());
}
}
}
THREE_EXIT("/players/hippo/rooms/kots","throw_up",
   "/players/hippo/rooms/thin_colon1","south",
   "/players/hippo/rooms/blood1","blood",
   "The stomach",
   "Although it's quite dark in here, you can see all different"+BS+
   "things, dwarling around in this wet crap you are in. So this"+BS+
   "must be the inside of a stomach. You wonder what this person"+BS+
   "has been eating lately. You see several unrecognizable things."+BS,
         1)
