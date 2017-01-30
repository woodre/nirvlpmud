/******************************************************************************
 *  File:           Zordon.c
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
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_short("Zordon the living master computer");
  set_name("zordon");
  set_alias("zordon");
  set_long(format("Zordon is a giant computer that runs the control center. \
He can keep track of the activities of Lord Zed and his evil monsters.\
On the screen all you see is a giant face."));
  set_level(20);
  set_hp(5000);
  set_wc(40);
  set_ac(22);
  set_res(20);
  set_al(2000);
  set_aggressive(0);
  set_chance(40);
  set_spell_dam(30);
  set_dead_ob(this_object());
  set_spell_mess2("Zordon short circuits your brain.\n");
  add_money(random(1000) + 5000);
}

void
init()
{
  string type;
  ::init();
  if(present("RangerCommunicator",this_player()))
  {
    if(this_player()->query_guild_rank() < 70){type = "space";}
    if(this_player()->query_guild_rank() < 60){ type = "rescue";}
    if(this_player()->query_guild_rank() < 50){ type = "turbo";}
    if(this_player()->query_guild_rank() < 40){ type = "zeo";}
    if(this_player()->query_guild_rank() < 30){ type = "ninja";}
    if(this_player()->query_guild_rank() < 20){ type = "thunder";}
    if(this_player()->query_guild_rank() <10){ type = "dino";}
    present("RangerCommunicator",this_player())->TrainRanger("Zordon",type);
  }
}

status
monster_died()
{
  write_file("/players/guilds/Rangers/Log/NPC_KILLED", (this_object()->query_attack())->query_name() +
    " killed Zordon " + ctime(time()) + "\n");
  return 0;
}
