/* Path file */
#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_room_type("path");
   short_desc="A paved road";
   long_desc=
      "As the road approaches the city it becomes better maintained and\n"
     +"easier to travel on.  There are fewer trees and bushes here - the\n"
     +"unfortunate consequences of an urban environment.  The city looms\n"
     +"on the horizon to the northwest.  There is an overhead street lamp\n"
     +"on the side of the road here.\n";
 
   items= ({
     "city", "Now that you're closer, you see that it's not really very big",
     "road", "You see nothing special",
     "trees", "The trees are smaller here",
     "lamp", "It provides the road with light at night",
     "bushes", "These bushes all look dead",
   });

   dest_dir= ({
     DCPATH+"p4", "northwest",
     DCPATH+"p2", "southeast",
   });
}
