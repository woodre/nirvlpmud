/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/mobs/skeleton.c      *
 *    Function:         mob                                           *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            mid lvl mob                                   *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object misc;
  ::reset(arg);
  if(arg) return;
  set_name(CYN+"Skeleton"+HIC+" <Undead>"+NORM);
  set_alt_name("skeleton");
  set_race(CYN+"skeleton"+NORM);
  set_alias("undead");
  set_short(CYN+"Skeleton"+HIC+" <Undead>"+NORM);
  set_long("The "+CYN+"Skeleton"+NORM+" has glowing "+HIG+"eyes"+NORM+" and appears not to be\n"+
  "afraid of you. Armed with mace and shield, the "+CYN+"Skeleton"+NORM+" raises his bony arms\n"+
  "to bring death to the living. The "+CYN+"Skeleton"+NORM+" moves at an incredible speed for\n"+
  "being undead. The "+CYN+"Skeleton"+NORM+" looks at you and cackles with glee!\n");
  set_level(18);
  set_hp(400 + random (100));
  set_ac(15 + random (4));
  set_wc(26 + random (4));
  set_al(-100);
  add_money(3500 +random(1000));
  set_chat_chance(15);
  load_chat(query_name()+" says, \"Finally.  A fresh soul to kill!\n");
  load_chat("The "+CYN+"Skeleton's"+NORM+" eyes burn a bright "+HIG+"Green"+NORM+"\n");
  load_chat("The "+CYN+"Skeleton"+NORM+" cackles with glee!\n");
  misc=clone_object("/players/valen/area/catacombs/misc/valen_key.c");
  move_object(misc, this_object());
  add_spell("smite", "#MN# $HR$SMITES$N$ you with a heavy mace!\n",
  				    "#MN# $HR$SMITES$N$ #TN# with a heavy blow!\n",
  				    50,60,"other|physical");
}