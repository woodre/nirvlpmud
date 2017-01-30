/******************************************************************************
 *  File:           nanobot.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 3001.03.07
 *  Notes:
 *  Change History: 2003.09.11; 2005.10.22 [strict_type'd and fixed id's]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"
inherit "/players/vital/closed/std/monster.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("nanobot");
  set_race("machine");
  set_alias("bot");
  set_short(BLINK + HIW + "Nano" + HIR + "bots" + NORM);
  set_long(format("This tiny, little computer is called upon to help the \
controller."));
  set_level(random(3) + 1);
  set_aggro(1,10,100);
  set_chance(45);
  set_spell_mess1("Bzzzt!\n");
  set_spell_mess2("Grrrnnnggg ping pop!\n");
  set_spell_dam(15);
  set_info(format("This nanobot can be configured to do nearly anything. \
It's not very strong.\n"));
}
