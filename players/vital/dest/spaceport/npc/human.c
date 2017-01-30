/******************************************************************************
 *  File:           human.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.03
 *  Notes:
 *  Change Histhis_object()ry: 2001.01.04; 2001.01.15; 2003.09.11;
 *                  2005.10.22 [strict_types and fixed ids]
 *
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>
#include "/players/vital/dest/include/spaceport.h"

inherit "/players/vital/closed/std/monster";

object item, weapon, helmet, boots, misc;
string *name_desc, *alias_desc, grace;
int name_num, alias_num;
int rnd;

string get_name();
string get_race();
string get_alias();

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  name_desc =
  ({
    "marc", "leptis", "xang", "leruv", "shiv", "erkcen", "vau", "pugap",
    "peeltor", "aknububa", "zeflel", "gongar", "psystic", "balton", "faib", 
    "korypal", "andabado", "antlol", "duplin", "dwayne", "typra", "lutzporg",
    "this_object()mmy", "sluror", "winnona", "myrkyr", "kirk", "lisa", "mona",
    "jesse", "andripal", "mol", "smarks", "nugt", "onfyl", "whipple",
  });
  alias_desc =
  ({
    "guy", "traveler", "adventurer", "regular", "passenger", "worker",
    "engineer", "executive", "porter", "clerk", "attendant"
  });
  switch(random(3))
  {
    case 0:
      helmet=clone_object(SPARMOR + "hat.c");
      move_object(helmet, this_object());
      item=clone_object(SPOBJ + "suitcase.c");
      move_object(item, this_object());
      break;
    case 1:
      item=clone_object(SPOBJ + "chit.c");
      move_object(item, this_object());
      weapon=clone_object(SPWEAPON + "info_pda.c");
      move_object(weapon, this_object());
      break;
    case 2:
      item=clone_object(SPOBJ + "bell.c");
      move_object(item, this_object());
      boots=clone_object(SPARMOR + "boots.c")
      ; move_object(boots, this_object());
      misc=clone_object(SPARMOR + "coat.c");
      move_object(misc, this_object());
      break;
  }
  rnd = random(6);
  set_name(get_name());
  set_alias(get_alias());
  set_race(get_race());
  set_gender(random(2) ? "male" : "female");
  set_short("A Milieu " + alias + " named " + capitalize(name));
  set_long(format("  " + short_desc + ".\n" + short_desc +
    " is a typical of the " + alias +
    "s found all over the \nMilieu. People like " + capitalize(name) + 
    " like to wander around while waiting\nfor something \
to happen.\n"));
  set_level(11 + rnd);
  set_wander(5 + random(10), 0, ({}));
  set_al(-40 * rnd);
  set_dead_ob(this_object());
  add_money( (int) this_object()->query_level() * (rnd + 1));
}

string
get_race()
{
  switch(random(5))
  {
    case 0: grace = "human"; break;
    case 1: grace = "simbari"; break;
    case 2: grace = "krondaku"; break;
    case 3: grace = "poltroyan"; break;
    case 4: grace = "gi"; break;
  }
  return grace;
}

string
get_name()
{
  int x;
  x = sizeof (name_desc);
  name_num = random(x - 1);
  name = name_desc[name_num];
  return name;
}

string
get_alias()
{
  int x;
  x = sizeof (alias_desc);
  alias_num = random(x - 1);
  alias = alias_desc[alias_num];
  return alias;
}
