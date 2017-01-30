/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/corporal.c   *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/1/06                                        *
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
  set_name("corporal");
  set_alt_name("solider");
  set_race("military");
  set_alias("mpo");
  set_short(""+CYN+"Corporal"+NORM+"");
  set_long("\
  The corporal is a highly trained machine.\n\
Anyone would be a fool to try and fight him!\n");
  set_level(18);
  set_hp(400 + random (100));
  set_ac(15 + random (9));
  set_wc(26 + random (9));
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(500)+2000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"You are not allowed beyond this point!\"\n");
  load_chat("This is a highly secure area!\n");
  add_spell("P90","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}