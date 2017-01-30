/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/mitchell.c   *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/5/06                                        *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("cameron mitchell");
  set_alt_name("colonel");
  set_race("military");
  set_alias("mitchell");
  set_short("Lt. Colonel Mitchell");
  set_long("\
  Lt. Colonel Cameron Mitchell is the commanding officer of SG-1.\n\
Mitchell is a daring fighter pilot, who led an F-302 squadron in\n\
the battle with Anubis's forces over Antarctica\n");
  set_level(22);
  set_hp(700 + random (100));
  set_ac(20 + random (7));
  set_wc(38 + random (7));
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+5000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"You can't take us on!\"\n");
  load_chat("INTRUDER, call for back up!\n");
  add_spell("P90","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}