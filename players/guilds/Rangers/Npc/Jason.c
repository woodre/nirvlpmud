/******************************************************************************
 *  File:           Jason.c
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
  set_name("Jason");
  set_alt_name("jason");
  set_long("Jason is one of the Mighty Morphin' Power Rangers.\n\
Jason is the leader of the Power Rangers.\n\
He is dressed from head to toe in a gold nylon suit.\n\
His face is obscured by a gold helmet.\n\
Jason is a fearless leader prepared to take on anyone or anything.\n\n");
  set_alias("ranger");
  set_race("ranger_jason");
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
    watch->SRangerAnsi(YELLOW);
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
query_guild_rank() { return 100; }

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
    return "Jason the "+YELLOW+"Gold"+OFF+" Ranger";
  }
  return "A teenage boy named Jason";
}

void
init()
{
  ::init();
  if(COMM)
  {
    if(random(100) < 50)
      COMM->TrainRangerSkill("leadership",2,"beck", "Jason", 50);
    else
      COMM->TrainRangerSkill("team",2,"beck", "Jason", 50);
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
  move_object(clone_object("/players/beck/armor/red_helmet.c"), corpse);
  move_object(clone_object("/players/beck/weapon/power_sword.c"), corpse);
  return 0;
}

