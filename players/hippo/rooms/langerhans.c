#include "/players/hippo/bs.h"
inherit "room/room";
int i;
object sign;
reset(arg){
if (!arg) {
	set_light(1);
for(i=1;i<3;i++) {
move_object(clone_object("/players/hippo/c/calangerh.c"),this_object());
}
short_desc="The Langerhans cells.... something is wrong in here(?)";
long_desc="You arrived at the Langerhans cells. And you see something "+BS+
   "that you've never seen in a normal body. You decide that this"+BS+
   "must be some sort of cancer.\n";
dest_dir = ({
   "/players/hippo/rooms/pancreas.c","pancreas",
	});
}
}
