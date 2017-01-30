#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

object stan;
reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Stan's House";
long_desc =
"  The room is filled with family pictures that cover the walls.\n"+
"Two chairs are turned so that they face out the window.  A little\n"+  
"pet bed is sitting on the carpet where the light shines through.\n"+
"Some magazines are stacked neatly on a coffee table in the center.\n";

items = ({
  "pictures",
  "A family picture of Stan's family.  You can't help but notice his\n"+
  "sister Shelly and her metal head gear", 
  "chairs",
  "They are made entirely of leather", 
  "carpet",
  "It is orange shag carpet that has food stains in some spots",
  "magazines",
  "Terrance and Phillip magazines",
  "table",
  "A small coffee table with a glass top",
  "stains",
  "These are very old stains that look like they will never come out",
  "bed",
  "Sparky's little bed where he likes to take naps during the day",
  "walls",
  "They are covered almost entirely with family pictures", 
  "window",
  "The window is very clean and you can see outside",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r10.c","out",
  });
  stan = clone_object("/players/fred/SP/Mon/stan.c");
  move_object(stan, this_object());
}
