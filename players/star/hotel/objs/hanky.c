/*
 *      File:                 /players/star/objs/hanky.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/18/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_id("handkerchief");
  set_alias("hanky");
  set_short("A White Handkerchief");
  set_long("This is a plain white hanky.\n");
  set_weight(1);
  set_value(50);
}
