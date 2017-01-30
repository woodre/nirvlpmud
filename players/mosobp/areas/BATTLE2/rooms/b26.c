#include "/obj/ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = YEL+"Atop a Cliff"+NORM;
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/BATTLE/rooms/b25.c","west",
"players/mosobp/areas/BATTLE/rooms/b27.c","east",
"players/mosobp/areas/BATTLE/rooms/b30.c","southeast",
"players/mosobp/areas/BATTLE/rooms/b29.c","south",
});
}
