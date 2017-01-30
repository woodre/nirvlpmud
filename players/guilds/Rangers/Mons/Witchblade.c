/******************************************************************************
 *  File:           Witchblade.c
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
  set_name("Witchblade");
  set_alias("witchblade");
  set_race("RangerMonster");
  set_short("Witchblade");
  set_long(format("Witchblade is a cross between a witch and sharp cutting \
utensils. This monster is sure to be deadly."));
  set_level(20);
  set_hp(500);
  set_wc(35+random(5));
  set_ac(15);
  set_chance(25);
  set_spell_dam(20);
  set_al(-800);
  set_aggressive(0);
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
