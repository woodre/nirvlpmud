#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short("South Park");
   set_long(
      "  There is a small open area here where nobody has put a trailer yet.\n");

   add_smell("main","You take a deep breath and start to cough.....");
   add_listen("main","You hear a loud gunshot followed by someone yelling, \"Woooo eeee!!!!\".");
   add_exit("/players/fred/SP/Rooms/r21.c","south");
  
   /* For Waxy's Land Development */
   
   set_cost(20000);
   set_realm_name("South Park");
   set_lot_size("2"); /* small trailer */
   setup_land();
}
