/******************************************************************************
 *  File:           Zack.c
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
  set_name("Zack");
  set_alt_name("zack");
  set_alias("ranger");
  set_race("ranger_zack");
  set_long(
    "Zack is one of the Mighty Morphin' Power Rangers. Quick witted and\n\
clever, Zack relies on a combination of skill, strength and agility to\n\
win his battles. He is an energetic, charismatic and perpetually fun-loving\n\
young man. He enjoys athletics such as basketball, football and scuba\n\
diving. He also enjoys dancing, parties and girls. When ever he doesn't\n\
have an arm around Trini or Kimberly he was pursuing his attractive, but\n\
hard-to-get classmate, Angela. \n");
  set_level(20);
  set_wc(29 + random(5));
  set_ac(16 + random(4));
  set_hp(900 + random(50));
  set_dead_ob(this_object());
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(3);
  add_money(random(1000) + 1000);
  if(!present("communicator", this_object()))
  {
    watch=clone_object("/players/guilds/Rangers/RangerCommunicator.c");
    move_object(watch, this_object());
    watch->guild_login();
    watch->init();
    watch->channel_me();
    watch->SRangerAnsi(REVERSE+BOLD+BLACK);
  }
}

status
custom_clean()
{
  CHANNEL->remove_channel("Power Ranger",this_object());
  return 0;
}

status
RangerNPC(){ return 1; }

int
query_guild_rank(){ return 100; }

string
short()
{
  if(present("RangerCommunicator", this_object())->QMorphed())
  {
     return "The Black Ranger";
  }
  return "A teenage boy named Zack";
}

status
monster_died()
{
  object corpse;
  CHANNEL->remove_channel("Power Ranger",this_object());
  command("release",this_object());
  corpse = present("corpse", environment(this_object()));
  move_object(clone_object("/players/beck/armor/black_helmet.c"), corpse);
  move_object(clone_object("/players/beck/weapon/power_axe.c"), corpse);
  return 0;
}

void
init()
{
  ::init();
  if(present("RangerCommunicator",this_player()))
  {
     present("RangerCommunicator", this_player())->TrainRangerSkill("machine",
            2, "beck", "Zack", 15);
  }
  command("rtm", this_object());
  command("rtm", this_object());
}
