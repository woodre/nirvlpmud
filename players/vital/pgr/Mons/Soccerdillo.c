/******************************************************************************
 *  File:           Soccerdillo.c
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
  set_name("Soccerdillo");
  set_alias("soccerdillo");
  set_race("RangerMonster");
  set_short("The Soccerdillo");
  set_long(format("The Soccerdillo is one of Rita's evil creatures, created to be half soccerball half armadillo. The soccerdillo can roll up into a ball and is heavily armored. Beware of playing with this guy."));
  set_level(20);
  set_hp(500);
  set_wc(25);
  set_ac(25);
  set_al(-500);
  set_aggressive(0);
  set_chance(25);
  set_spell_dam(18);
  set_spell_mess2("The Soccerdillo rolls right over you!\n");
  set_chat_chance(3);
  load_chat("The Soccerdillo says: Hey Power Rangers...Wanna PLAY?\n");
  add_money(random(1000) + 4000);
  if(!present("DarkRangerCommunicator", this_object()))
  {
    watch =
    clone_object("/players/guilds/Rangers/DarkRangers/DarkRangerCommunicator.c");
    watch->init();
    watch->guild_login();
    move_object(watch, this_object());
  }   
  set_dead_ob(this_object());
}

