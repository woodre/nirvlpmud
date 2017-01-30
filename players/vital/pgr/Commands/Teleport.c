#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

/*
 *  Allows the ranger to teleport to certain locations.
 */

void
RangerInit()
{
  if(previous_object()->QuerySkillLevel("teleport") >= 7)
  {
    previous_object()->AHiddenSkill("pack","beck");
    previous_object()->AHiddenSkill("unpack","beck");
  }
}

int
QMax(){ return 20; }

status
QRangerInfo(){ return 1; }

status
RangerInfo()
{

  write("\
  Teleporting is a major Power Ranger Ability. Teleporting allows a\n\
Ranger to instantly transfer to pre-designated locations, and to\n\
other Power Rangers. The cost to Teleport is:  110 - ( 5 * (Teleport\n\
Skill Level) ). Teleporting when not morphed, or to other players,\n\
is double that amount. The minimum cost can never be less than 20\n\
(40 when unmorphed/another player).\n\n\
Abilities:\n\n"+
    BOLD+RED+"Pack"+OFF+"                                        7\n"+
    BOLD+RED+"Unpack"+OFF+"                                      7\n\n\
Locations:\n\n\
Church                                       1\n\
Command Center                               2\n\
Command Center Outside                       2\n\
Park                                         5\n\
Remote Locator (must have 13 Communication) 10\n\
Another Power Ranger 'teleport <name>'      10\n\
Megaship  (must be Space Ranger at least)   15\n\
!!! All  P2P teleport requires Comm skill of 3 or higher !!!\n\
Other destination will be available in the future Please mail\n\
Beck with (serious) uggestions.");
  return 1;
}

status
RangerPower(string str, string type)
{
  int cost;
  string destination;
  object locator;
  cost = 110 - ( (int) previous_object()->QuerySkillLevel("teleport") * 5);
  if(cost < 20) cost = 20;
  if(!str){write("Teleport where?\n"); return 1;}
  if(!previous_object()->QMorphed() || !previous_object()->QMorphed())
  {
    if(MASTER->QPowerPoints(type) < cost*2)
    {
      tell_object(this_player(),
        "Zordon tells you: \"There is not enough power to teleport you.\"\n");
      return 1;
    }
  }
  if(MASTER->QPowerPoints(type) < cost)
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough power to teleport you.\"\n");
    return 1;
  }
                              /* added 6.11.01 by verte */
  if(!environment(this_player())) return 0;
  if( (string) environment(this_player())->realm() == "NT")
  {
    tell_object(this_player(),
      "Zordon tells you: \"I cannot seem to pinpoint your location.\"\n");
    return 1;
  }
  destination = "none";
  if(str=="church" && previous_object()->QuerySkillLevel("teleport") > 0){ destination = "X#/room/church.c"; }
  if(str=="park" && previous_object()->QuerySkillLevel("teleport") > 4 ){ destination = "teleport#/players/beck/room/park5.c"; }
  if(str=="megaship" && this_player()->query_guild_rank() > 69 && previous_object()->QuerySkillLevel("teleport") > 14 )
  {
    destination = "teleport#/players/guilds/Rangers/RangerSpaceship.c";
  }
  if(str=="command center" && previous_object()->QuerySkillLevel("teleport") > 1 ){ destination = "X#/players/guilds/Rangers/CommandCenter/CommandCenter.c"; }
  if(str=="command center outside" && previous_object()->QuerySkillLevel("teleport") > 1 ){ destination = "X#/players/beck/room/mountain2.c"; }

  if("/players/guilds/Rangers/CommandCenter/CommandCenter.c"->QCurrEnhancement(str))
  {
    locator = (object)
"/players/guilds/Rangers/CommandCenter/CommandCenter.c"->QCurrEnhancement(str);
    if(!locator->valid_teleport())
      destination = "none";
    else if( (string) environment(locator)->realm() == "NT")
    {
      tell_object(this_player(),
        "Zordon tells you: \"I can't pinpoint " + str +
        "'s location for you.\n");
      return 1;
    }
    else if(living(environment(locator)))
    {
      tell_object(this_player(),
        "Zordon tells you: \"You cannot teleport to a living being.\n");
      return 1;
    }
    else
    {
      tell_room(environment(this_player()),this_player()->query_name()+
        " becomes a mass of "+previous_object()->QRangerAnsi()+previous_object()->COLOR+
        " light"+OFF+".\n"+"The "+previous_object()->QRangerAnsi()+"light"+OFF+" then rockets into the sky and disappears"+
        " out of sight.\n"+
        "");
      move_object(this_player(), environment(locator));
      tell_room(environment(this_player()),"A brilliant display of "+
        previous_object()->QRangerAnsi()+previous_object()->COLOR+" light"+OFF+" beams into the room.\n"+
        "");
      command("look", this_player());
      MASTER->APowerPoints(-cost,type);
      if(!previous_object()->QMorphed())
      {
        MASTER->APowerPoints(-cost,type);
      }
      return 1;
    }
  }

  if(type == "Dark Ranger")
  {
    if(str == "castle"){ destination = "teleport#/players/beck/DarkRangers/Room/ZedChamber.c"; }
  }
  if(destination != "none")
  {
    tell_room(environment(this_player()),this_player()->query_name()+
      " becomes a mass of "+previous_object()->QRangerAnsi()+previous_object()->COLOR+
      " light"+OFF+".\n"+"The "+previous_object()->QRangerAnsi()+"light"+OFF+" then rockets into the sky and disappears"+
      " out of sight.\n"+
      "");
    call_other(this_player(),"move_player",destination);
    tell_room(environment(this_player()),"A brilliant display of "+
      previous_object()->QRangerAnsi()+previous_object()->COLOR+" light"+OFF+" beams into the room.\n"+
      "");
    MASTER->APowerPoints(-cost,type);
    if(!previous_object()->QMorphed())
    {
      MASTER->APowerPoints(-cost,type);
    }
    return 1;
  }
  if(!find_living(str))
  {
    tell_object(this_player(),
      "Zordon tells you: \"You can't teleport there.\"\n");
    return 0;
  }
  if(!present("RangerCommunicator", find_living(str)) || previous_object()->QuerySkillLevel("teleport") < 10 && previous_object()->QuerySkillLevel("communication") > 2)
  {
    write("You can't teleport to that person.\n");
    return 0;
  }
  if( (string) environment(find_living(str))->realm() == "NT")
  {
    tell_object(this_player(),
      "Zordon tells you: \"I can't pinpoint that ranger's location \
for you.\"\n");
    return 0;
  }
  if(MASTER->QPowerPoints(type) < cost*2)
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough Power to teleport you to \
that person.\"\n");
    return 0;
  }
  tell_room(environment(this_player()),this_player()->query_name()+
    " becomes a mass of "+previous_object()->QRangerAnsi()+previous_object()->COLOR+
    " light"+OFF+".\n"+"The "+previous_object()->QRangerAnsi()+"light"+OFF+
    " then rockets into the sky and disappears"+
    " out of sight.\n");
  move_object(this_player(), environment(find_living(str)));
  if(!previous_object()->QNinja())
  {
    tell_room(environment(this_player()),"A brilliant display of "+
      previous_object()->QRangerAnsi()+previous_object()->COLOR+" light"+OFF+" beams into the room.\n");
  }
  command("look", this_player());
  MASTER->APowerPoints(-(cost*2),type);

  return 1;
}
