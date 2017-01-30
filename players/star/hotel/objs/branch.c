
/*
 *      File:                 /players/star/hotel/objs/branch.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2014 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               04/26/2014
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_id("branch");
  set_alias("branch");
  set_short("A Branch");
  set_long("This is a short branch that looks a little pointy on one end, but seems\n"+
    "far too flimsy to be of any use.\n");
  set_weight(1);
  set_value(100);
}
