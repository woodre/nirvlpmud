/* Path file */
#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_room_type("path");
   short_desc="A well-paved road";
   long_desc=
      "To the north there is a busy city street and an old aging building.\n"
     +"There are no more trees or bushes here, only concrete and pavement.\n"
     +"Another overhead street lamp stands on the side of the road.  Looking\n"
     +"north, the city doesn't look like much, but there is some construction\n"
     +"going on, so maybe this place will experience some growth in the\n"
     +"future.\n";
 
   items= ({
     "city", "A city?! HA! It's just one building and one street",
     "concrete", "You see nothing special about the concrete",
     "pavement", "You see nothing special about the pavement",
     "lamp", "It provides the road with light at night",
   });

   dest_dir= ({
     "players/cosmo/apt/rooms/rstreet", "north",
     DCPATH+"p3", "southeast",
   });
}
