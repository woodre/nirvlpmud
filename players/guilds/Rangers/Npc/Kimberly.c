/******************************************************************************
 *  File:           Kimberly.c
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
  object watch;
  ::reset(arg);
  if(arg) return;
  set_name("Kimberly");
  set_alt_name("kimberly");
  set_long("Kimberly is one of the Mighty Morphin' Power Rangers.\n\n");
  set_alias("ranger");
  set_race("ranger_kimberly");
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
    watch->SRangerAnsi(BOLD+MAGENTA);
  }
}

status
custom_clean()
{
  CHANNEL->remove_channel("Power Ranger",this_object());
  return 0;
}

status
RangerNPC() { return 1; }

int
query_guild_rank() { return 90; }

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
    return "The "+BOLD+MAGENTA+"Pink"+OFF+" Ranger";
  }
  return "A teenage girl named Kimberly";
}

status
monster_died()
{
  object corpse;
  CHANNEL->remove_channel("Power Ranger",this_object());
  command("release",this_object());
  corpse = present("corpse", environment(this_object()));
  move_object(clone_object("/players/beck/armor/pink_helmet.c"), corpse);
  move_object(clone_object("/players/beck/weapon/power_bow.c"), corpse);
  return 0;
}

void
init()
{
  ::init();
  if(present("RangerCommunicator",this_player()))
  {
    present("RangerCommunicator", this_player())->TrainRangerSkill("weapon", 3,
      "beck", "Kimberly", 25);
  }
  command("rtm", this_object());
  command("rtm", this_object());
}
