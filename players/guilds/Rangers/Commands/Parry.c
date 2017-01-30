#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

int
QMax() { return 20; }

status
RangerPower()
{
  if(!Rangers) Rangers = ({});
  if(!(previous_object()->QMorphed()) && !(previous_object()->QNinja()))
  {
    if(member_array(this_player()->query_real_name(), Rangers) != -1)
      Rangers -= ({ this_player()->query_real_name() });
    tell_object(this_player(),
      "Zordon tells you: \"You can only use Parry when Morphed.\"\n");
    return 1;
  }
  if(member_array(this_player()->query_real_name(), Rangers) < 0)
  {
    write("You turn on Parry Team Tactics.\n");
    previous_object()->SRangerTactic("Parry");
    Rangers += ({this_player()->query_real_name()});
    return 1;
  }
  write("You turn Off Parry Team Tactics.\n");
  previous_object()->SRangerTactic(0);
  Rangers -= ({ this_player()->query_real_name() });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("  Parry Team Tactics allow you better defense when facing tough \
enemies.\n\It is best used when in a party of strong players, as you will \
not be\nAble to hit your enemy as well.\n");
  return 1;
}

int
OffSkill(int level)
{
  if(!Rangers) Rangers = ({});
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    if(!previous_object()->QMorphed() ||
      (string) previous_object()->QRangerTactic() != "Parry")
    {
      tell_object(environment(previous_object()),
        "You turn off Parry Tactics.\n");
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
    level = (int) previous_object()->QuerySkillLevel("team");
    return -(2*(level));
  }
  else
    return 1;
}

int
DefSkill(int level)
{
  if(!Rangers) Rangers = ({});
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    level = (int) previous_object()->QuerySkillLevel("team");
    tell_object(environment(previous_object()), "[ " + BOLD + RED + 
      "TACTIC" + OFF + " ] " + "You use Parry Team Tactics\n");
    return 100*(level);
  }   
  else
    return 1;
}