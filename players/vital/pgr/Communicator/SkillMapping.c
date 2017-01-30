/************************************************************************
*  The Power Ranger Guild Skill System                                  *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Updated by vital/keith for the Rangers                               *
*  Last changed 2005.10.13                                              *
*************************************************************************/
#pragma strict_types

#include "../RangerDefs.h"
#include <ansi.h>

mapping Skills;               /* The Skills */
mixed *SkillsSaved;           /* The Saved Skills */
static string *GeneralSkills; /* Non Combat Related Skills */
static string *OffSkills;     /* Offensive Combat Skills */
static string *DefSkills;     /* Defensive Combat Skills */
static string *HiddenSkills;  /* Untrained Skills */
string RangerType;            /* Ranger Morph Type */
string RangerBelt;            /* Ranger Karate Belt Type */
string RangerLeadership;      /* Ranger Leadership Level */

void
AddSkill(string skill_name, int skill_level, int skill_verb, string skill_wiz)
{
  string verb;
  if(Skills == 0) Skills = ([ ]);
  Skills[skill_name] = ({ skill_level , skill_verb , skill_wiz });
  if(skill_verb == 1 || skill_verb == 7) add_action("RangerPower",skill_name);
  verb = "/players/guilds/Rangers/Commands/"+capitalize(skill_name)+".c";
  verb->RangerInit();
}

status
QSkill(string skill_name)
{
  string *skills;
  if(Skills == 0) Skills = ([ ]);
  skills = keys(Skills);
  if(member_array(skill_name, skills) != -1 )
    return 1;
  else
    return 0;
}

mixed
QuerySkillLevel(string skill_name)
{
  string *skills;
  if(Skills == 0) Skills = ([ ]);
  if(!(skills = Skills[skill_name])) return 0;
  skills = Skills[skill_name];
  return skills[0];
}

mixed
QuerySkillVerb(string skill_name)
{
  string *skills;
  if(Skills == 0) Skills = ([ ]);
  if(!(skills = Skills[skill_name])) return 0;
  skills = Skills[skill_name];
  return skills[1];
}

mixed
QuerySkillWiz(string skill_name)
{
  string *skills;
  int hidcheck;
  if(Skills == 0) Skills = ([ ]);
  if(!(skills = Skills[skill_name]))
  {
    hidcheck = member_array(skill_name, HiddenSkills);
    if(hidcheck != -1) return HiddenSkills[hidcheck + 1];
     return 0;
  }
  skills = Skills[skill_name];
  return skills[2];
}  

void
RestoreSkillsSaved()
{
  int i;
  string verb;
  GeneralSkills = ({});
  OffSkills = ({});
  DefSkills = ({});
  if(!SkillsSaved) SkillsSaved = ({});
  Skills = ([ ]);
  if(!this_object()->QNextSkillCost()) this_object()->SNextSkillCost(100);
  for (i=0;i < sizeof(SkillsSaved); i++)
  {
    AddSkill(SkillsSaved[i],
             SkillsSaved[i+1],
             SkillsSaved[i+2],
             SkillsSaved[i+3]);
    if(SkillsSaved[i+2] == 1) add_action("RangerPower",SkillsSaved[i]);
    else if(SkillsSaved[i+2] == 2) GeneralSkills += ({ SkillsSaved[i] }); 
    else if(SkillsSaved[i+2] == 3) OffSkills += ({ SkillsSaved[i] });
    else if(SkillsSaved[i+2] == 4) DefSkills += ({ SkillsSaved[i] });
    else if(SkillsSaved[i+2] == 5)
    {
      OffSkills += ({ SkillsSaved[i] });
      DefSkills += ({ SkillsSaved[i] });
    }
    else if (SkillsSaved[i+2] == 7)
    {
      add_action("RangerPower",SkillsSaved[i]);
      DefSkills += ({ SkillsSaved[i] });
    }
    verb = "/players/guilds/Rangers/Commands/"+capitalize(SkillsSaved[i])+".c";
    verb->RangerInit();
    i=i+3;
  }
}

string *
QDefSkills() { return DefSkills; }

string *
QOffSkills() { return OffSkills; }

void
SaveSkillsSaved()
{
  int i;
  string *skills;
  if(Skills ==0) Skills = ([ ]);
  skills = keys(Skills);
  SkillsSaved = ({ });
  for(i=0; i<sizeof(skills); i++)
  {
    SkillsSaved += ({ skills[i] });
    SkillsSaved += Skills[skills[i]];
  }
}

int
ShowSkills()
{
  string *skills;
  int i;
  string verb;
  skills = keys(Skills);
  write("SKILLS\n");
  write(pad("Name:",15));
  write(pad("Level:",10));
  write(pad("Usable:",8));
  write(pad("Max:",5));
  write(pad("Help:",6));
  write(pad("Wiz:",12));
  write("\n");
  write("________________________________________________\n");
  for(i=0; i<sizeof(skills); i++)
  {
    write(pad(capitalize(skills[i]),15));
    write(pad(QuerySkillLevel(skills[i]),10));
    write(pad(QuerySkillVerb(skills[i]) == 1 ? "Yes" : "No" , 8));
    verb = "/players/guilds/Rangers/Commands/"+capitalize(skills[i])+".c";
    write(pad( (int) verb->QMax(), 5));
    write(pad( (int) verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
    write(pad(capitalize(QuerySkillWiz(skills[i])), 12));
    write("\n");
  }
  for(i=0; i<sizeof(HiddenSkills); i++)
  {
    write(pad(capitalize(HiddenSkills[i]),15));
    write(pad("-",10));
    write(pad("Yes",8));
    verb = "/players/guilds/Rangers/Commands/"+capitalize(HiddenSkills[i])+".c";
    write(pad("-", 5));
    write(pad( (int) verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
    write(pad(capitalize(HiddenSkills[i+1]),12));
    write("\n");
    i=i+1;
  }
  for(i=0; i < sizeof(SKILLS); i++)
  {
     write(pad(capitalize(SKILLS[i]),15));
     write(pad("-",10));
     write(pad("Yes",8));
     verb = "/players/guilds/Rangers/Commands/"+capitalize(SKILLS[i])+".c";
     write(pad("-", 5));
     write(pad( (int) verb->QRangerInfo() == 1 ? "Yes" : "No" , 6));
     write(pad("Beck",12));
     write("\n");
  }
  write("\n");
  write("Unused Skill Points: " + this_object()->QSkillPoints() + "\n");
  write("Build Points: " + this_object()->QBuildPoints() + "\n");
  write("Next Skill Point: " + this_object()->QNextSkillCost() + "\n");
  return 1;
}

void
AHiddenSkill(string name, string wizard, int verb)
{
  if(member_array(name, HiddenSkills) == -1)
  {
    HiddenSkills += ({name, wizard});
    if(verb == 7)
    {
      DefSkills += ({ name });
      add_action("RangerPower", name);
    }
    else if(verb == 6)
    {
      OffSkills += ({ name });
      add_action("RangerPower", name);
    }
    else if(verb == 8)
    {
      DefSkills += ({ name });
      OffSkills += ({ name });
      add_action("RangerPower", name);
    }
    else
      add_action("RangerPower", name);
  }
}

string
query_date()
{
  string stamp, date;
  stamp = ctime();
  date = stamp[4..10]+stamp[20..23];
  return date;
}

string
query_ranger_leadership()
{
  switch(this_object()->QuerySkillLevel("leadership"))
  {
    case 20:      RangerLeadership = "Team Leader"; break;
    case 15..19:  RangerLeadership = "Recruiter"; break;
    case 10..14:  RangerLeadership = "Moderator"; break;
    case 5..9:    RangerLeadership = "Trainer"; break;
    default:      RangerLeadership = "None";
  }
  return RangerLeadership;
}
 
string
query_ranger_type()
{
  switch(this_object()->QuerySkillLevel("morph"))
  {
    case 190..999:  RangerType = "Mystic Force"; break;
    case 170..189:  RangerType = "S.P.D."; break;
    case 150..169:  RangerType = "Dino Thunder"; break;
    case 130..149:  RangerType = "Ninja Storm"; break;
    case 110..129:  RangerType = "Wild Force"; break;
    case 100..109:  RangerType = "Time Force"; break;
    case   90..99:  RangerType = "Lightspeed"; break;
    case   80..89:  RangerType = "Rescue"; break;
    case   70..79:  RangerType = "Galaxy"; break;
    case   60..69:  RangerType = "Space"; break;
    case   50..59:  RangerType = "Turbo"; break;
    case   40..49:  RangerType = "Zeo"; break;
    case   30..39:  RangerType = "Ninja"; break;
    case   20..29:  RangerType = "Thunder"; break;
    case   10..19:  RangerType = "Dino"; break;
    default: RangerType = "Initiate";
  }
  return RangerType;
}
 
string
query_ranger_belt()
{
  switch(this_object()->QuerySkillLevel("combat"))
  {
    case    100:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+RED+
                  " (8)"+OFF; break;
    case     99:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+BOLD+GREEN+
                  " (7)"+OFF; break;
    case     98:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+BOLD+BLUE+
                  " (6)"+OFF; break;
    case     97:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+GREEN+
                  " (5)"+OFF; break;
    case     96:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+BLUE+
                  " (4)"+OFF; break;
    case 94..95:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+MAGENTA+
                  " (3)"+OFF; break;
    case 92..93:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+YELLOW+
                  " (2)"+OFF; break;
    case 90..91:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF+WHITE+
                  " (1)"+OFF; break;
    case 80..89:  RangerBelt = REVERSE+WHITE+BLACK+"Black"+OFF; break;
    case 70..79:  RangerBelt = BROWN+"Brown"+OFF; break;
    case 60..69:  RangerBelt = MAGENTA+"Purple"+OFF; break;
    case 50..59:  RangerBelt = BOLD+BLUE+"Blue"+OFF; break;
    case 40..49:  RangerBelt = GREEN+"Green"+OFF; break;
    case 30..39:  RangerBelt = BOLD+RED+"Red"+OFF; break;
    case 20..29:  RangerBelt = RED+"Orange"+OFF; break;
    case 10..19:  RangerBelt = YELLOW+"Yellow"+OFF; break;
    case   3..9:  RangerBelt = WHITE+"White"+OFF; break;
    default:      RangerBelt = "None";
  }
  return RangerBelt;
}
