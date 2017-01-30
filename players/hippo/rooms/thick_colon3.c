#include "room.h"
#include "/players/hippo/bs.h"
int i;
object up,something;
object nut;
object staphylococ;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("something")){
for (i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/something.c"),this_object());
}
}
if(!present("up")){
   move_object(clone_object("/players/hippo/c/7_up.c"),this_object());
}
if(!present("nut")){
   move_object(clone_object("/players/hippo/c/nut.c"),this_object());
}
if(!present("staphylococ")){
   move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object());
}
}
THREE_EXIT("/players/hippo/rooms/thick_colon2","west",
   "/players/hippo/rooms/rectum","down",
   "/players/hippo/rooms/blood7","blood",
   "The descending colon",
   "As you arrive in the descending colon, you start having trouble"+BS+
   "to move forewards, as this substance you are in, is getting a "+BS+
   "hard shape. You are glad it is descending here, that's help you "+BS+
   "a bit to get to the exit, maybe"+BS,
         1)
