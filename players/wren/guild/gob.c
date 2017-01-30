/*
 * Hey .. Need to add spell support.
 * Reduce mi/sh/fi/so efficiency.
 *
 */

#include "def.h"

inherit "/players/vertebraker/closed/std/auto_load";

string guild_title;
int    guild_rank;
int    guild_exp;
string *saved_classic_skills;
string *saved_futuristic_skills;
string master;

static object workroom;

static mapping classic_skills, futuristic_skills;

status id(string str)
{
 return (str==OBJID||str=="guild_object");
}

void reset(status x)
{
 if(x) return;
 classic_skills=futuristic_skills=([]);
 cmd_dir=DIR_CMD;
}

void clean_slate()
{
 saved_classic_skills=saved_futuristic_skills=({});
 guild_exp=guild_rank=0;
 guild_title="the Apprentice";
 master="NoOne";
 TO->save_me();
}

void init()
{
 if(!TO->restore_me())
  clean_slate();
 ::init();
}

void set_guild_title(string x)
{
 guild_title=x;
}

string query_guild_title()
{
 return guild_title;
}

void add_guild_rank(int x)
{
 guild_rank+=x;
}

void set_guild_rank(int x)
{
 guild_rank=x;
}

int query_guild_rank()
{
 return guild_rank;
}

void set_guild_exp(int x)
{
 guild_exp=x;
}

int query_guild_exp()
{
 return guild_exp;
}

void set_classic(string skill, int amt)
{
 classic_skills[skill]=amt;
}

void add_classic(string skill, int amt)
{
 classic_skills[skill]+=amt;
}

int query_classic(string skill)
{
 return classic_skills[skill];
}

mapping query_classics()
{
 return classic_skills;
}

void set_futuristic(string skill, int amt)
{
 futuristic_skills[skill]=amt;
}

void add_futuristic(string skill, int amt)
{
 futuristic_skills[skill]+=amt;
}

int query_futuristic(string skill)
{
 return futuristic_skills[skill];
}

mapping query_futuristics()
{
 return futuristic_skills;
}

void set_workroom(object ob)
{
 workroom=ob;
}

object query_workroom()
{
 return workroom;
}

status restore_me()
{
 futuristic_skills=reconstruct_mapping(saved_futuristic_skills);
 classic_skills=reconstruct_mapping(saved_classic_skills);
 return restore_object(SAVE_CHAR+(string)ENV->RN);
}

void save_me()
{
 saved_classic_skills=deconstruct_mapping(classic_skills);
 saved_futuristic_skills=deconstruct_mapping(futuristic_skills);
 save_object(SAVE_CHAR+(string)ENV->RN);
}
