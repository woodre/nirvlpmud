/*
 *      File:                 /players/star/hotel/npcs/danny.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/24/2006
 *      Notes:
 *      Change History:
 */

#include </players/star/defs.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("danny");
  set_race("human");
  set_gender("male");
  set_short("Danny Torrance");
  set_long("This is Danny Torrance, the new care-taker's son.  He looks about\n"+
    "five years old and has blonde hair and blue eyes.  He knows he isn't\n"+
    "supposed to play up here and looks at you with a guilty look on his\n"+
    "small freckled face.\n");
  set_level(10);
  set_hp(150);
  set_al(100);
  set_wc(14);
  set_ac(8);
  set_chat_chance(3);
    load_chat("Danny says, \"Please don't tell Mommy and Daddy I was up here.\"\n");
    load_chat("Danny says, \"There's something scary in the bathroom in 217.\"\n");
    load_chat("Danny says, \"Dick doesn't think the things I see can hurt me.\"\n");
  add_money(random(50)+400);
}
