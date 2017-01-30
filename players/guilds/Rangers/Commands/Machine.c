#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
  if(previous_object()->QuerySkillLevel("machine") >= 5)
    previous_object()->AHiddenSkill("zord","beck");
  if(previous_object()->QuerySkillLevel("machine") >= 20)
    previous_object()->AHiddenSkill("megazord","beck");
}

status
RangerPower(string str, string Align) { return 1; }

int
QMax() { return 20; }

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write("\
  Machines are powerful vehicles/robots that fight with the Power Rangers.\n\
Some fight alongside the Power Rangers, while others are used with the \n\
Power Ranger inside.\n\n\
Available machines:\n\n"+
BOLD+RED+"Zord"+OFF+"                  5\n\
Thunder Megazord      20 (The biggest baddest fighter on Nirvana)\n\n\
Other machines may be available in the future.\n\n");
  return 1;
}

