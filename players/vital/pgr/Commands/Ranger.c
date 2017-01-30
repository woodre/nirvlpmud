#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string str)
{
  string verb;
  string wiz;
  string *filename;
  write("*****************P o w e r \
  R a n g e r s****************************\n\n");
  write(BOLD + RED + "Red" + OFF +
        " Letters indicates help available for highlighted word.\n\n");
  if(!str || str == "ranger")
  {
    write("\n\
  The Power Rangers guild is based loosely on the Fox TV show.\n\
It should be considered a 'good' guild, where teamwork is the\n\
main objective.  In this guild any weak link will be amplified.\n\
This guild is designed as a " + BOLD + BLUE + "role playing guild" + OFF +
". The experience\n\
cost is very high and will likely NOT reflect the actual abilities\n\
of performance with in the guild itself.\n\
Please see the following topics for much more information.\n\n\
    Topics:\n        " + HIR + "training" + NORM + "   " + HIR + "power" +
NORM + "    " + HIR + "pk" + NORM + "\n\        " + HIR + "spells" + NORM +
"     " + HIR + "quests" + NORM + "   " + HIR + "conduct" + NORM +
"\n\        " + HIR + "combat2" + NORM + "\n\
To see information on a topic: type 'ranger <topic>'.\n");
    return 1;
  }
  else if(str == "training")
  {
    write(
"*************************Power Ranger Training***********************\n\n\n\
Training for the Power Rangers guild differs slightly from that of \n\
any other guild.  There is no set place for training to take place.\n\
Training is done by seeking out select NPC's .\n\n\
You must first aquire skill points.  These are obtained by converting\n\
experience, practice, and gold into build points.  Once you have obtained\n\
enough build points, you may convert these into skill points.\n\
Skill points are used directly to learn or increase your ability in a\n\
particular skill.\n\ In general 1 experience = 1 build point.\n\
Each skill point costs 1.04 times the amount of the previous skill point.\n\
The first skill point costs 100 build points.\n\
You may allocate skill points however you want.  Some skills have no limit\n\
in the amount of skill points you may allocate for them.\n\
Be aware, though, that once you have allocated a skill point, it is almost \n\
completely permanent. One skill will let you retrain, but at a cost.\n"+"\
Also know that there can be many skills out there that you may not know \n\
about, so keep this in mind, before blowing through all your current skill \n\
points only on skills you already know.\n\n\
Major skill areas are:\n\t" + HIR + "Morph" + NORM + "\n\t" + HIR + "Combat" +
NORM + "\n\t" + HIR + "Leadership" + NORM + "\n\t" + HIR + "Team" + NORM +
"\n\t" + HIR + "Communication" + NORM + "\n\t" + HIR + "Teleport" + NORM +
"\n\t" + HIR + "Machine" + NORM + "\n\n\
You may see the current skills you know by the command 'skills'.\n\
This will also show you your unused skill points, and the amount\n\
of build points required for the next level.\n\n\
Help files are available on almost every known skill.\n\
Type 'ranger <skill name>' for more information.\n\
Skills that every Ranger knows are:\n\n\
  " + HIR + "skills" + NORM + "  " + HIR + "rsc" + NORM + "  " + HIR + "ri" + NORM + "  " + HIR + "ansi" + NORM + "  " + HIR + "ranger" + NORM + "\n");
    return 1;
  }
  else if(str == "power")
  {
    write(
 "**************************Guild Power******************************\n\n\n\
 Guild Powers are not used from spell points as in other guilds.\n\
 Instead there is a pool of points used by every member of the guild.\n\
 All guild powers are supported by this pool.\n\
 It will be " + BOLD + BLUE + " members " + OFF + "of the guild own \
 responsibility to maintain the\npower levels.  If the pool drops below 0 no \
 members powers will work.\nIt will take teamwork from all members to properly \
 maintain the\nGuild Power levels.\n\
 Players can add to the pool by donating their own sps (not 1:1),\n\
 or by donating objects for a percentage of their value in gold.\n");
    return 1;
  }
  else if(str == "combat2")
  {
    write(""+
"***************************COMBAT***********************************\n\n\n\
Combat is the Primary ability of the Power Rangers Guild.\n\
There are a few key differences between the Rangers and any other\n\
guild.\n\
The main difference is that Power Rangers never have a need for \n\
" + HIR + "Armor" + NORM + " or " + HIR + "Weapons" + NORM +
". In fact they cant use them.  \n\
A Power Ranger is equipped with the only weapon and armor they\n\
need, automatically at the point they login to Nirvana.\n\
Power Rangers can engage in combat anytime, but they receive special\n\
bonuses if they are morphed.  There is a bonus for just being morphed\n\
as well as an 'armor' function bonus, and a 'weapon' bonus.\n"+"\
The 'armor' and 'weapon' commands only add small bonuses that require\n\
power points each round of combat.  Do NOT think that without them\n\
you have no weapon or armor (I need to clarify once again that these\n\
are only small bonuses).\n\
To improve your combat ability you should train Combat, Morph,\n\
and obtain the 2 skills listed above.\n\
Power Rangers cannot initially attack a good creature while morphed.\n");
    return 1;
  }
  else if(str == "spells")
  {
    write(
"******************************SPELLS**********************************\n\n\n\
Power Rangers have no spell use capability.  They may not use \n\
the standard game spells, and there are no guild spells.\n\
There is no guild healing spell either.\n\
Power Rangers are designed to be completely hand to hand combat\n\
oriented.\n");
    return 1;
  }
  else if(str == "quests")
  {
    write(
"****************************QUESTS************************************\n\n\n\
At this time there are no special guild quest that you will partake in.\n\
The only thing you need to do is seek out the people you need to train\n\
with.  That is not really questing as it is not at all hard to do.\n\
Rather it is designed for role playing atmosphere purposes.\n");
     return 1;
  }
  else if(str == "conduct")
  {
    write(
"*******************************CONDUCT********************************\n\n\n\
As a member of the Power Rangers I expect you will conduct yourself\n\
in a manner and role in accordance to the guild.  The Power Rangers\n\
are 'good' and I expect for players to assume that role while using\n\
their Power Ranger character.\n\
I will not tolerate evil acts by guild members, which include, but is\n\
not limited to things such as: personal verbal abuse to any player or\n\
wizard, extensive lack of cooperation with other guild members (using\n\
guild resources without giving back, and refusing to help other guild\n\
members --> showing or telling how to do things.  I frown on not \n"+"\
partying with other guild members, but will tolerate it), or\n\
any act that discredits the guild or its members.\n\
The punishment for such offenses is automatic removal from the guild\n\
and loss of all experience invested in it.\n");
    return 1;
  }
  else if(str == "pk")
  {
    write(
"*********************Player Killing*********************************\n\n\n\
The Power Rangers are allowed to set their Player Killing if they\n\
choose to do so.  \n\
Be aware there is no protected guild hall, so if you set PK\n\
There is NOWHERE to hide.\n\
I also expect that player killers would only attack those who are\n\
in 'evil' guilds.\n\n\
There are some skill improvements coming to give those who desire to\n\
participate in pk a greater ability to do so, while maintaining both\n\
the theme/role-playing aspect of the guild and also be more competitive\n\
in the area of player versus player combat.\n");
    return 1;
  }
  if(!(wiz = (string) previous_object()->QuerySkillWiz(str)))
  {
    wiz = "guilds";
    if(file_size("/players/"+wiz+"/Rangers/Commands/"+capitalize(str)+".c") < 0)
    {
       notify_fail("No info available on that topic.\n");
       return 0; 
    }
  }
   
   verb = "/players/guilds/Rangers/Commands/"+capitalize(str)+".c";
      
   if(verb->RangerInfo()) return 1;
   else
      write("No info available on that topic.\n");
   return 1;
}

