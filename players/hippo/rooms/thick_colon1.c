#include "room.h"
#include "/players/hippo/bs.h"
int i;
object cheese,bread_piece,up;
object nut;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("cheese")){
   move_object(clone_object("/players/hippo/c/cheese.c"),this_object());
}
if(!present("bread_piece")){
   move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object());
}
if(!present("nut")){
for (i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/nut.c"),this_object());
}
}
if(!present("up")){
for (i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/7_up.c"),this_object());
}
}
}
THREE_EXIT("/players/hippo/rooms/thin_colon3","west",
   "/players/hippo/rooms/thick_colon2","up",
   "/players/hippo/rooms/blood5","blood",
   "The thick ascending colon",
   "Yes, this is the thick ascending colon. You can't see what most "+BS+
   "of all these little hard things in here must have been. "+BS,
         1)
