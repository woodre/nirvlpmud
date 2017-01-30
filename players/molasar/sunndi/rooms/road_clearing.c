
/*
 *
 * Road to Sunndi
 *
 */


/* Inherit standard room */
inherit "/std/room";

#include "/players/molasar/sunndi/include/filter_color.h"
#include "/players/molasar/sunndi/include/sunndi.h"

reset(arg) {
   if (arg) 
      return;

   set_long(long_desc);
   set_short(filter_color("Sunndi Road Clearing",HIC));
   set_long(
      "This is my long description. Next to a " + filter_color("sofa", HIW) + "\n" + 
      "is a table with a " + filter_color("pen", HIW) + ". In the corner of the\n" +
      "room is large " + filter_color("plant", HIW) + " in a large blue pot.\n"
   );
   set_light(1);
   set_dest_dir(
      ({
         "/players/molasar/sunndi/rooms/road2","east",
      })
   );
   add_item("sofa", "A sofa");
   add_item("plant", "A plant");
   add_item("pen", "A pen");

}


