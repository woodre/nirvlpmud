/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/halling.c    *
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
  set_name("halling");
  set_alt_name("athosian");
  set_race("athosian");
  set_alias("father");
  set_short(""+HIG+"Halling"+NORM+"");
  set_long(
  "Halling is an Athosian citizen, father to Jinto. Halling\n"+
  "was the first adult Athosian who encountered the pioneering\n"+
  "Atlantis team on the planet Athos. A deeply spiritual man,\n"+
  "Halling is very loyal to his people.\n");
  set_level(20);
  set_hp(500);
  set_ac(17);
  set_wc(30);
  set_al(0);
  set_heal(5,5);
  gold=clone_object("obj/money");
  gold->set_money(random(300)+2000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/atlantis/obj/rakan.c");
  move_object(weapon, this_object());
  set_chat_chance(5);
  load_chat("Our people live on the mainland.\n");
  load_chat("You are welcome to come visit.\n");
  set_multi_cast(1);
  add_spell("flesh hit",
    "#MN# "+HIB+"manipulates the BO  S T A F F and SLICES your F O E ' S flesh!"+NORM+"\n",
    "#MN# "+HIB+"manipulates the BO  S T A F F and SLICES your F O E ' S flesh!"+NORM+"\n",
    20,({10,40}),({"physical","physical"}));
  add_spell("kyusho",
    "#MN# strikes with a devistating $HM$HEAVY HAND$N$ Kyusho technique!\n",
    "#MN# strikes with a devistating $HM$HEAVY HAND$N$ Kyusho technique!\n",
    20,({10,40}),({"physical","physical"}));
}