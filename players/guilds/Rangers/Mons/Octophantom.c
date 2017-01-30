/******************************************************************************
 *  File:           Octophantom.c
 *  Author(s):      Beck@Nirvana modified by Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 
 *  Source:         10/13/05
 *  Change History: 2005.10.13
 *****************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "obj/monster";

void
reset(status arg)
{
  object watch;
  ::reset(arg);
  if(arg) return;
  set_name("Octophantom");
  set_alias("octophantom");
  set_race("RangerMonster");
  set_short("The Octophantom");
  set_long(format("The Octophantom is one of Lord Zed's evil creatures. It's \
a cross between an octopus and an elephant."));
  set_level(20);
  set_hp(500);
  set_wc(30);
  set_ac(17);
  set_chat_chance(2);
  set_chance(15);
  set_spell_dam(10);
  set_spell_mess2("Octophantom grabs you and throws you to the ground.\n");
  set_al(-800);
  set_aggressive(0);
  load_chat("The Octophantom cries out: I am so good looking!\n");
  load_chat("The Octophantom says: I can't believe how incredibly \
handsome I am!\n");
  add_money(random(4000) + 500);
  set_dead_ob(this_object());
  if(!present("DarkRangerCommunicator", this_object()))
  {
    watch =
    clone_object("/players/guilds/Rangers/DarkRangers/DarkRangerCommunicator.c");
    watch->init();
    watch->guild_login();
    move_object(watch, this_object());
  }   
}
