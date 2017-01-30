inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("mondar"))  {
    MOCO("/players/jareel/monsters/chaos/caves/mondar.c"),this_object()); }
  if(!present("joe"))  {
    MOCO("/players/jareel/monsters/town/bar_shop_owner.c"),this_object()); }
  if(!present("menu"))  {
    MOCO("/players/jareel/general_stuff/bar_shop_menu.c"),this_object()); }
  if (arg)
    return;

  set_light(1);
  short_desc=("The "+BOLD+RED+"Bloody"+NORM+" Axe");
  long_desc=
    "  On the north wall a large hearth fire is ablaze in a large stone\n"+
    "fireplace.  The walls of the bar are smudged a dark crimson red. The\n"+ 
    "chairs seem to have been pieced together as if they have been broken\n"+ 
    "over and over again.  An eccentric menu hangs over the bar.  To the\n"+
    "west a door leads to the road outside\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road9","west",
  });

}

