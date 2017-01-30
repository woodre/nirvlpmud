/*                                                                    *
 *    File:             /players/angel/area/lowthar/room/start.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

#include "/players/angel/area/stargate/obj/dial_obj.c"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!present("dhd"))
     move_object(clone_object("/players/angel/area/atlantis/obj/dhd"), this_object());
  if(!present("sign"))
    move_object(clone_object("/players/angel/area/lowthar/obj/sign.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIY+"Lowthar's Stargate"+NORM;
  long_desc =
"     "+HIY+"~ The Land of Lowthar ~"+NORM+"\n\
"+BROWN+"    These are dangerous times in the land of lowthar. Fierce Mawr\n\
hounds prowl the dark roads, and grymclaws patrol the skies. There\n\
is talk of an evil power rising in the east. Beware of what you may\n\
face in this realm. The stargate can be seen from here."+NORM+"\n";

  items =
  ({
    "sign",
    "Maybe you should try to 'read' the sign",
    "hounds",
    "",
    "roads",
    "",
    "grymclaws",
    "",
    "realm",
    "",
    "skies",
    "The skies are dark and gloomy",
  });

  dest_dir =
  ({
    "/players/angel/area/lowthar/room/pen_01", "road",
  });
}