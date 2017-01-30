/************************************************************************
*  Power Ranger Guild Armor.                                           *
*  Created by Beck/Russ Warren for Nirvana                             *
*  Updated by vital/keith for the Rangers                              *
*  Last changed 2005.10.13                                             *
************************************************************************/
#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

static string name, alias, short_desc, long_desc;
static int value, weight;
static string type;
static int size, save_flag, worn, ac;
static object worn_by;
static object next;
static string info;
static int set_ac_flag;

void
link(object ob) { next = ob; }

object
remove_link(string str)
{
  object ob;
  if(str == name)
  {
    ob = next;
    next = 0;
    return ob;
  }
  if(next) next = (object) call_other(next, "remove_link", str);
  return this_object();
}

string
rec_short()
{
  if(next) return name + ", " + call_other(next, "rec_short");
  return name;
}

mixed
test_type(string str)
{
  if(str == type) return this_object();
  if(next) return call_other(next, "test_type", str);
  return 0;
}

int
tot_ac()
{
  if(next) return ac + call_other(next, "tot_ac");
  return ac;
}

string
query_type() { return type; }

status
query_worn() { return worn; }

int
armor_class() { return ac; }

void
set_weight(int w) { weight = w; }

void
set_ac(int a)
{
  ac = a; 
  set_ac_flag = 7;
}

status
valid_armor(string t)
{
  switch(t)
  {
    case "armor":
    case "helmet":
    case "boots":
    case "ring":
    case "amulet":
    case "shield":
    case "misc":
    case "bracelet":
    case "cloak":
    case "chest" :
    case "necklace":
    case "earring":
    case "gloves":
    case "pants":
    case "belt": return 1;
    default: return 0;
  }
  return 0; /* Rumplemintz */
}

void
set_type(string t)
{
  if (ac > 0 || !set_ac_flag)
  {
    if(!valid_armor(t)) destruct (this_object());
  }
  type = t;
}

void
set_arm_light(int lightvalue) { set_light(lightvalue); }

status
query_paladin_shield() { return 1; }

int
shield_bonus(object ob)
{
  mixed *skills, *defskills;
  string skill, msg, name, attack;
  int i;
  int prot;
  int temp;
  int result;
  prot = 0;  /* Need some skills for any AC */
  name = capitalize( (string) environment(this_object())->query_real_name());
  if(environment(this_object())->query_attack())
  {
    attack =
      (string) (environment(this_object())->query_attack())->query_name();
  }
  else
  {
    attack = "Enemy";
  }
  /* AC bonus for being morphed.  */
  if(this_object()->QMorphed() || this_object()->QNinja())
  {
    temp = (int) this_object()->QuerySkillLevel("morph");
    for(i=10; i < temp; i++)
    {
      prot += 1;
      result += 1;
      temp -= i;
    }
/*      prot += 1+(QuerySkillLevel("morph") / 15); */
  }  
  /* for ld, changed (array) below to (mixed) appears ok in DR -Bp */
  defskills = (mixed) this_object()->QDefSkills();
  for(i=0; i < sizeof(defskills); i++)
  {
    prot += 
      (int) ("/players/guilds/Rangers/Commands/" + capitalize(defskills[i]) +
      ".c")->DefSkill(1); /* DefSkill passed 1, as value is discarded */
  }
  if(prot < 0) prot = 0;
  if(prot > 100)
  {
    if( (prot - ((100/prot)*100)) > 40)
    {
      prot = ((100/prot)*100) + 40;
    }
  }
  else if(prot < 40) prot = 40; 
  return prot;
}

