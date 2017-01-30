/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/wp.c         *
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
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("wounded personal");
  set_alt_name("personal");
  set_race("military");
  set_alias("wounded");
  set_short("Wounded Personal");
  set_long(
  "This is a very wounded military personal.\n");
  set_level(5);
  set_hp(75);
  set_ac(9);
  set_wc(5);
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(200);
  move_object(gold, this_object());
  set_chat_chance(4);
  load_chat(query_name()+" says, \"Please let me be!\"\n");
  load_chat(query_name()+" says, \"Doc, you think I'll make it?\"\n");
}