/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/weir.c       *
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
  set_name("weir");
  set_alt_name("beth");
  set_race("military");
  set_alias("dr");
  set_short(""+HIG+"Elizabeth Weir"+NORM+"");
  set_long(
  "Dr. Weir is the Commander of the Atlantis expedition to\n"+
  "the Pegasus Galaxy.  An expert in international politics,\n"+
  "Dr. Weir is a civilian and a diplomat.  She speaks five\n"+
  "languages, including Russian and Latin  (the latter of\n"+
  "which is very similar to Ancient).\n");
  set_level(15);
  set_hp(250);
  set_ac(12);
  set_wc(20);
  set_al(50);
  gold=clone_object("obj/money");
  gold->set_money(random(100)+1000);
  move_object(gold, this_object());
  set_chat_chance(8);
  load_chat("Elizabeth Weir says:  Well, we've been through a lot together. Yes.\n");
  load_chat("Dr. Weir says:  You had it coming.\n");
 }