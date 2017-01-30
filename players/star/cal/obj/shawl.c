/*
 *      File:                 /players/star/cal/obj/shawl.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/10/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/armor";

#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shawl");
  set_alias("pink shawl");
  set_short(HIM+"A Pink Shawl"+NORM);
  set_long("A pink crocheted shawl with little tassels around the edges.\n");
  set_type("cloak");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
