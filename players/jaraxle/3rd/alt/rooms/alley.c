#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"Dirty alley"+NORM;
   long_desc =
   "  A long forgotten corner of the village where\n"+
   "hookers and deviants used to hang out.  A pub\n"+
   "which is long since closed stood to the south.\n";
   add_item("pub","A long forgotten pub");
   add_object("/players/jaraxle/3rd/alt/mobs/trixie.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/yard.c","east");
   
}

