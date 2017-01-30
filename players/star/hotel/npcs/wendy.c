/*
 *      File:                 /players/star/npcs/wendy.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/03/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("wendy");
  set_race("human");
  set_gender("female");
  set_short("Wendy Torrance");
  set_long("Wendy is the new caretaker's wife.  She is a short and thin woman with\n"+
    "brown eyes, shoulder length brown hair, and a very pretty smile.\n");
  set_level(12);
  set_hp(180);
  set_al(50);
  set_wc(16);
  set_ac(9);
  set_chat_chance(3);
  load_chat("Wendy says, \"I hope this job is good for Jack.\"\n");
  load_chat("Wendy asks, \"Have you seen Danny?\"\n");
  add_money(random(50)+500);
}
