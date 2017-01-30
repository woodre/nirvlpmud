/*
 *      File:                 /players/star/cal/obj/diaper.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/10/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name ("diaper");
  set_short("A Diaper");
  set_long("This is a soft white diaper.\n");
  set_type("underwear");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
