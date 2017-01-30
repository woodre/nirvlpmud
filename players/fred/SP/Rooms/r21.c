#include "/players/fred/ansi.h"
inherit "/players/vertebraker/closed/std/room";
inherit "/players/earwax/housing/land";

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short("South Park");
   set_long(
      "  The ground is pretty barren outside of some scattered litter and\n"+
      "a few patches of weeds.  Beat up trailer homes are all around.  Most\n"+
      "are small and starting to rust.  Several small kids are running back\n"+
      "and forth in the dirt.  The sound of loud country music fills the air.\n");

   add_item("ground","The ground is made up of packed dirt and patches of weeds.");
   add_item("weeds","Bright green weeds just starting to come throught the dirt.");
   add_item("kids","Small children dressed in old clothes.");
   add_item("trailers","Old ass beat up trailers....people live here?");
   add_item("trailer","Old ass beat up trailer....people live here?");
   add_item("home","One trailer has a \"If this here trailers a rockin' don't come a knockin'\" sign on it.");
   add_smell("main","You take a deep breath and start to cough.....");
   add_listen("main","You hear a loud gunshot followed by someone yelling, \"Woooo eeee!!!!\".");
   add_exit("/players/fred/SP/Rooms/r23.c","north");
   add_exit("/players/fred/SP/Rooms/r20.c","west");

   /* For Waxy's Land Development */
   
   set_cost(20000);
   set_realm_name("South Park");
   set_lot_size("2"); /* small trailer */
   setup_land();
}
