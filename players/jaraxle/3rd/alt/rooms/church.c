/* 05/26/06 Earwax: I think the intent was for this mob to be 1/6
 * resets, not once a boot, 1/6 boots.
 */
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if (!arg) {
     set_light(0);
     get_random_mob();
     short_desc = BLK+BOLD+"Village church"+NORM;
     long_desc =
     "  An old forgotten place of worship and prayer.  A rotted\n"+
     "and decaying clock is leaning heavilly against the dusty\n"+
     "stone wall.  A tattared altar in the middle of the room\n"+
     "looks as if it has seen many a war.\n";
     add_item("clock","A non-working clock of times past");
     add_item("altar","An ancient altar of wood, broken and useless");
     add_item("wall","Stone walls, broken and barely holding up");
     add_exit("/players/jaraxle/3rd/alt/rooms/green.c","south");
     add_exit("/players/jaraxle/3rd/alt/rooms/clinic.c","east");
     add_exit("/players/jaraxle/3rd/alt/rooms/council.c","north");
   }
   if( !random(3) )
      add_object("/players/jaraxle/3rd/alt/mobs/armageddon.c");
   
}

