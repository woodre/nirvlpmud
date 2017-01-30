/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/teyla.c      *
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
  set_name("teyla");
  set_alt_name("emmagan");
  set_race("military");
  set_alias("athosian");
  set_short(""+HIG+"Teyla"+NORM+"");
  set_long(
  " Tayla is the daughter of Tagan, and leader of the Athosians\n"+
  "from the planet Athos. Teyla is a strong and capable warrior,\n"+
  "and a confident leader. Though she was reluctant to say good\n"+
  "bye to her people to remain in Atlantis with a reconnaissance\n"+
  "team. Don't attack her or she will kick your ass!\n");
  set_level(28);
  set_hp(1800);
  set_ac(26);
  set_wc(52);
  set_al(0);
  set_heal(5,10);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+23000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/atlantis/obj/rakan.c");
  move_object(weapon, this_object());
  set_chat_chance(8);
  load_chat("I am the leader of the Athosians!\n");
  load_chat("I have traded in many marketplaces, on many worlds.\n");
  set_multi_cast(1);
  add_spell("head bust",
    "#MN# swiftly swings her head around $G$B U S T I N G$N$ you, directly in your head!\n",
    "#MN#  $G$B U S T$N$ #TN#, direct hit!\n",
    20,({5,30}),({"physical","physical"}));
  add_spell("flesh hit",
    "#MN# "+HIB+"manipulates the BO  S T A F F and SLICES your F O E ' S flesh!"+NORM+"\n",
    "#MN# "+HIB+"manipulates the BO  S T A F F and SLICES your F O E ' S flesh!"+NORM+"\n",
    20,({10,40}),({"physical","physical"}));
}