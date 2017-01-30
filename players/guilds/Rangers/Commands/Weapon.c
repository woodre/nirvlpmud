#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
  if(previous_object()->QuerySkillLevel("weapon") >= 5)
  {
    previous_object()->AHiddenSkill("pweapon","beck",6);
  }
}

void
RangerPower(string str, string Align) { }

int
QMax(){ return 20; }

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write("Weapon is your ability to inflict damage on the enemy.\n\n\
Weapon skills:\n\n\
Power Weapon (" + BOLD + RED + "Pweapon" + OFF + ")    5\n\n");
  return 1;
}


int
OffSkill(int level)
{
  level = (int) previous_object()->QuerySkillLevel("weapon");
  return ((level/2));
}
