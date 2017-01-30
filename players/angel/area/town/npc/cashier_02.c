/*                                                                            *
 *      File:             /players/angel/area/town/npc/cashier.c              *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
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
  ::reset(arg);
  if(arg) return;
  set_name("cashier");
  set_race("human");
  set_alias("cashier");
/* mizan - capitalized 'cashier' */
  set_short("Cashier");
/* mizan - added comma */
  set_long("\A nice, soft spoken lady in her mid 50's.\n");
  set_level(30);
  set_hp(10000);
  set_wc(60);
  set_ac(60);
  set_al(1000);
  set_chat_chance(1);
  load_chat(query_name()+" asks, \"What would you like to order today?\"\n");
}

void
heart_beat()
{
  if(hit_point < max_hp)
  {
    hit_point = max_hp;
  }
  :: heart_beat();
}
