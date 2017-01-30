#include "room.h"
#include "/players/hippo/bs.h"
int i;
object cheese,bread_piece,up;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("cheese")){
for (i=0;i<3;i++) {
   move_object(clone_object("/players/hippo/c/cheese.c"),this_object());
}
if(!present("bread_piece")){
   move_object(clone_object("/players/hippo/c/bread_piece.c"),this_object());
}
}
if(!present("up")){
for (i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/7_up.c"),this_object());
}
}
}
THREE_EXIT("/players/hippo/rooms/stomac","north",
   "/players/hippo/rooms/blood2","blood",
   "/players/hippo/rooms/thin_colon2","southwest",
   "A duodenum",
   "You are in the duodenum, the first part of the thin colon."+BS+
   "You see a lot of things around you, you can recognize as"+BS+
"'substances that must once have been food'"+BS,
         1)
