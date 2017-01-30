#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("octopus");
   set_alias("al");
   set_short("Al, the stuffed octopus");
   set_long(
      "This is Al, a small "+BOLD+MAG+"purple"+NORM+" stuffed octopus.  He is an unofficial mascot\n"+
     "of the Red Wings.  Detroit fans have traditionally thrown real octopuses\n"+
     "onto the ice because the eight tentacles symbolized the 8 wins needed\n"+
     "to capture the Stanley Cup.\n");
   set_weight(1);
   set_value(40);
}
