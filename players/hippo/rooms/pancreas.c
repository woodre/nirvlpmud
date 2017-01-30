#include "/players/hippo/bs.h"
inherit "room/room";
object sign;
reset(arg){
if (!arg) {
	set_light(1);
short_desc=("The pancreas");
long_desc=("Here in the pancreas you see strange walls, and some"+BS+
   "kind of different cells, including 'Langerhans areas'..."+BS+
    "You wonder how you know that these cells are called like that, "+BS+
   "but you suppose it's worth to check that place"+BS);
dest_dir = ({
   "/players/hippo/rooms/liver.c","back",
   "/players/hippo/rooms/langerhans","langerhans",
	});
}
}
