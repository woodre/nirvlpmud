#include "/obj/ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = YEL+"Atop a Cliff"+NORM;
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/BATTLE/rooms/b26.c","west",
"players/mosobp/areas/BATTLE/rooms/b28.c","east",
"players/mosobp/areas/BATTLE/rooms/b29.c","southwest",
"players/mosobp/areas/BATTLE/rooms/b30.c","south",
"players/mosobp/areas/BATTLE/rooms/b31.c","southeast",
});
}
