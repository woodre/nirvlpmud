/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/private_02.c *
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
  set_name("mp officer");
  set_alt_name("mp");
  set_alt_name("officer");
  set_race("military");
  set_alias("private");
  set_short(""+CYN+"MP Officer"+NORM+"");
  set_long("\
  The MP is a well trained. It would be foolish to fight him!\n");
  set_level(16);
  set_hp(300 + random (100));
  set_ac(13 + random (7));
  set_wc(23 + random (7));
  set_al(0);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(6);
  set_wander_realm("/players/angel/area/stargate/room/");
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  set_chat_chance(10);
  load_chat(query_name()+" says,  \"Show me your sercurity badge!\"\n");
}