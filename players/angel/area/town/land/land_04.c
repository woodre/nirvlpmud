/*                                                                    *
 *    File:             /players/angel/area/town/land/land_04.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

inherit "/players/earwax/housing/land";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIB+"Beech Drive"+NORM;
  long_desc =
"    125 Beech drive.\n\
  This is a beautiful, well-manicured, large, city lot.  The serene\n\
setting appears to give plenty of privacy.  There are many new oak\n\
trees planted around the yard.\n";

  items =
  ({
  "lot",
  "This piece of land has a wonderful view with\n\
lots of trees and rolling hills",
  "trees",
  "There are many average size live oak trees",
  "yard",
  "It is well manicured",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/beech_02", "road",
  });

  set_cost(100000);
  set_realm_name("Gas City");
  set_lot_size(9);
  setup_land();  

}