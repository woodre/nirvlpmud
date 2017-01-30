/*
 *      File:                 /players/star/objs/y_dress.c
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
  set_name("yellow dress");
  set_alias("dress");
  set_short("A Yellow Dress");
  set_long("This is a pretty "+HIY+"yellow "+NORM+"dress.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(100);
}
