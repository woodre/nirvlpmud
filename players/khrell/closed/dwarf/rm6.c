#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Khazad Naggrund"+NORM+" ("+HIK+"The Hungry Furnace"+NORM+")");
   set_long("\
  This shop has seen better days.  What was once a thriving place of\n\
business, now is a dust covered ruin.  Nothing of value remains in\n\
here, as it has been stripped to the now bare walls.\n"); 
   set_light(0);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "dust", "A fine layer of it covers the room",
         "walls", "Bare except for the dust"});
   dest_dir = ({
         "players/khrell/closed/dwarf/rm2.c", "south",
         });
   move_object(clone_object("/players/khrell/closed/dwarf/mob/forgegolem.c"), this_object());
   return 1; }      