#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Small yard"+NORM;
   long_desc =
   "  A small, decomposed yard surrounded by abandoned\n"+
   "houses. To the north looks like a doddering chapel.\n";
   add_item("houses","These houses have been abandoned for ages");
   add_item("chapel","To the north, an inactive chapel was built");
   add_object("/players/jaraxle/3rd/alt/mobs/beggar.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/road1.c","south");
   add_exit("/players/jaraxle/3rd/alt/rooms/pub.c","east");
   add_exit("/players/jaraxle/3rd/alt/rooms/alley.c","west");
   add_exit("/players/jaraxle/3rd/alt/rooms/chapel.c","north");
   
}

