#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"Garden of Love"+NORM;
   long_desc =
   " Fetid green plants blanket the ground all around the\n"+
   "broken fountains in the center of this open air atrocity.\n"+
   "A destroyed path lined by fallen and broken marble pillars\n"+
   "block access to any of the other rooms.  There is a sign\n"+
   "hanging on the chapel door.\n";
   add_item("plants","Plants on the verge of death");
   add_item("fountains","Spralwed across the room the broken fountains carry no water");
   add_item("pillars","Pillars that once held a great cathedral, fallen, and useless");
   add_item("sign","You cannot make out any of the words on the sign");
   add_object("/players/jaraxle/3rd/alt/mobs/hera.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/yard.c","south");
}
