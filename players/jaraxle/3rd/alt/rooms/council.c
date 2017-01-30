#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"The town council"+NORM;
   long_desc =
   "  This look like old town council chambers where\n"+
   "the inhabitants posted issues to vote upon.  A\n"+
   "few notices lay grounded on the dry floor.\n";
   add_item("notices","Which notice would you like to look at?\n   <notice 1> <notice 2> <notice 3>");
   add_item("notice 1","[10/03/98] Vote to kill Armageddon");
   add_item("notice 2","[12/25/99] Boltar to decide fate of Nirvana");
   add_item("notice 3","[01/01/04] Jaraxle for King");
   add_exit("/players/jaraxle/3rd/alt/rooms/church.c","south");
   
}

