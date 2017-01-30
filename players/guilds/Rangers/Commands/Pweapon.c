#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

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
  if(!Rangers) Rangers = ({});
  if(previous_object()->QNinja())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You cannot use your Power Weapon as a Ninja.\"\n");
    return 1;
  }
  if(!(previous_object()->QMorphed()))
  {
   if(member_array(this_player()->query_real_name(), Rangers) != -1) Rangers -= ({ this_player()->query_real_name() });
   tell_object(this_player(),
      "Zordon tells you: \"You can only use your Power Weapon when \
Morphed.\"\n");
   return 1;
  }
  if(member_array(this_player()->query_real_name(), Rangers) < 0)
  {
    tell_room(environment(this_player()), this_player()->query_name() +
      " yells: Power " + previous_object()->QRangerWeapon() + "\n");
    Rangers += ({this_player()->query_real_name()});
    return 1;
  }
  write("You Power down your Power Weapon.\n");
  Rangers -= ({ this_player()->query_real_name() });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("\
  Your Power Weapon gives you better fighting ability in battle.\n\
Power Weapon does come at a price however.\n\
The power cost is equivelent to your skill level in Weapon \n\
(5-20 Power Points) each time you hit the enemy. If power levels\n\
are too low, your Power Weapon will turn off.\n\n");
  return 1;
}

int
OffSkill(int level)
{
  if(!Rangers) Rangers = ({});
  level = (int) previous_object()->QuerySkillLevel("weapon");
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    if(!previous_object()->QMorphed())
    {
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
    if(MASTER->QPowerPoints(previous_object()->QRangerAlign()) > level)
    {
      MASTER->APowerPoints(-level, previous_object()->QRangerAlign());
      tell_object(environment(previous_object()), "[ " + BOLD + RED +
        "POWER WEAPON" + OFF + " ] " +
        "You strike the enemy with your Power Weapon\n");
      return (level/2);
    }
    else
    {
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
  }
  else
    return 0;
}
