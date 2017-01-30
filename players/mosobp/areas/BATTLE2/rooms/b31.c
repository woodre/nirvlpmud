#include "/obj/ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = YEL+"Atop a Cliff"+NORM;
long_desc = 
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/BATTLE/rooms/b27.c","northwest",
"players/mosobp/areas/BATTLE/rooms/b28.c","north",
"players/mosobp/areas/BATTLE/rooms/b33.c","south",
"players/mosobp/areas/BATTLE/rooms/b32.c","southwest",
"players/mosobp/areas/BATTLE/rooms/b30.c","west",
});
}
