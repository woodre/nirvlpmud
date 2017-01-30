#include "room.h"
#include "/players/hippo/bs.h"
int i;
object stone;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("stone")){
   for(i=0;i<4;i++) {
      move_object(clone_object("/players/hippo/c/stone.c"),this_object());
}
}
}
TWO_EXIT("/players/hippo/rooms/blood10","blood",
   "/players/hippo/rooms/bladder","down",
   "One of the kidneys",
   "You are in one of the kidneys. Besides the blood, you only see one exit"+BS+
   "from this place. I suppose you can immagine where that path ends..."+BS,
         1)
