#include <ansi.h>
#include <security.h>

#include "../lib/guild_defs.h"

object shadowee;

void start_shadow(object ob)
{
   shadowee = ob;
   shadow(ob, 1);
}

void end_shadow()
{
   shadow(shadowee, 0);
   destruct(me);
}

status query_undead_shadow() { return 1; }

string short()
{
   string tag;
   string title;
   object gob;
   tag = "";
   if(gob = present("guild_object", shadowee))
  {
    if(gob->query_var(V_HEAD)) tag += "Decapitated";
    if(gob->query_var(V_LLEG) || gob->query_var(V_RLEG))
      tag += (tag==""?"Legless":", Legless");
    if(gob->query_var(V_LARM) || gob->query_var(V_RARM))
      tag += (tag==""?"Armless":", Armless");
  }
     if(tag != "") tag = "The "+tag+" Body of ";
   title = (string)MASTER->get_title(shadowee);
   if((int)shadowee->query_level() < 21)
      shadowee->set_title(title);
   return tag+(string)shadowee->short();
}

int set_title(string title)
{
   if((int)shadowee->query_level() >= 21)
      return (int)shadowee->set_title(title);
   short();
   return 1;
}

int set_pretitle(string title)
{
  if((int)shadowee->query_level() >= 21)
    return (int)shadowee->set_pretitle(title);
  short();
  return 1;
}

int add_hit_point(int arg)
{
  int result, org, new;
  object x;
  if((x=TP) && (x != shadowee) && ((int)x->query_level() < CREATE) && arg > 0)
  {
    org = (int)shadowee->QHP;
    result = (int)shadowee->AHP(arg);
    new = (int)shadowee->QHP;
    if(org < new)
    {
      tell_object(shadowee, "\
Your body is "+HIR+"gripped"+NORM+" with "+HIR+
"PAIN"+NORM+" from the Healing Power!\n");
      tell_room(ENV(shadowee),
(string)shadowee->QN+"'s skin "+HIR+"BLISTERS"+NORM+"!\n",
  ({shadowee}));
      shadowee->HP(arg*3+random(arg),"other|good");
    }
    return result;
  }
  return (int)shadowee->AHP(arg);
}

int add_spell_point(int arg)
{
  int result, org, new;
  object x;
  if((x=TP) && (x != shadowee) && ((int)x->query_level() < CREATE) && arg > 0)
  {
    org = (int)shadowee->QSP;
    result = (int)shadowee->ASP(arg);
    new = (int)shadowee->QSP;
    if(org < new)
    {
      tell_object(shadowee, "\
Your body is "+HIR+"gripped"+NORM+" with "+HIR+
"PAIN"+NORM+" from the Rejuvenating Power!\n");
      tell_room(ENV(shadowee),
(string)shadowee->QN+"'s skin "+HIR+"BLISTERS"+NORM+"!\n",
  ({shadowee}));
      shadowee->HP(arg*3+random(arg),"other|good");
    }
    return result;
  }
  return (int)shadowee->ASP(arg);
}

int heal_self(int arg)
{
  int result, org, new;
  object x;
  if((x=TP) && (x != shadowee) && ((int)x->query_level() < CREATE) && arg > 0)
  {
    org = ((int)shadowee->QHP + (int)shadowee->QSP);
    result = (int)shadowee->HS(arg);
    new = ((int)shadowee->QHP + (int)shadowee->QSP);
    if(org < new)
    {
      tell_object(shadowee, "\
Your body is "+HIR+"gripped"+NORM+" with "+HIR+
"PAIN"+NORM+" from the Healing Power!\n");
      tell_room(ENV(shadowee),
(string)shadowee->QN+"'s skin "+HIR+"BLISTERS"+NORM+"!\n",
  ({shadowee}));
      shadowee->HP(arg*3+random(arg),"other|good");
    }
    return result;
  }
  return (int)shadowee->HS(arg);
}

int drink_alcohol(int strength)
{
  tell_object(shadowee, "\
Alcohol has no effect on an Undead.\n");
  return 0;
}

void add_intoxination(int strength) { }

string query_race()
{
  return HIK+"Undead"+NORM;
}

void set_race() { }

void long()
{
  shadowee->set_race(HIK+"Undead"+NORM);
  shadowee->long();
}

status second_life()
{
  object gob;
  if(gob = present("guild_object", shadowee))
  {
    gob->undead_death();
  }
  return (int)shadowee->second_life();
}
