#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"


int
RangerPower(string str)
{
  int exp;
  int level;
  int my_exp;
  int level_exp;
  int ex_lvl, lvl, spare;
  if(!str)
  {
     previous_object()->ShowSkills();
     return 1;
  }
  if(sscanf(str, "experience %d", exp) !=1)
  {
     tell_object(this_player(),
      "Zordon tells you: \"Use 'skills experience <amount>.\"\n");
     return 1;
  }
  if (exp < 0) exp = (exp * -1);
  ex_lvl=(int)this_player()->query_extra_level();
  lvl=(int)this_player()->query_level();
  my_exp=(int)this_player()->query_exp();
  if(ex_lvl < 1 && lvl < 21)
    spare = (my_exp - ((int)"/room/adv_guild"->get_next_exp(lvl-1)));
  if(ex_lvl > 0 && lvl < 21)
    spare = (my_exp - ((int)"/room/exlv_guild"->get_next_exp(ex_lvl-1)));
  if(spare >= exp)
  {
    this_player()->add_exp(-exp);
    previous_object()->ABuildPoints(exp);
    tell_object(this_player(),
      "Zordon tells you: \"You have converted " + exp +
      " experience into build points.\"\n");
    previous_object()->ConvertSkillPoint();
    return 1;
  }
  else
  {
    tell_object(this_player(),
      "Zordon tells you: \"You do not have enough free experience for \
that.\"\n");
    return 0;
  }
  return 1;
}

int
QMax() { return 1; }

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("The skills command is used to see your current skills\n\
or to convert experience into skill points.\n\n\
skills                    - shows you all your known skills.\n\
    You will see the following:\n\
    Name:    Level:  Usable:  Max:  Help:   Wiz:\n\
    _____________________________________________\n\
    Rt	  1       Yes      1     Yes        Beck\n\n\
    Name:  The name of the skill\n\
    Level:  How many skill points you have allocated\n\
    Usable:  If the skill is a command you can type to use\n\
    Max:  Max # of skill points you are allowed to allocate\n\
    Help: Help is available.  Type 'ranger <name>'\n\
    Wiz: Name of creation wizard (In case it is broke)\n\n\n\
skills experience <amount>\n" + "\
    converts <amount> experience into build points.\n\
    Also buys skill points if you have enough build points.\n\
    Build points = guild experience.  Skill points are\n\
    what you actually use to purchase skills.\n\n\n\
WARNING: Be thoughful on how you allocate your skills.  There are\n\
more skills available than the number of skill points you will have.\n\
If you allocate too many on 'morph' for example, you will not have\n\
any left to use to build other skills.  This is where you choose\n\
your specialties. There is a limit to the amount of skill points you\n\
can earn.  However, the experience cost becomes so high, that they\n\
become very difficult to obtain. Choose where you use the skill\n\
points wisely when you still can get them easily. If you later wish\n\
to choose to raise items like 'morph' real high, you can do that.\n");
  return 1;
}
