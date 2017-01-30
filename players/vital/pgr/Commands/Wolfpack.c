#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

string *Rangers;

int
QMax() { return 20; }

status
QTactic(string person)
{ 
  if(member_array(person, Rangers) != -1)
  {
    return 1; 
  }
  else
    return 0;
}

status
RangerPower(string str, string Type)
{
  if(!Rangers) Rangers = ({});
  if(!(previous_object()->QMorphed()) && !(previous_object()->QNinja()))
  {
    if(member_array(this_player()->query_real_name(), Rangers) != -1) Rangers -= ({ this_player()->query_real_name() });
    tell_object(this_player(),
      "Zordon tells you: \"You can only use Wolfpack when Morphed.\"\n");
    return 1;
  }
    if(member_array(this_player()->query_real_name(), Rangers) < 0)
    {
      write("You turn on Wolfpack Team Tactics.\n");
      previous_object()->SRangerTactic("Wolfpack");
      Rangers += ({this_player()->query_real_name()});
      return 1;
    }
  write("You turn Off Wolfpack Team Tactics.\n");
  previous_object()->SRangerTactic(0);
  Rangers -= ({ this_player()->query_real_name() });
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("\
  Wolfpack Tactics give you the ability to sneak up on an enemy \n\
And hit them better.  Be careful because this will leave you \n\
more vulnerable to hits. You can only use this if you are not the \n\
leader in battle.\n");
   return 1;
}

int
OffSkill(int level)
{
  if(!Rangers) Rangers = ({});
  level = (int) previous_object()->QuerySkillLevel("team");
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    if(!previous_object()->QMorphed() ||
      (string) previous_object()->QRangerTactic() != "Wolfpack")
    {
      tell_object(environment(previous_object()), 
        "You turn off Wolfpack Team Tactics.\n");
      Rangers -= ({ environment(previous_object())->query_real_name() });
      return 0;
    }
    tell_object(environment(previous_object()), "[ " + BOLD + RED +
                "TACTIC" + OFF + " ] " + "You use Wolfpack Team Tactics\n");
    return ((level*5)/3);
  }
  else
    return 1;
}

status
DefSkill(int level)
{
  if(!Rangers) Rangers = ({});
  level = (int) previous_object()->QuerySkillLevel("team");
  if(member_array(environment(previous_object())->query_real_name(),
    Rangers) >= 0)
  {
    tell_object(environment(previous_object()),
      "You turn off Wolfpack Team Tactics.\n");
    if((string) previous_object()->QRangerTactic() == "Wolfpack")
      previous_object()->SRangerTactic(0);
    Rangers -= ({ environment(previous_object())->query_real_name() });
    return -((level*5)/3);
  }   
  else
    return 1;
}
