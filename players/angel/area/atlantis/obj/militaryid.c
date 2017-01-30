/*                                                                    *
 *    File:             /players/angel/area/atlantis/obj/militaryid.c *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/1/06                                        *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("military id");
   set_alias("id");
   set_short("A military id");
   set_long(
    "A military id card with writing on it\n");
   set_read(
    "You can see the words id scan at the bottom.\n");
   set_weight(0);
   set_value(0);
}