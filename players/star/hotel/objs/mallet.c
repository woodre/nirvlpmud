/*
 *      File:                 /players/star/objs/mallet.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/14/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/weapon.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("mallet");
  set_short("A Roque Mallet");
  set_long("This mallet has a hard end and a softer end, as well as a rubber grip.\n");
  set_class(16);
  set_weight(2);
  set_value(400);
}
