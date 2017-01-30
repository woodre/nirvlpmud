/*                                                                            *
 *      File:             /players/angel/area/town/npc/ronald.c               *
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
  set_name("ronald");
  set_race("clown");
  set_alias("mcdonald");
  set_short(HIR+"R"+HIW+"o"+HIR+"n"+HIW+"a"+HIR+"l"+HIW+"d"+HIR+" M"+HIW+"c"+HIR+"D"+HIW+"o"+HIR+"n"+HIW+"a"+HIR+"l"+HIW+"d"+NORM);
  set_long("\
  Ronald McDonald, the Hamburger-Happy Clown.  Ronald McDonald\n\
as well as costume clown face persona wears a yellow jump suit\n\
with white and red striped arms.  His costume stands out equally\n\
as his bright red hair.\n");
  set_level(17);
  set_hp(350);
  set_al(1000);
  set_wc(24);
  set_ac(14);
  set_chat_chance(2);
  load_chat(query_name()+" says, \"Welcome boys and girls\"\n");
  load_chat(query_name()+" says, \"I'm loving it!!!\"\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+2000);
  move_object(gold, this_object());
}