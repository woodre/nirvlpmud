#include "/players/hippo/bs.h"
inherit "room/room";
int i;
object sign;
reset(arg){
if (!arg) {
	set_light(1);
/* Changed from 3 to 1  (how many lev20 monsters can there be?)
-Snow */
/* Fixed this so it at least cloned something. -Feldegast 12-12-00 */
for(i=0;i<1;i++) {
  move_object(clone_object("/players/hippo/c/cahepar.c"),this_object());
}
short_desc="Another part of the liver";
long_desc="This part of the liver is not as friendly as the other part."+BS+
   "You see an enormous carcinogenic process around you. You wonder how\n"+
   "it is possible Hippo is still alive with such a liver."+BS+
   "He must have trained his liver a lot by drinking alcoholic stuff."+BS;
dest_dir = ({
   "/players/hippo/rooms/liver.c","back",
	});
}
}
