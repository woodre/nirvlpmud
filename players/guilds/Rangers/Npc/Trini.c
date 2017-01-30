/******************************************************************************
 *  File:           Trini.c
 *  Author(s):      Beck@Nirvana modified by Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 
 *  Source:         10/13/05
 *  Change History: 2005.10.13
 *****************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "/players/guilds/Rangers/Npc/RangerNpc.c";
inherit "obj/monster";

void
reset(status arg)
{
  object gold, helmet, daggers, watch;
  ::reset(arg);
  if(arg) return;
  set_name("Trini");
  set_alt_name("trini");
  set_long(
  "Trini is one of the Mighty Morphin' Power Rangers. She believes in\n\
\"mind over matter\" tactics and is one of the intellectuals of the\n\
team. She often has to translate Billy's techno-talk for the other \n\
Rangers. She also often assists Billy or Alpha with creation of inven-\n\
tions to help in combat\n\n");
  set_alias("ranger");
  set_race("ranger_trini");
  set_level(20);
  set_hp(900 + random(50));
  set_wc(29 + random(5));
  set_ac(16 + random(4));
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(3);
  set_dead_ob(this_object());
  add_money(random(1500) + 1000);
  if(!present("communicator", this_object()))
  {
    watch = clone_object("/players/guilds/Rangers/RangerCommunicator.c");
    move_object(watch, this_object());
    watch->guild_login();
    watch->init();
    watch->channel_me();
    watch->SRangerAnsi(BOLD+YELLOW);
  }
}

void
custom_clean()
{
  CHANNEL->remove_channel("Power Ranger",this_object());
  return 0;
}

status
RangerNPC() { return 1; }

status
query_interactive(){ return 1; }

int
query_guild_rank() { return 90; }

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
    return "The "+BOLD+YELLOW+"Yellow"+OFF+" Ranger";
  }
  return "A teenage girl named Trini";
}


void
init()
{
  ::init();
  if(COMM)
  {
    COMM->TrainRangerSkill("teleport",1,"beck", "Trini", 25);
  }
  command("rtm", this_object());
  command("rtm", this_object());
}

status
monster_died()
{
  object corpse;
  CHANNEL->remove_channel("Power Ranger",this_object());
  command("release",this_object());
  corpse = present("corpse", environment(this_object()));
  move_object(clone_object("/players/beck/armor/yellow_helmet.c"), corpse);
  move_object(clone_object("/players/beck/weapon/power_daggers.c"), corpse);
  return 0;
}
