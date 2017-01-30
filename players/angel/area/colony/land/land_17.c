#include <ansi.h>

inherit "room/room";

inherit "/players/earwax/housing/land";

reset(arg)
{
  ::reset(arg);
  if(!present("new sign"))
     move_object(clone_object("/players/angel/area/colony/obj/sign"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Gas City Lot 17";
  long_desc =
"    227 Colony Way\n\
   This is a beautiful, well-manicured, large, ten-acre wooded\n\
lot.  The woods seem to surround the lot with a nice size clearing\n\
in the middle, perfect for a home.  The serene setting appears to\n\
give plenty of privacy.  This lot is in the Colony Way Subdivision\n\
at the edge of town.\n";

  items =
  ({

  "woods",
  "The woods are filled with large live oak trees",
  "lot",
  "This piece of land has a wonderful view with lots of trees\n\
and rolling hills",
  "subdivision",
  "This is an area of land composed of subdivided lots",
  "sign",
  "Maybe you should try to 'read' it",
  });

  dest_dir =
  ({
"/players/angel/area/colony/room/colony_06", "road",
  });

  set_cost(250000);
  set_realm_name("Gas City");
  set_lot_size(9);
  setup_land();

}