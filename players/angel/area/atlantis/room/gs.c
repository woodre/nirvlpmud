/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/            *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  /*
  if( !present(" ", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object(" "), this_object());
    }
}*/
if(arg) return;
  set_light(1);
  short_desc = "GROUNDING STATIONS";
  long_desc =
"    "+WHT+"~ GROUNDING STATIONS ~"+NORM+"\n\
"+HIB+"  Here, massive grounding rods channel lightning from the highest\n\
lightning rods, dispelling the energy back into the ocean.  The\n\
grounding stations are designed in the event that lightning is\n\
needed to power the city, supplementing Z.P.M.'s. Sophisticated\n\
terminals can separate the rods."+NORM+"\n";

  items =
  ({
    " ",
    " ",
  });

  dest_dir =
  ({
  });
}