/*                                                                    *
 *    File:             /players/angel/area/atlantis/room/lq_02.c     *
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
  short_desc = "LIVING QUARTERS";
  long_desc =
"      "+WHT+"~ WIRE'S LIVING QUARTERS ~"+NORM+"\n\
"+HIB+"  This is Wire's room. It is one large open area.  Everything seems\n\
to have its place. This quarters is suited for a single occupant.\n\
There are two paintings on the north wall of people in battle. She\n\
also has a couple of bookcases full of books."+NORM+"\n";

  items =
  ({
    "paintings",
    "pictures of people in battle, at the bottom is a plaque",
    "painting",
    "a picture of people in battle, at the bottom is a plaque",
    "bookcase",
    "a large wood shelving unit",
    "bookcases",
    "large wood shelving units",
    "book",
    "there are many hard backs",
    "books",
    "there are many hard backs",
    "plaque",
    "The Zulu War of 1879",
  });

  dest_dir =
  ({
	"/players/angel/area/atlantis/room/hall_08.c",     "east",
  });
}