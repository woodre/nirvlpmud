#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contraction_wave;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("contraction_wave")){
move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
}
TWO_EXIT("/players/hippo/rooms/mouth","climb",
   "/players/hippo/rooms/stomac","down",
   "A throat",              
   "This throat belongs to the mouth you have seen before you "+BS+
   "entered here. It seems you are swallowed by the owner of"+BS+
   "the mouth and the throat... who should that be? Should"+BS+
   "this belong to the great Hippo?"+BS+
   "Anyway.. if you don't watch out for that contraction wave, "+BS+  
   "you'll probably never know the answer in the rest of your"+BS+
   "(short remaining) life!!"+BS,
         1)
