#include "room.h"
#include "/players/hippo/bs.h"
int i;
object cheese,up,contraction_wave;
object nut;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
if(!present("cheese")){
move_object(clone_object("/players/hippo/c/cheese.c"),this_object());
}
if(!present("contraction_wave")){
   move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
if(!present("up")){
for(i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/7_up.c"),this_object());
}
}
if(!present("nut")){
for(i=0;i<2;i++) {
   move_object(clone_object("/players/hippo/c/nut.c"),this_object());
}
}
}
FOUR_EXIT("/players/hippo/rooms/thin_colon2","north",
   "/players/hippo/rooms/appendix","west",
   "/players/hippo/rooms/blood4","blood",
   "/players/hippo/rooms/thick_colon1","east",
   "The ileum",
   "You are in the ileum now..it looks quite similar to the jejunum"+BS+
   "and the duodenum. You wonder how long you'll have to stay in here. "+BS+
  "Oeps.. you were wrong. There is another exit in this place."+BS+
   "Where the hell should that one lead to?"+BS,
         1)
