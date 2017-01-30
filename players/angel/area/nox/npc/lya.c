/*                                                                    *
 *    File:             /players/angel/area/nox/npc/lya.c             *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           07/01/08                                      *
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
  set_name("lya");
  set_alt_name("nox");
  set_race("nox");
  set_alias("nox");
  set_short("");
  set_long("\
  Lya a Nox woman, is the wife of Anteaus, and mother of Nafrayu.\n\
She is a friend to the Tollans and Daniel. She is about five feet\n\
tall and her hair is wild.\n");
  set_level(28);
  set_hp(1800);
  set_ac(26 + random (5));
  set_wc(52 + random (5));
  set_al(0);
  set_heal(30,10);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(6);
  set_wander_realm("/players/angel/area/nox/room/");
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+24000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/nox/obj/boots.c");
  move_object(armor, this_object());
  command("wear boots", this_object());
  set_chat_chance(2);
  load_chat("A sweet smell moves through the air!\n");
  load_chat("A cool breeze moves through the air!\n");
  /*This NPC is invisible w/a silent_move_object, moves, has a heal, and has 1 multi cast(3) spell*/
  set_multi_cast(2);
  add_spell("forcefield",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds her body reflecting your attack!\n",
    "#MN# concentrates and a $HW$FORCEFIELD$N$ surrounds her body reflecting your attack!\n",
    10,({25,25}),({"physical","physical"}));
}

short() { return 0; }