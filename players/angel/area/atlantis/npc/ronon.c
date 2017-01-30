/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/ronon.c      *
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
  set_name("ronon");
  set_alt_name("dex");
  set_race("military");
  set_alias("soldier");
  set_short(""+HIG+"Ronon Dex"+NORM+"");
  set_long(
  "Once a military soldier on the planet Sateda, Specialist\n"+
  "Ronon Dex became a runner when the Wraith took him from\n"+
  "his home. Ronon defended his world during a devastating\n"+
  "Wraith culling. Upon learning that the Wraith destroyed\n"+
  "Sateda, Ronon decided to join the Tari at Atlantis.\n"+
  "Satedion physiology is several time stronger than human.\n"+
  "Attacking him would be insane.\n");
  set_level(29);
  set_hp(2200);
  set_ac(30 + random (4));
  set_wc(56 + random (4));
  set_al(0);
  set_heal(10,10);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+28000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/atlantis/obj/rgun.c");
  move_object(weapon, this_object());
  set_chat_chance(8);
  load_chat("You're expecting me to let them get away with this?\n");
  load_chat("Aren't we supposed to follow?\n");
/*  This mob has three special spell attacks and one heal */
  set_multi_cast(1);
  add_spell("head bust",
    "#MN# swiftly swings his head around $G$B U S T I N G$N$ you, directly in your head!\n",
    "#MN#  $G$B U S T$N$ #TN#, direct hit!\n",
    20,({5,30}),({"physical","physical"}));
  add_spell("energy",
    "#MN# summons forth a massive $HM$B U R S T$N$, of Red Energy from his gun!\n",
    "#MN# summons forth a massive $HM$B U R S T$N$, of Red Energy from his gun!\n",
    20,({10,30}),({"physical","other|eletric"}));
  add_spell("Lazer fire",
    "#MN# releases a immense force  $HR$Red$N$-$HR$Bursts$N$  of Energy!\n",
    "#MN# releases a immense force  $HR$R E D$N$-$HR$B U R S T$!\n",
    15,({15,25}),({"other|fire","other|laser"}),1);
}
