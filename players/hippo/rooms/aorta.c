#include "room.h"
#include "/players/hippo/bs.h"
int i,j;
object ery,leuco,thrombo;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("ery")){
/* Changed from 5 to 3  -Snow */
   for(i=0;i<3;i++) {
   move_object(clone_object("/players/hippo/c/ery.c"),this_object());
}
}
if(!present("leuco")){
/* Changed from 3 to 2  -Snow */
   for(j=0;j<2;j++) {
   move_object(clone_object("/players/hippo/c/leuco.c"),this_object());
}
}
if(!present("thrombo")){
   move_object("/players/hippo/c/thrombo.c",this_object());
}
}
THREE_EXIT("/players/hippo/rooms/lventr","heart",
  "/players/hippo/rooms/carotis","carotis",
  "/players/hippo/rooms/blood1","down",
   "The aorta",
   "This is the largest vessel you have ever seen. You suppose "+BS+
   "this must be the aorta."+BS,
         1)
