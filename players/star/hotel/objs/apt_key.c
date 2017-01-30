/*
 *      File:                 /players/star/objs/apt_key.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/07/2005
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("key");
  SetMultipleIds( ({ "key", "metal key", "ol_apt_key" }) );
  set_short("A Metal Key");
  set_long("This is a plain metal key.\n");
  set_weight(1);
  set_value(5);
}
