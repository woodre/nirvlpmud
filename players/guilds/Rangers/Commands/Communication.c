#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

void
RangerInit()
{
  if(previous_object()->QuerySkillLevel("communication") > 0)
  {
    previous_object()->AHiddenSkill("rt","beck");
    previous_object()->AHiddenSkill("rte","beck");
    previous_object()->AHiddenSkill("rth","beck");
  }
  if(previous_object()->QuerySkillLevel("communication") > 1)
  {
    previous_object()->AHiddenSkill("rwho","beck");
  }
}

void
RangerPower(string str, string Align) { }

int
QMax() { return 15; }

status
QRangerInfo() { return 1; }

status
RangerInfo(string str)
{
  write("Comm is a combination of all your important communications skills.\n\
They will be a combo of audio and video skills.\n\
Some skills are very advanced.  While not necessary, they will make\n\
your life a lot easier.\n\n\
Comm Skills are:\n\n\
Rt                         1\n\
Rte                        1\n\
Rwho                       2\n\
Rwho (with location)       3  (required for P2P teleport)\n\
Communications Tower      10 \n\
Invisible [Ninja Morph]   11\n\
Remote Camera             12\n\
Remote Locator            13\n\
Spy Satellite             15\n\n");
  return 1;

}
