/************************************************************************
*  The Power Ranger Training System                                     *
*  Created by Beck/Russ Warren for Nirvana                              * 
*  Updated by vital/keith for the Rangers                               *
*  Last changed 2005.10.13                                              *
*************************************************************************/
#pragma strict_types

#include "../RangerDefs.h"
#include <ansi.h>

int SkillPoint;
int NextSkillCost;
int BuildPoint;

static string skill;
static int skill_points;
static int skill_verb;
static string skill_wiz;
static string Teacher;

int
QSkillPoints() { return SkillPoint; }

int
QBuildPoints() { return BuildPoint; }

void
SNextSkillCost(int cost) { NextSkillCost = cost; }

int
QNextSkillCost() { return NextSkillCost; }

void
ABuildPoints(int num)
{
  BuildPoint += num;
  this_object()->SaveRanger();
}

void
RBuildPoints(int num)
{
  BuildPoint -= num;
  this_object()->SaveRanger();
}

void
ASkillPoints(int num)
{
  SkillPoint += num;
  this_object()->SaveRanger();
}

void
RSkillPoints(int num)
{
  SkillPoint -= num;
  this_object()->SaveRanger();
}

void
TrainRangerSkill(string skill_name, int skill_verb_num,
                 string skill_wiz_name, string teacher, int per)
{
  string file;
  skill = skill_name;
  skill_verb = skill_verb_num;
  skill_wiz = skill_wiz_name;
  if(this_object()->QSkill(skill_name))
    skill_points = (int) this_object()->QuerySkillLevel(skill_name);
  else
     skill_points = 0;
  if ( QSkillPoints() == 0 ) return;
  file = "/players/guilds/Rangers/Commands/"+capitalize(skill)+".c";
  if (skill_points >= file->QMax()) return;
  if (per < random(100) ) return;
  Teacher = teacher;
  call_out("message",1);
  if(environment(this_object())->is_kid()) return;
  else
  {
    input_to("FinishTrainRanger");
  }
  return;
}

void
message()
{
  object trainee;
  if(environment(this_object()))
  {
    if(environment(this_object())->is_player())
    {
      tell_object(environment(this_object()), Teacher +
        " asks: Would you like to advance your skill in " + skill +
        "? (yes/no)\n");
      tell_object(environment(this_object()), "Your current level is " +
        skill_points + ".\n");
    }
    else if(environment(this_object())->is_kid())
    {
      tell_room(environment((environment(this_object()))), Teacher +
        " asks: Would " + environment(this_object())->query_name() +
        " like to advance their skill in " + skill + "? (yes/no)\n");
      tell_room(environment((environment(this_object()))),
        "Their current level is " +
        skill_points + ".\n");
    }
    else
      return;
  }
  else
    return;
}

void
FinishTrainRanger(string ack)
{
  if(ack == "yes" && skill)
  {
    ASkillPoints(-1);
    skill_points += 1;
    this_object()->AddSkill(skill, skill_points, skill_verb, skill_wiz);
    this_object()->SaveSkillsSaved();
    this_object()->SaveRanger();
    if(environment(this_object())->is_kid())
    {
      tell_room(environment((environment(this_object()))),
        (string) environment(this_object())->query_name() +
        " has advanced their skill in " + skill + ".\n");
    }
    else
      tell_object(environment(this_object()),
        "You have advanced your skill in " + skill + ".\n");
  }
  else
  {
    if(environment(this_object())->is_kid())
    {
      tell_room(environment((environment(this_object()))),
        environment(this_object())->query_name() +
        " can advance that skill another time then.\n");
    }
    else
      tell_object(environment(this_object()),
        "You can advance that skill another time then.\n");
  }
  skill = 0;
  return;
}

status
ConvertSkillPoint()
{
  int rep;
  if(BuildPoint > NextSkillCost)
  {
    while(BuildPoint > NextSkillCost)
    {
      RBuildPoints(NextSkillCost);
      ASkillPoints(1);
      NextSkillCost = NextSkillCost * 104;
      NextSkillCost = NextSkillCost / 100;
      if(NextSkillCost > 1000000) NextSkillCost = 1000000;
      rep += 1;
    }
    write("You have added " + rep +
      " skill point(s), which you may use to advance any skill.\n");
    write("Your next skill will cost you " + NextSkillCost + ".\n");
    return 1;
  }
  else
  {
    write("You have not invested enough to obtain the next skill point.\n");
    return 1;
  }
}

status
ReTrainRanger(string skill_name)
{
  if(this_object()->QSkill(skill_name))
  {
    skill = skill_name;
    skill_points = (int) this_object()->QuerySkillLevel(skill_name);
    skill_verb = (int) this_object()->QuerySkillVerb(skill_name);
    skill_wiz = (string) this_object()->QuerySkillWiz(skill_name); 
    if(skill_points < 6)
    {
      write("You must keep at least 5 skill points in every skill.\n");
      return 0;
    }
    skill_points -= 1;
    this_object()->AddSkill(skill, skill_points, skill_verb, skill_wiz);
    this_object()->SaveSkillsSaved();
    this_object()->SaveRanger();
    ASkillPoints(1);
    return 1;
  }
  return 0;
}
