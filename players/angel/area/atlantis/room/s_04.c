/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/s_04.c      *
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

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Hall";
  long_desc =
"    "+WHT+"~ STAIRS ~"+NORM+"\n\
"+HIB+"  Atlantis was built by the ancients. The massive complex\n\
is more high tech than anyone has ever seen. The stairs lead to the\n\
Operations Center. There are illuminated words written into the\n\
stairs in Ancient. The lighting and all room functions turn on and\n\
off as people walk in and out of each area."+NORM+"\n";

  items =
  ({
    "stairs",
    "words written in Ancient illuminate the stairs",
    "center",
    "central operations",
    "words",
    "they are similar to Latin and somehow illuminate",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/oc.c",       "east",
    "/players/angel/area/atlantis/room/s_03.c",     "west",
  });
}