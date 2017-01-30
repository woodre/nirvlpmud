/*                                                                            *
 *      File:             /players/angel/area/kalipso/serdawnd.c              *
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
  set_name("serdawnd");
  set_race("kalipic");
  set_alias("dawn");
  set_short("Serdawnd");
  set_long(
  "    This fierce beast is over 90 feet tall. It is black\n"+
  "with spiked scales covering its entire body. Its elongated\n"+
  "neck with a smaller head allows it to get in small spaces\n"+
  "for food. On top of its head sit two cone shaped horns.\n");
  set_level(1);
  set_hp(1);
  set_al(1);
  set_wc(1);
  set_ac(1);
  set_chat_chance(2);
  load_chat("\n");
  load_chat("\n");
}