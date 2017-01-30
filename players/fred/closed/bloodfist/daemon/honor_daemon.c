/* Honor Daemon for Bloodfist - 1.0                                */
/* Prevent wizards/testchars from being in it.                     */

#include "/players/fred/closed/bloodfist/defs.h"

mapping guild_members;
string *saved_members;
static int size;
static int *values;
int timer;
static object gob;

/********************** Mapping Funs *******************************/
void save_mapping()
{
  saved_members = deconstruct_mapping(guild_members);
  save_object("players/fred/closed/bloodfist/log/honor_log");
}

int restore_mapping()
{
  int a;
  a = restore_object("players/fred/closed/bloodfist/log/honor_log");
  guild_members = reconstruct_mapping(saved_members);
  return a;
}
/*******************************************************************/

void reset(mixed arg){
  if(arg) return;

  /* size = sizeof(files("players/fred/closed/bloodfist/member/*.o")); */

  guild_members = ([ ]);

  if(!restore_mapping())
    timer = time() + 432000; 
  else if(timer < time())
  {
    int x;
    string *ks;
    size= sizeof(ks=keys(guild_members));
    for(x = 0; x < size; x++)  /* everybody loses 1 honor */
    {
     /*
     if(guild_members[ks[x]] > 0)
        guild_members[ks[x]] --;
     */
    }
    timer = time() + 14400; /* 4 hours */
  }
  size = sizeof(keys(guild_members));
  save_mapping();
}

/*******************************************************************/
/********************** Member Funs ********************************/
int add_member(string name)
{
  if(!name) return 0;
  gob = present("bloodfist_gob", find_player(name));
  if(file_size("/players/fred/closed/bloodfist/member/"+name+".o") > 0
    || find_player(name)->query_level() < 20
    || gob->is_testchar() == 0)
  {
    guild_members[name] = 0;
    size++;
    save_mapping();
  }
  else {
    write(capitalize(name)+"'s .o file is either 0k or not there.\n");
    return 0;
  }
  return 1;
}

int rm_member(string name)
{
  if(!name) return 0;
  if(file_size("/players/fred/closed/bloodfist/member/"+name+".o") <= 0)
  {
    write(capitalize(name)+"'s .o file is either 0k or not there.\n");
    return 0;
  }
  else {
    /* check if same member (rm'ing last or first) */
    if(!size)
      guild_members[name] = 0;
    else if(guild_members[name] == guild_members[size])
      guild_members[name] = 0;
    else
      guild_members[name] = guild_members[size];
    size--;
    save_mapping();
    return 1;
  }
  return 0;
}

void print_top_members(object me)
{
  int b, c, d;
  mixed *temp, g;
  temp = keys(guild_members);
  c = 1;
  for(d = 0; d < size, c > 0; d++)
  {
    c = 0;
    for(b = 0; b < size; b++)
    {
      if((b + 1) < size) /* at least one more */
      {
        if(guild_members[temp[b+1]] > guild_members[temp[b]]) /* swap */
        {
          c = 1;                /* a swap was made */
          g = temp[b+1];
          temp[b+1] = temp[b];
          temp[b] = g; 
        }
      }
    }
  }
  for(b = 0, c = 0; b < size; b++) /* top 10 */
  {
    if(guild_members[temp[b]] > 0)
      tell_object(me, pad("",14)+pad(capitalize(temp[b]),14)+
        guild_members[temp[b]]+"\n");
    c++;
    if(c > 9)
      return;
  }
}

/*
mixed *
get_top(mixed n)
{
  int i, s;
  mixed *val, *chub;
  mapping c;

  val = sort_array(m_values(c = (mapping)LIB->query_contest()),
         "sort_me", this_object());

  s = sizeof(val);
  chub = ({ });

  if(stringp(n)) n = sizeof(val);
  for(i = 0; i < n; i ++)
  {
    if(s > i)
    {
      if(!val[i]) chub += ({ "None", 0 });
      else 
        chub += ({ get_key(c, val[i]), val[i] });
    }
    else
      chub += ({ "None", 0 });
  }

  return chub;
}
*/

void print_members(object me) /* display both key and value of all elements */
{
  int b;
  mixed *temp;
  if(!me) return;
  temp = keys(guild_members);
  for(b = 0; b < size; b++)
  {
    if(guild_members[temp[b]] < 1)
      tell_object(me, pad("",14)+pad(capitalize(temp[b]),14)+
        "No Blood Honor\n");
    else 
      tell_object(me, pad("",14)+pad(capitalize(temp[b]),14)+
        guild_members[temp[b]]+"\n");
  }
}
/*******************************************************************/
/********************** Honor Funs *********************************/
int query_honor(string name)
{
  /* if(guild_members[name]) */
    return guild_members[name];
    /*
  else
    return -1;
    */
}

int honor_check(int val)
{
  object me;
  me = this_player();
  gob = present("bloodfist_gob", me);
  me = environment(gob);
  if(!gob) return 0;
  if(gob->is_testchar() || me->query_level() > 20) return 1;
  if(query_honor((string)me->query_real_name()) >= val) return 1;
  return 0;
}

void add_honor(string name, int amt, object pgob)
{
  if(!pgob) return;
  if(file_size("/players/fred/closed/bloodfist/member/"+name+".o") > 0
    && find_player(name) && find_player(name)->query_level() < 20
    && pgob->is_testchar() == 0)
  {
    guild_members[name] += amt;
    save_mapping();
    tell_object(find_player(name), 
      HIR+"Your Blood Honor has increased.\n"+NORM);
  }
  else {
    if(find_player(name))
      tell_object(find_player(name), 
      HIR+"Blood Honor gained but not added.\n"+NORM);
  }
}

void rm_honor(string name, int amt)
{
  if(guild_members[name])
  {
    guild_members[name] -= amt;
    save_mapping();
  }
}

string display_honor(string name)
{
  object me;
  if(!name) return 0;
  if(!(me = find_player(name))) return 0;
  gob = present("bloodfist_gob", me);

  if(gob)
  {
    if(gob->is_testchar())
      return "Testchar";
  }
  else
    return guild_members[name];

  if(me->query_level() > 19)
    return "Wizard";
  else if(guild_members[name] < gob->query_hrank(1))
    return RED+"BloodInitiate"+NORM+" ("+guild_members[name]+")";
  else if(guild_members[name] < gob->query_hrank(2))
    return RED+"BloodApprentice"+NORM+" ("+guild_members[name]+")";
  else if(guild_members[name] < gob->query_hrank(3))
    return RED+"BloodRogue"+NORM+" ("+guild_members[name]+")";
  else if(guild_members[name] < gob->query_hrank(4))
    return RED+"BloodWarrior"+NORM+" ("+guild_members[name]+")";
  else if(guild_members[name] < gob->query_hrank(5))
    return RED+"BloodLord"+NORM+" ("+guild_members[name]+")";
  else if(guild_members[name] > gob->query_hrank(5))
    return RED+"BloodMaster"+NORM+" ("+guild_members[name]+")";
  else
    return guild_members[name];
}
/*******************************************************************/

