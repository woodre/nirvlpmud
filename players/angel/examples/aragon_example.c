/******************************************************************************
*  File:           aragon.c
*  Author(s):      Vital@Nirvana
*  Copyright:      Copyright (c) 1997 Vital@Nirvana
*                  All Rights Reserved.
*  Source:         Started 30/11/2001
*  Notes:          
*  Change History: 04/09/2005
*****************************************************************************/
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("aragon");
  set_alias("dragon");
  set_short("An "+CYN+"aragon"+NORM);
  set_long("\
This is a amorphous, whispy creature with two light sets of wings \n\
that flutter rapidly in the breeze. It doesn't have any other limbs \n\
but it does have a writhing, twisting, thin tail.\n");
  set_level(random(5)+2);
  set_ac(10);
  set_wc(10);
  set_info("This "+CYN+"aragon"+NORM+" is often very hard to hit.\n");
  set_dead_ob(this_object());
}

monster_died()
{
  object corpse, tail;
  corpse = present("corpse", environment());
  corpse->set_name(CYN+"airling"+NORM);
  corpse->set_value(6);
  say("The "+CYN+"airling"+NORM+" shudders and collapses.\n");
  tail = clone_object("/obj/treasure.c");
  tail->set_name("tail");
  tail->set_short(CYN+"airling"+NORM+" "+HIW+"tail"+NORM);
  tail->set_long("\
This long, thin, "+CYN+"whispy "+HIW+"tail"+NORM+" is a rare and valuable treasure.\n");
  tail->set_value(100+random(100));
  move_object(tail,corpse);
  return 1;
}
