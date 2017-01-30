#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   get_random_mob();
   short_desc = BLK+BOLD+"The adventurers guild"+NORM;
   long_desc =
   "The adventurers guild\n"+
   "  This room is littered with torn pages from rotten\n"+
   "and ransacked books.  Great knowledge was obtained here\n"+
   "at one time. There are some broken stairs that used to\n" +
   "lead up to the second level of the adventurers guild.\n";
   add_item("pages","Non legible pages from numerous books");
   add_item("books","From the size, these look like they were great books");
   add_item("stairs","The stairs leading up have fallen");
   add_exit("/players/jaraxle/3rd/alt/rooms/road2.c","north");
   
}

