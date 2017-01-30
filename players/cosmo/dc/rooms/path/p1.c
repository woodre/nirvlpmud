/* Path file */
#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_sound("A bird sings peacefully from a nearby tree.");
   set_smell("You smell vegetation around you. Spring is in the air.");
   set_room_type("path");
   short_desc="A gravel road";
   long_desc=
      "The gravel road is surprisingly easy to travel on.  The gravel\n"
     +"is not loose but actually held together by a sticky substance\n"
     +"that makes it much easier to walk on.  It looks like this road\n"
     +"was just recently constructed, and perhaps it isn't quite finished.\n"
     +"The road is slightly hilly and continues on to the northwest.\n";
 
   items= ({
     "gravel", "Small gray rocks layed down as a road foundation",
     "road", "You see nothing special",
     "substance", "It's dark and sticky, possibly tar",
     "bird", "You don't see it anywhere, but you hear it",
     "vegetation", "You don't see any, but you can smell it",
   });

   dest_dir= ({
     DCPATH+"p2", "northwest",
     "room/plane1", "southeast",
   });
}
