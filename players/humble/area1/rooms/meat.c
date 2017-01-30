/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIR+"Meat Department"+NORM;
    long_desc =
    "This is the "+HIR+"Meat Department"+NORM+" .  It is immaculate\n"+
    "in every aspect.  The meat case contains all the packaged meat products\n"+
    "perfectly aligned with all the pricing tags.  The floor is spotless, the\n"+
    "meat cleavers located against the wall and the meat cutter\n"+
    "are all glimmering like diamonds.  Something seems a little\n"+
    "peculiar about this place.  Your not sure if you should hang out\n"+
    "or just leave quietly.\n";

    items =
    ({
    "cleaver",
    "There are enormous meat cleavers but one stands out amongst the others"+
    ".  It     seems to draw you to it, maybe you could try stealing it",
    "meat cutter",
    "An enormous meat cutter used to chop meat, careful chief!  This could take your hand off",
    "meat case",
    "The meat case looks so perfect, you should try to "+HIW+"mess"+NORM+" it up",
    });
    dest_dir =
    ({
    RPATH+"aisle5",        "south",
    });

    move_object(clone_object("players/humble/area1/mobs/mary.c"), this_object());
  }
}
