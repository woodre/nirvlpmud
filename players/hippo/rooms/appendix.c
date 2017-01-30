#include "room.h"
#include "/players/hippo/bs.h"
int i;
object thrombo;
object nut;
object staphylococ;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("thrombo")){
/* Changed from 2 to 1  -Snow */
for(i=0;i<1;i++) {
   move_object(clone_object("/players/hippo/thrombo.c"),this_object());
}
}
if(!present("nut")){
   move_object(clone_object("/players/hippo/c/nut.c"),this_object());
}
if(!present("staphylococ")){
   move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object());
}
}
ONE_EXIT("/players/hippo/rooms/thin_colon3","east",
   "The appendix vermiformis",
   "This is a dead end of the colon. Normally, there is not much to do in here."+BS,
         1)
