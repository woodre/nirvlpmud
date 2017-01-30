#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
/* Add an id of "kill_check_object" if a ranger has any points in the team skill */
/* Allows a small bonus when fighting with other rangers. */
  previous_object()->AID("kill_check_object");
  if(previous_object()->QuerySkillLevel("team") > 0)
  {
    previous_object()->AHiddenSkill("aid","beck");
  }
  if(previous_object()->QuerySkillLevel("team") >= 5)
  {
    previous_object()->AHiddenSkill("wolfpack","beck",8);
  }
  if(previous_object()->QuerySkillLevel("team") >= 7)
  {
    previous_object()->AID("kill_check_object");
    previous_object()->AHiddenSkill("parry","beck",8);
  }
}

void
RangerPower(string str, string Align) { }

int
QMax() { return 20; }

status
QRangerInfo(){ return 1; }

status
RangerInfo(string str)
{
  write("\
  Team skills are very important and powerful for Power Rangers.\n\
Teamwork is a major component, and these skills provide useful\n\
tools for that purpose.\n\nTeam Skills:\n\n"+
BOLD + RED + "Aid " + OFF + "                       1 (requires \
Teleport of 10 for remote use\n"+
BOLD + RED + "Wolfpack " + OFF + "                  5\n"+
BOLD + RED + "Parry " + OFF +  "                     7\n\n\
Others in the future as well\n\n");
  return 1;
}
