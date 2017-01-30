/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/wraith.c     *
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
  set_name("wraith");
  set_alt_name("sucker");
  set_race("wraith");
  set_alias("vamp");
  set_short(""+CYN+"Wraith"+NORM+"");
  set_long(
  "This is a vampirous, hive-based species that harvest on the\n"+
  "life-force of other beings for nourishment through suckers\n"+
  "on their palms. They use their mental powers to forcefully\n"+
  "interrogate humans.\n");
  set_level(23);
  set_hp(800);
  set_ac(21);
  set_wc(40);
  set_al(-1000);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(500)+8000);
  move_object(gold, this_object());
  set_chat_chance(12);
  load_chat("When I am free, you'll be the first that I feed upon.\n");
  load_chat("I am feeling a bit hungry.\n");
  /*  This mob has one special spell attacks and one heal */
  add_spell("drain",
    "#MN# sucks a massive $HM$D R A I N$N$, of energy!\n",
    "#MN# sucks a massive $HM$D R A I N$N$, of energy from you!\n",
    20,({50,40}),({"physical","other|eletric"}));
}