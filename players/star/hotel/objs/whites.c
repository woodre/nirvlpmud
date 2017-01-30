/*
 *      File:                 /players/star/objs/whites.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/18/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cook's whites");
  set_alias("whites");
  set_short("Cook's Whites");
  set_long("The large, white, billowy shirt worn by a cook.\n");
  set_type("armor");
  set_ac(3);
  set_params("fire", 0, 10, "void");
  set_weight(2);
  set_value(100);
}
