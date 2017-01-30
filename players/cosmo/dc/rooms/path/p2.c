/* Path file */
#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_room_type("path");
   short_desc="A recently paved road";
   long_desc=
      "The road is slightly more finished here as it continues to the\n"
     +"northwest and southeast.  Looking to the northwest, you begin\n"
     +"to see the skyline of a city.  Large oak and maple trees line\n"
     +"the sides of the street, providing shade from the midday sun.\n"
     +"A few low-lying bushes and shrubs also dot the path.\n";
 
   items= ({
     "city", "It's difficult to judge the size of it from this distance",
     "road", "You see nothing special",
     "trees", "The trees are quite large, indicating their age",
     "sun", "You're going to damage your eyes if you keep doing that",
     "bushes", "Mostly green, although a few are turning brown from lack of water",
     "shrubs", "They look about the same as the bushes",
   });

   dest_dir= ({
     DCPATH+"p3", "northwest",
     DCPATH+"p1", "southeast",
   });
}
