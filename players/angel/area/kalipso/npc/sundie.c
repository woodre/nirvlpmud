/*                                                                            *
 *      File:             /players/angel/area/kalipso/sundie.c                *
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
  set_name("sundie");
  set_race("kalipic");
  set_alias("bird");
  set_short("Sundie");
  set_long(
  "    The Sundie has a wavy neck, a curved down beak, and\n"+
  "two small wings. It has two short skinny legs allowing\n"+
  "it to move quickly.  Its feathers are florescent orange.\n");
  set_level(1);
  set_hp(1);
  set_al(1);
  set_wc(1);
  set_ac(1);
  set_chat_chance(2);
  load_chat("\n");
  load_chat("\n");
}