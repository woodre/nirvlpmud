/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/carter.c     *
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
  set_name("captain samantha carter");
  set_alt_name("carter");
  multipleIds=({"captain","samantha","carter"});
  set_race("military");
  set_alias("captian");
  set_short("Captain Samantha Carter");
  set_long("\
  SG-1's science expert and theoretical astrophysicist, Samantha Carter is\n\
responsible for deciphering the Stargate address system and designing the\n\
dialing computer, allowing Earth to use the Stargate without its companion\n\
D.H.D. Brave, devoted and extremely intelligent, she is Earth's leading\n\
authority on the Stargate and wormhole theory, as well as a member of the\n\
Air Force.\n");
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
  load_chat(query_name()+" says, \" I have to figure out how to make this work!\"\n");
  load_chat(" Where did that part go?\n");
  add_spell("P90","#MN# shoots the $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots the $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}
