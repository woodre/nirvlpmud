/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/tp_02.c     *
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
  short_desc = " Transporter 2";
  long_desc =
"      "+WHT+"~ Transporter 2 ~"+NORM+"\n\
"+HIB+"  Atlantis transporters can move people to different areas of\n\
atlantis.  There are three screens on the north wall.  The\n\
center screen is in english."+NORM+"\n";

  items =
  ({
    "screen",
    "The follow places you can move to from here:\n\
    Brig, Labs, Gate, and Bay",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_10.c",     "west",
	"/players/angel/area/atlantis/room/tp_03.c",       "brig",
	"/players/angel/area/atlantis/room/tp_04.c",       "labs",
	"/players/angel/area/atlantis/room/tp_01.c",       "gate",
	"/players/angel/area/atlantis/room/tp_05.c",       "bay",
  });
}