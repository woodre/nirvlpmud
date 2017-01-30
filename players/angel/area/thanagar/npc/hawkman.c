/*                                                                    *
 *    File:             /players/angel/area/         *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           09/09/08                                      *
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
  object gold, armor;
  ::reset(arg);
  if(arg) return;
  set_name("hawkman");
  set_alt_name("hawk");
  set_race("thangorian");
  set_alias("man");
  set_short("Hawkman");
  set_long("\
  \n");
  set_level(29);
  set_hp(2000);
  set_ac(34 + random (8));
  set_wc(58 + random (8));
  set_al(1000);
  set_heal(40,20);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+3000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/  ");
  move_object(armor, this_object());
  command("wear boots", this_object());
  set_chat_chance(2);
  load_chat("   \n");
  load_chat("  \n");
 
  set_multi_cast(3);
  add_spell("forcefield",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds his body reflecting your attack!\n",
    10,({25,25}),({"physical","physical"}));
  add_spell("fist",
    "#MN# swiftly swings his fist $G$B U S T I N G$N$ #TN#, directly in the head!\n",
    "#MN# swiftly swings his fist $G$B U S T I N G$N$ #TN#, directly in the head!\n",
    20,({5,40}),({"physical","physical"}));
  call_out("random_move",10);
}