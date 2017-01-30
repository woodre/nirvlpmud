/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/mckay.c      *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           10/05/07                                      *
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
  set_name("rodney mckay");
  set_alt_name("rodney");
  set_race("military");
  set_alias("mckay");
  set_short(""+HIG+"Dr. McKay"+NORM+"");
  set_long(
  "Dr. McKay is an astrophysicist and one of the world's leading\n"+
  "experts on the Stargate. He has an arrogant and condescending\n"+
  "personality, but he allowed himself to be a test subject for the\n"+
  "gene therapy Dr. Beckett created. McKay has found that he now can\n"+
  "activate Ancient devices.\n");
  set_level(13);
  set_hp(195);
  set_ac(10);
  set_wc(17);
  set_al(0);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(100)+200);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  command("unwield P90", this_object());
  set_chat_chance(8);
  load_chat("Well, It's gonna take longer than that!\n");
  load_chat("Could you just, Give me a minunet!\n");
  add_spell("shot","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                   "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                    25,30,"other|physical");
}