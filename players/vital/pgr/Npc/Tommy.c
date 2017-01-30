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

inherit "/players/guilds/Rangers/Npc/RangerNpc.c";
inherit "obj/monster";

void
reset(status arg)
{
  object watch;
  set_move_at_reset();
  ::reset(arg);
  if(arg) return;
  set_name("Tommy");
  set_alt_name("tommy");
  set_long(format("Tommy is one of the Mighty Morphin' Power Rangers.\
Tommy is the strongest of the power rangers. He is also the first to step into battle to save his friends. With his new identity and powers, as the White Ranger \(formerly the Green Ranger\) his only mission is to destroy Lord Zed and his evil minions."));
  set_alias("ranger");
  set_race("ranger_tommy");
  set_level(20);
  set_wc(30);
  set_ac(22);
  set_hp(1000);
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(3);
  set_dead_ob(this_object());
  add_money(random(1000) + 3000);
  if(!present("RangerCommunicator", this_object()))
  {
    watch = clone_object("/players/guilds/Rangers/RangerCommunicator.c");
    move_object(watch, this_object());
    watch->guild_login();
    watch->init();
    watch->SRangerAnsi(HIW);
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

status
query_interactive() { return 1; }

int
query_guild_rank() { return 100; }

void
init()
{
  ::init();
  if(COMM){
    COMM->TrainRangerSkill("morph",1,"beck","Tommy",50);
  }
}

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
    return "The "+BOLD+WHITE+"White"+OFF+" Ranger";
  }
  return "A teenage boy named Tommy";
}

status
monster_died()
{
  object corpse;
  write_file("/players/guilds/Rangers/Log/NPC_KILLED", (this_object()->query_attack())->query_name() +
    " killed Tommy " + ctime(time()) + "\n");
  CHANNEL->remove_channel("Power Ranger",this_object());
  command("release",this_object());
  corpse = present("corpse", environment(this_object()));
  move_object(clone_object("/players/beck/armor/white_helmet.c"), corpse);
  return 0;
}
