/*                                                                            *
 *      File:             /players/angel/area/                                *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("farmer");
  set_race("human");
  set_alias("bob");
  set_short("Farmer Bob");
  set_long("\He looks Fierce!\n");
  set_level(10);
  set_hp(100);
  set_al(0);
  set_wc(15);
  set_ac(20);
  set_chat_chance(2);
  load_chat("Hello\n");
  load_chat("How are you?\n");
/*  gold=clone_object("obj/money");
  gold->set_money(random(###)+###);
  move_object(gold,this_object());
  weapon=clone_object("");
  move_object(weapon,this_object());
  armor=clone_object("");
  move_object(armor,this_object());*/
  set_dead_ob(this_object());
}
monster_died() {
  say(""+BOLD+"The Sergeant falls over in agony!!!"+NORM+"\n");
"/players/angel/closed/displays"->display_file("/players/angel/pic/man");
      environment(this_object());
  }