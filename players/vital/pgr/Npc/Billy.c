/******************************************************************************
 *  File:           Billy.c
 *  Author(s):      Beck@Nirvana modified by Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 
 *  Source:         10/13/05
 *  Change History: 2005.10.13
 *****************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "obj/monster";
inherit "/players/guilds/Rangers/Npc/RangerNpc.c";

void
reset(status arg)
{
  object watch;
  ::reset(arg);
  if(arg) return;
  set_name("Billy");
  set_alt_name("billy");
  set_long(format("Billy is one of the Mighty Morphin' Power Rangers. Billy \
is the genius of the power rangers. He is also the most creative, always \
building devices to in defeating Lord Zed and other evil creatures. Billy \
not only has brains, but also is a very strong opponent if you choose to \
make him such.\n"));
  set_alias("ranger");
  set_race("ranger_billy");
  set_level(20);
  set_hp(900 + random(50));
  set_wc(29 + random(5));
  set_ac(16 + random(4));
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(3);
  set_dead_ob(this_object());
  add_money(random(2000) + 1000);
  if(!present("communicator", this_object()))
  {
    watch = clone_object("/players/guilds/Rangers/RangerCommunicator.c");
    watch->guild_login();
    move_object(watch, this_object());
    watch->init();
    watch->SRangerAnsi(BLUE);
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

void
init()
{
  ::init();
  if(present("RangerCommunicator",this_player()))
  {
    present("RangerCommunicator",
      this_player())->TrainRangerSkill("communication",2,"beck","Billy", 15);
  }
}

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
    return "The "+BOLD+BLUE+"Blue"+OFF+" Ranger";
  }
  return "A teenage boy named Billy";
}

status
monster_died()
{
  object corpse;
  CHANNEL->remove_channel("Power Ranger",this_object());
  command("release",this_object());
  corpse = present("corpse", environment(this_object()));
  move_object(clone_object("/players/beck/armor/blue_helmet.c"), corpse);
  return 0;
}
