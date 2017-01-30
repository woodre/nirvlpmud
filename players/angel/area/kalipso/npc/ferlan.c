/*                                                                            *
 *      File:             /players/angel/area/kalipso/ferlan.c                *
 *      Function:         NPC                                                 *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2009 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/08/09                                            *
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
  set_name("ferlan");
  set_race("kalipic");
  set_alias("tree");
  set_short("Ferlan");
  set_long(
  "    This is a hybrid beast. It appears to be a tree.\n"+
  "Upon closer inspection it has moveable lower branches\n"+
  "as if it had arms. At he top of the Ferlan is a large\n"+
  "bush. The bark is wavy and the leaves appear to be\n"+
  "quite sharp.\n");
  set_level(1);
  set_hp(1);
  set_al(1);
  set_wc(1);
  set_ac(1);
  set_chat_chance(2);
  load_chat("\n");
  load_chat("\n");
}