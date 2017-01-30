#include "room.h"
#include "/players/hippo/bs.h"
int i;
object cheese,something;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("cheese")){
for (i=0;i<3;i++) {
   move_object(clone_object("/players/hippo/c/cheese.c"),this_object());
}
}
if(!present("something")){
   move_object(clone_object("/players/hippo/c/something.c"),this_object());
}
}
THREE_EXIT("/players/hippo/rooms/thick_colon1","down",
   "/players/hippo/rooms/thick_colon3","east",
   "/players/hippo/rooms/blood6","blood",
   "The transvers colon",
   "You are in the transvers colon. You see that the crap you were"+BS+
   "in at the thin colon is slowly changing into some harder"+BS+
   "stuff. The water seems to be extracted, and the air is awful."+BS,
         1)
