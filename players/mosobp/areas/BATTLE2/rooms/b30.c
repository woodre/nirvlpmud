#include "/obj/ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = YEL+"Atop a Cliff"+NORM;
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/BATTLE/rooms/b26.c","northwest",
"players/mosobp/areas/BATTLE/rooms/b27.c","north",
"players/mosobp/areas/BATTLE/rooms/b28.c","northeast",
"players/mosobp/areas/BATTLE/rooms/b31.c","east",
"players/mosobp/areas/BATTLE/rooms/b33.c","southeast",
"players/mosobp/areas/BATTLE/rooms/b32.c","south",
"players/mosobp/areas/BATTLE/rooms/b29.c","west",
});
}
