/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/sargent.c    *
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
  set_name("sergeant");
  set_alt_name("soldier");
  set_race("military");
  set_alias("mpo");
  set_short(""+CYN+"Sergeant"+NORM+"");
  set_long("\
  The sergeant is a highly trained soldier.\n\
Anyone would be a fool to try and fight him!\n");
  set_level(20);
  set_hp(550 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(100)+3000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load p90", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"You are not allowed beyond this point!\"\n");
  load_chat("You need special clearance to continue on!\n");
  load_chat("This area is highly secure!\n");
  add_spell("shot","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
  set_dead_ob(this_object());
}
/* calls another NPC once it is killed */
monster_died() {
  say(""+BOLD+"The Sergeant screams for backup, then falls over in agony!!!"+NORM+"\n");
  
    move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"),
      environment(this_object()));
}