/*
 *      File:                 /players/star/objs/g_dress.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/16/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("green dress");
  set_alias("dress");
  set_short("A Green Dress");
  set_long("This is a pretty "+HIG+"green "+NORM+"dress.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(100);
}
