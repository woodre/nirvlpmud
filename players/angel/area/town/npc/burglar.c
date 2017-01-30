/*                                                                            *
 *      File:             /players/angel/area/town/npc/burglar.c              *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("hamburglar");
  set_race("monster");
  set_alias("ham");
  set_short(HIW+"H"+BLK+"a"+HIW+"m"+BLK+"b"+HIW+"u"+BLK+"r"+HIW+"g"+BLK+"l"+HIW+"a"+BLK+"r"+NORM);
  set_long("\
  The Hamburglar steals McDonald's hamburgers, Ronald McDonald\n\
devises a plan to trick him, and everybody gets their hamburgers\n\
back. He dresses in a black-and-white striped shirt and pants,\n\
a red cape, and a wide-brimmed hat.\n");
  set_level(17);
  set_hp(350);
  set_al(-100);
  set_wc(24);
  set_ac(14);
  set_chat_chance(12);
  load_chat(query_name()+" asks, \"Can I see that burger?\"\n");
  load_chat("Hamburglar just ran off stage with your hamburger!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+2000);
  move_object(gold, this_object());
}