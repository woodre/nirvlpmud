/*                                                                    *
 *    File:             /players/angel/area/nox/npc/fenri.c           *
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
  set_name("fenri");
  set_alt_name("fin");
  set_race("nox");
  set_short("Fenri");
  set_long("\
  This is a large flying beast. It has wide, thin wings that\n\
move as fast as a humming bird, and it can hover just like one.\n\
Its long tail has what looks like an Indian head on the end.\n");
  set_level(15);
  set_hp(250);
  set_ac(12 + random (3));
  set_wc(20 + random (3));
  set_al(100);
  set_heal(5,10);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(5);
  set_wander_realm("/players/angel/area/nox/room/");
  gold=clone_object("obj/money");
  gold->set_money(random(200)+1000);
  set_chat_chance(10);
  load_chat("You feel a tug at your hair as something moves by!\n");
  load_chat("A cool breeze moves through the air!\n");
}