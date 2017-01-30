#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
  if(previous_object()->QuerySkillLevel("leadership") >= 1)
    previous_object()->AHiddenSkill("study","beck");
  if(previous_object()->QuerySkillLevel("leadership") >= 2)
    previous_object()->AHiddenSkill("lead","beck");   
  if(previous_object()->QuerySkillLevel("leadership") >= 5)
    previous_object()->AHiddenSkill("retrain","beck");   
  if(previous_object()->QuerySkillLevel("leadership") >= 10)
    previous_object()->AHiddenSkill("recruit","beck");
}

status
RangerPower(string str, string Align) { }

int
QMax() { return 20; }

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write("\
  Leadership is the essence of a Power Ranger. Power Rangers should set an example to all other players. Increasing leadership will help you and your whole team.\n\n\
Leadership Skills:\n\n"+
BOLD+RED+"  Study"+OFF+"                      1\n"+
BOLD+RED+"  Lead "+OFF+"                      2\n"+
BOLD+RED+"  Retrain "+OFF+"                   5\n"+
BOLD+RED+"  Recruit"+OFF+"/Remove Allies      10\n"+
BOLD+RED+"  Recruit"+OFF+" Power Ranger       15\n\
  Team Leader Title          20\n\n\
Others in the future as well\n\n");
  return 1;
}

