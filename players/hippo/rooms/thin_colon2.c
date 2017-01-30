#include "room.h"
#include "/players/hippo/bs.h"
int i;
object cheese,up;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("cheese")){
for(i=0;i<3;i++) {
move_object(clone_object("/players/hippo/c/cheese.c"),this_object());
}
}
if(!present("up")){
for(i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/7_up.c"),this_object());
}
}
}
THREE_EXIT("/players/hippo/rooms/thin_colon1","northeast",
   "/players/hippo/rooms/blood3","blood",
   "/players/hippo/rooms/thin_colon3","south",
   "The jejunum",
   "You are in the jejunem, the second part of the thin colon."+BS+
  "You see that the food here, has been scrumbled some more,"+BS+
   "but still you recognize some of the food"+BS,
         1)
