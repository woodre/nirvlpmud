/******************************************************************************
 *  File:           RangerNpc.c
 *  Author(s):      Beck@Nirvana modified by Vital@Nirvana
 *  Copyright:      Copyright (c) 2002 
 *  Source:         10/13/05
 *  Change History: 2005.10.13
 *****************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

inherit "obj/monster";

string talk_name;
int talk_num;
string aid_name;
static object cc_attack;

string
query_guild_name(){ return "rangers"; }

void
catch_tell(string str)
{
  string temp;
  string what;
  string who;
  if(sscanf(str,"%sZordon says: %s is under attack%s", temp, what, who) == 3)
  {
    if(what == "The Command Center")
    {
      aid_name = "The Command Center";
      call_out("delay_aid", random(20));
    }
    else
    {
      aid_name = lower_case(what);
      call_out("delay_aid", random(20));
    }
  }
  else if(sscanf(str,"%sPower Ranger%shello "+this_object()->query_name(), temp, what) == 2
          || sscanf(str,"%sPower Ranger%shello "+this_object()->query_name()+"%s", temp,
          what, who) == 3)
  {
    talk_name = (string) this_player()->query_name();
    talk_num = 1;
    call_out("delay_talk", 3);
  }
  else if(sscanf(str,"%sPower Ranger%sbye "+this_object()->query_name(), temp, what) == 2
          || sscanf(str,"%sPower Ranger%sbye "+this_object()->query_name()+"%s", temp,
          what, who) == 3)
  {
    talk_name = (string) this_player()->query_name();
    talk_num = 2;
    call_out("delay_talk", 3);
  }
  else
  {
    return;
  }
}

void
delay_aid()
{
  if(aid_name == "The Command Center")
  {
    command("aid command center",this_object());
  }
  else
  {
    if(find_living("ranger_"+aid_name))
    {
      if(find_living("ranger_"+aid_name) != this_object())
      {
        command("rt I am on my way " + capitalize(aid_name) +
                ". Hang in there.",this_object());
        if(!present("RangerCommunicator",this_object())->QMorphed())
        {
          MASTER->APowerPoints(3500,"Power Ranger");
          command("morph",this_object());
        }
        command("aid ranger_"+aid_name,this_object());
      }
    }
  }
}

void
delay_talk()
{
  if(talk_num == 1)
    command("rt Hello "+talk_name,this_object());
  else if(talk_num == 2)
    command("rt See you later "+talk_name,this_object());
  else
    return;
}

void
attacked_by(object ob)
{
  if(!query_attack() || (object) this_object()->query_attack() != cc_attack)
  {
    CHANNEL->channel_message("Power Ranger", WHITE + "[" + RED +
      "Command Center" + OFF + WHITE + "]" + OFF + " Zordon says: " + query_name() +
      " is under attack from "+ob->query_name()+".\n");
    cc_attack = ob; 
  }
  ::attacked_by(ob);
}

void
heart_beat()
{
  object attacker;
  ::heart_beat();
  if(!this_object()->query_attack())
  {
    if(random(100) < 2) { random_move(); }
  }
  if(this_object()->query_attack())
  {
    if((this_object()->query_attack())->query_level() < 21)
    {
      if(present("honor_ranger_communicator", (object) 
         this_object()->query_attack()))
      {
        attacker = (object) this_object()->query_attack();
        MASTER->RemoveRanger("Power Ranger",attacker);
        destruct(present("honor_ranger_communicator", attacker));
        tell_object(attacker, "Tommy tells you: How dare you!\n");
        command("rt " + attacker->query_name() + 
                " is no longer an Ally of the Power Rangers.\n",this_object());
        attacker->hit_player(100);
      }
    }
  }
  if(this_object()->query_hp() < 850)
  {
    if(!present("RangerCommunicator",this_object())->QMorphed())
    {
      MASTER->APowerPoints(3500,"Power Ranger");
      command("morph", this_object());
    }
  }
  if(this_object()->query_hp() < 750)
  {
    MASTER->APowerPoints(1400,"Power Ranger");
    command("zord", this_object());
  } 
}

