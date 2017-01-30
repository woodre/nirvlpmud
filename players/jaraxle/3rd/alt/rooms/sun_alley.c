#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"Sun alley"+NORM;
   long_desc =
   "  An archway covered alley that runs east and west along the\n"+
   "edge of an old mountain range.  Heavy rocks and boulders line\n"+
   "the southern edge of the path.\n";
   add_item("road","The road is covered in dust");
   add_item("dust","Fine dust, possibly from nuclear destruction of the pebble covered road");
   add_item("path","The path that you have followed on the east road has become\nunwalkable further to the north");
   add_item("archway","A rotted archway of wood");
   add_item("alley","A small walkway to the west, under an old archway");
   add_exit("/players/jaraxle/3rd/alt/rooms/eastroad3.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/sun_alley2.c","west");
}

