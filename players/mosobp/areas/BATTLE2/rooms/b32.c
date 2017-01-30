#include "/obj/ansi.h"
inherit "room/room";
reset(arg) {
  if(arg) return;

short_desc = YEL+"Atop a Cliff"+NORM;
long_desc =
"blah.\n";
set_light(1);
dest_dir = ({
"players/mosobp/areas/BATTLE/rooms/b29.c","northwest",
"players/mosobp/areas/BATTLE/rooms/b30.c","north",
"players/mosobp/areas/BATTLE/rooms/b31.c","northeast",
"players/mosobp/areas/BATTLE/rooms/b33.c","east",
});
}
