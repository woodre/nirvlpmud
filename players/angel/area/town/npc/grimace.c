/*                                                                            *
 *      File:             /players/angel/area/town/npc/grimace.c              *
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
  set_name("grimace");
  set_race("monster");
  set_alias("grim");
  set_short(""+HIM+"Grimace"+NORM+"");
  set_long("\
  Grimace is large and purple with short arms and legs, he is\n\
known for his smiling face and simple demeanor. His most common\n\
expression is the word 'duh'.  Grimace is a sort of well meaning\n\
doofus, whose clumsy antics provide a comic foil to the serious\n\
clown Ronald McDonald.\n");
  set_level(17);
  set_hp(350);
  set_al(500);
  set_wc(24);
  set_ac(14);
  set_chat_chance(12);
  load_chat(query_name()+" says, \"Duh............emm.......duh\"\n");
  load_chat(query_name()+" asks, \"Did you ask me something?\"\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+2000);
  move_object(gold, this_object());
}