/*
 *      File:                 /players/star/objs/b_dress.c
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
  set_name("blue dress");
  set_alias("dress");
  set_short("A Blue Dress");
  set_long("This is a pretty "+HIB+"blue "+NORM+"dress.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(100);
}
