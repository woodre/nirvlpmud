/**************************************************************************
 complex/quest.c, Copyright by Carador, Dec-97, Tubmud
***************************************************************************/

/*

This file is used to implement new quests in Tubmud. You have to put
a file called questname_quest.c in /global/quests. This file must
inherit complex/quest and must be configured properly.

Please read /global/quests/HOWTO_QUESTS for details.
As this file describes all functions of this object I will not
write any comments.

*/

#pragma strong_types

#ifdef NEW_LEVELS

#include <wizlevels.h>
#include <quests.h>

string title;
string short_title;
string author;
int qp;
int low_level;
int high_level;
int time, part_time;
mixed players;
status beginner;
mixed description;

inherit "basic/create";

void reset(int arg)
{
  create::reset(arg);

  if (load_name(this_object()) == "complex/quest") return;

  if (!title)
    raise_error("Missing set_title\n");

  if (!short_title)
    raise_error("Missing set_short_title\n");

  if (!author)
    raise_error("Missing set_author\n");

  if (!qp)
    raise_error("Missing set_quest_points\n");

  if (!low_level)
    raise_error("Missing set_low_level\n");

  if (!high_level)
    raise_error("Missing set_high_level\n");

  if (low_level > high_level)
    raise_error("Low level must not be bigger than high level\n");

  if (low_level < 1)
    raise_error("Illegal low level\n");

  if (high_level > PL_MAX_PLAYER_LEVEL)  // changed >= to >, Coogan, 26-Jun-01
    raise_error("Illegal high level\n");

  if (!time || time > sizeof(TIME_GROUPS))
    raise_error("No or illegal set_duration\n");

  if (part_time < 0)
    raise_error("Illegal set_part_duration\n");
}


static void set_description(mixed d)
{
  description = d;
}


mixed query_description()
{
  return description;
}

static void set_players(mixed p)
{
  players = p;
}


mixed query_players()
{
  return players;
}

static void set_beginner()
{
  beginner = 1;
}

int query_beginner()
{
  return beginner;
}

static void set_duration(string s)
{
  int i;

  if (!s) return;
  i = member(TIME_GROUPS, s);
  if (i<0) return;
  time = i+1;
}

int query_duration()
{
  return time;
}

static void set_part_duration(string s)
{
  int i;

  if (!s) return;
  i = member(TIME_GROUPS, s);
  if (i<0) part_time = -1;
  else part_time = i+1;
}

int query_part_duration()
{
  return part_time;
}


static void set_low_level(int l)
{
  low_level = l;
}

int query_low_level()
{
  return low_level;
}

static void set_high_level(int h)
{
  high_level = h;
}

int query_high_level()
{
  return high_level;
}

static void set_title(string s)
{
  title = s;
}

string query_title()
{
  return title;
}

static void set_short_title(string s)
{
  short_title = s;
}

string query_short_title()
{
  return short_title;
}

static void set_author(string s)
{
  author = s;
}

string query_author()
{
  return author;
}

static void set_quest_points(int q)
{
  qp = q;
}

static void set_qp(int q)
{
  qp = q;
}

int query_quest_points()
{
  return qp;
}

int query_qp()
{
  return qp;
}


mixed query_attributes()
{
  return ({           // global/quests/momu_quest  -> momu
    explode(load_name(this_object()), "/")[<1][0..<7],
    query_short_title(),
    query_title(),
    query_author(),
    query_quest_points(),
    query_low_level(),
    query_high_level(),
    query_duration(),
    query_part_duration(),
    query_players(),
    query_beginner()
  });
}

#endif
