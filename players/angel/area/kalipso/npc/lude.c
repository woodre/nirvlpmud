/*                                                                            *
 *      File:             /players/angel/area/kalipso/lude.c                  *
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
  set_name("lude");
  set_race("kalipic");
  set_alias("raptor");
  set_short("Lude");
  set_long(
  "    The Lude is a type of raptor. This animal fly's\n"+
  "all the time unless it is eating. It has a triangular\n"+
  "shaped head and only one leg.  Its leg connects striaght\n"+
  "off the bottom of its slinder body. For protection it\n"+
  "has an beak like an ice pick and three sharpe talons on\n"+
  "its foot.\n");
  set_level(1);
  set_hp(1);
  set_al(1);
  set_wc(1);
  set_ac(1);
  set_chat_chance(2);
  load_chat("\n");
  load_chat("\n");
}