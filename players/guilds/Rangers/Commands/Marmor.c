#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;
int MetallicArmorType;

int
QMax() { return 20; }

status
QSkill(string person)
{ 
  if(!Rangers) Rangers = ({});
  if(member_array(person, Rangers) != -1)
    return 1; 
  else
    return 0;
}

status
RangerPower()
{
  object prev_obj;

  prev_obj = previous_object();

  if(!Rangers) Rangers = ({});
  if(!(prev_obj->QMorphed()))
  {
    if(prev_obj->QNinja())
    {
      if(member_array(this_player()->query_real_name(), Rangers) != -1)
        Rangers -= ({ this_player()->query_real_name() });
      write("Zordon tells you: You cannot use your Metallic Armor as \
a Ninja.\"\n");
      return 0;
    }
    if(member_array( this_player()->query_real_name(), Rangers) != -1)
       Rangers -= ({ this_player()->query_real_name() });
    tell_object(this_player(),
      "Zordon tells you: \"You can only use your Metallic Armor \
when Morphed.\"\n");
    return 0;
  }
  if(member_array(this_player()->query_real_name(), Rangers) < 0)
  {
    string msg;
    switch(prev_obj->QuerySkillLevel("armor"))
    {
      case   5..8:
        msg = "Metallic Armor";
        MetallicArmorType = 5;
        break;
      case  9..12:
        msg = "Mega Battle Armor";
        MetallicArmorType = 4;
        break;
      case 13..16:
        msg = "Battle Warrior Armor";
        MetallicArmorType = 3;
        break;
      case 17..19:
        msg = prev_obj->ANIMAL + " Animarium Armor";
        MetallicArmorType = 2;
        break;
      case     20:
        msg = prev_obj->R_ANSI + prev_obj->COLOR + " Battelizer Armor" + OFF;
        MetallicArmorType = 1;
    }
    tell_room(environment(this_player()), this_player()->query_name() +
              " yells: " + msg + ", Power Up!\n");
    Rangers += ({ this_player()->query_real_name() });
    return 1;
  }
  write("You Power down your Metallic Armor.\n");
  Rangers -= ({ this_player()->query_real_name() });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("Your Mettalic Armor gives you better protection in battle.\n\
Metallic Armor does come at a price however.\n\
The power cost is equivelent to your skill level in Armor\n\
(5-20 Power Points) each time you are hit by the enemy.\n\
If power levels are too low, your Metallic Armor will turn off.\n\n\
Current Metallic Armor Types are:\n\
  Metallic Armor            5 Armor Skill\n\
  Mega Battle Armor         9 Armor Skill\n\
  Battle Warrior Armor     13 Armor Skill\n\
  Animarium Armor          17 Armor Skill\n\
  Battelizer Armor         20 Armor Skill\n\n");
  return 1;
}

int
DefSkill(int level)
{
  string msg;
  object prev_obj;

  prev_obj = previous_object();

  if(!Rangers) Rangers = ({});
  level = (int) prev_obj->QuerySkillLevel("armor");
  if( member_array( environment(prev_obj)->query_real_name(),
      Rangers) >= 0)
  {
    if(!prev_obj->QMorphed())
    {
      Rangers -= ({ environment(prev_obj)->query_real_name() });
      return 0;
    }
    if(MASTER->QPowerPoints(prev_obj->QRangerAlign()) > level)
    {
      MASTER->APowerPoints(-level, prev_obj->QRangerAlign());
      switch(MetallicArmorType)
      {
        case 5: msg = "[ " + BOLD + BLUE + "METALLIC ARMOR" + OFF + " ] "+
                      "Your Armor flashes as it absorbs some damage.\n";
                break;
        case 4: msg = "[ " + BOLD + MAGENTA + "MEGA BATTLE ARMOR" + OFF+" ] "+
                      "Your Armor deflects some of the damage away.\n";
                break;
        case 3: msg = "[ " + BOLD + GREEN + "BATTLE WARRIOR ARMOR" + OFF+" ] " +
                      "Your Armor diverts damage away from you.\n";
                break;
        case 2: msg = "[ " + BOLD + REV_GREEN + "ANIMARIUM ARMOR" + OFF + " ] "+
                      "Your Armor is strengthed from Animarian Spirits.\n";
                break;
        case 1: msg = "[ " + BOLD + REV_BLUE + "BATTELIZER ARMOR" + OFF + " ] "+
                      "Some damage is powerfully averted by your Armor.\n";
      }
      tell_object(environment(prev_obj), msg);
      return (100*(level/2))+(level/MetallicArmorType);
    }
    else
    {
      Rangers -= ({ environment(prev_obj)->query_real_name() });
      return 0;
    }
  }
  else
    return 0;
}
