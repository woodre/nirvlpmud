#include "room.h"
#include "/players/hippo/bs.h"
int i;
object contrction_wave;
object something;
object dna;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
/* Not sure if this is needed here...
if(!present("contraction wave")){
   move_object(clone_object("/players/hippo/c/contr_wave.c"),this_object());
}
*/
if(!present("dna")){
  move_object(clone_object("/players/hippo/c/staphylococ.c"),this_object());
}
if(!present("something")){
/* Changed from 4 to 2  -Snow */
   for(i=0;i<2;i++) {
      move_object(clone_object("/players/hippo/c/something.c"),this_object());
}
}
}
THREE_EXIT("/players/hippo/rooms/thick_colon3","up",
   "/players/hippo/rooms/blood8","blood",
   "/players/hippo/rooms/shit","hole",
   "The rectum",
   "Well, you finally reached some place where you can't continue"+BS+
"You are stuck into a massive substance, and you think that you"+BS+
   "can not continue your way. Although, you see some light"+BS+
   "through a small hole. Maybe you should figure out what"+BS+
   "that may be......"+BS,
         1)
