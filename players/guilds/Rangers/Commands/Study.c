#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"


int
RangerPower(string str)
{
  object enemy, me;
  if(!str) return 0;
  if(!present(str, environment(this_player())))
  {
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
      " is not here.\"\n");
    return 1;
  }
  enemy = present(str, environment(this_player()));
  if(!living(enemy))
  {
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
      " is not a living being.\"\n");
    return 1;
  }
  if( present("RangerCommunicator", enemy) &&
      (int) previous_object()->QuerySkillLevel("leadership") > 19)
  {
    write("FIRE\n");
    present("RangerCommunicator", enemy)->ShowSkills();
  }
  write(enemy->short() + "\n");
  if(enemy->query_alignment() > 0)
  {
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
      " appears to be good.\"\n");
    return 1;
  }
  if(enemy->query_alignment() < 0)
  { 
    tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
      " appears to be bad.\"\n");
    return 1;
  }
  tell_object(this_player(), "Zordon tells you: \"" + capitalize(str) +
    " seems to be indifferent to good or evil.\"\n");
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write(format("Study will inform you the alignment status of another player \
or monster. Team Leaders are able to view the skills of other Power \
Rangers to help advise them.\n"));
  return 1;
}
