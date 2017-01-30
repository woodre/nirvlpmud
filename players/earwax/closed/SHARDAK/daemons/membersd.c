/* **********************************************************************
 * File:                   ~/closed/SHARDAK/daemons/membersd.c          *
 * Function:               Members Daemon, controls membership funs     *
 * Author(s):              Earwax@Nirvana                               *
 * Copyright:              Copyright (c) 2004 Earwax                    *
 *                                 All Rights Reserved.                 *
 * Source:                 06/16/04                                     *
 * Notes:                                                               *
 * Change History:                                                      *
 * *********************************************************************/

#include "../defs.h"

#pragma weak_types

/* Global Variables */
static mapping  MembersMap;
       string  *MemberNames;
       mixed   *MemberInfo;
       string  *Banned;
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
void
load_info()
{
  int i;
  
  MembersMap = ([ ]);
  restore_object(MEMBERS_DATA);

  i = sizeof(MemberNames);
  
  while(i--)
    MembersMap[MemberNames[i]] = MemberInfo[i];
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
void
save_info()
{
  MemberNames = m_indices(MembersMap);
  MemberInfo = m_values(MembersMap);
  save_object(MEMBERS_DATA);
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
void
reset(status arg)
{
  if (arg)
    return;
    
  Banned = ({ });
  MemberNames = ({ });
  MemberInfo = ({ ({ }) });
  load_info();
}
/* ********************************************************************** 
 * Function name:  query_member
 * Description:    Check if online player is a member of Shards.
 * Arguments:      object ob - player object to check, cloner's object
 * Returns:        Banned -1, nonmember 0, senior 1, member 2
 * *********************************************************************/
varargs
int
check_member(object ob, object cloner)
{
  string name;
  int level, i;
  
  if (!MembersMap)
    load_info();
  
  if (!ob) 
    return 0;
    
  name = (string)ob->query_real_name();
  level = (int)ob->query_level();
  i = member_array(name, Banned);
  
  if (i > -1)
  {
    tell_object(ob, RED+"Shardak tells you, '"+HIK+"You are banned from my order for:\n"
      +Banned[(i+1)]+ NORM+NORM+RED+"'\n"+NORM+NORM);
    write_file(LOG_BANNED, (string)WAXFUNS->date_time()+" - "
      + " gob cloned to: "+capitalize(name)+" by "
      + ((cloner && living(cloner)) ? capitalize((string)cloner->query_real_name())
      : "Unknown") + ".\n");
      
    if (cloner && cloner != ob)
      tell_object(cloner, HIR
        + "DO NOT ATTEMPT TO CLONE GUILD OBJECTS TO BANISHED MEMBERS.\n"+NORM+NORM);
/* Might have to uncomment this later        
    else
*/
      perform_rapage(ob);
      
    return -1;
  }
      
  if (member(MembersMap, name))
    return 2;
 
  if (level < 20)
  {
    tell_object(ob, RED+"Shardak tells you, '"+HIK
      + "Do not attempt that again."+NORM+NORM+RED+"'\n"+NORM+NORM);
    write_file(LOG_CLONE, (string)WAXFUNS->date_time()+" - "
      + " Cloned to Player: "+capitalize(name)+" by "
      + ((cloner && living(cloner)) ? capitalize((string)cloner->query_real_name())
      : "Unknown") + ".\n");
    if (cloner && cloner != ob)
      tell_object(cloner, "Cloning guild objects to nonmembers will not work.\n");
      
    this_player()->move_player("fleeing from Shardak's rage#"+BANNED_HOME);
    return 0;
  }
  
  if (level > 99)
  {
    tell_object(ob, "\
You are welcome to check the guild out as a guest.  If you wish to change\n\
something, please go through Earwax.  As he is an active wizard, and the \n\
guild is his, there is no reason why this shouldn't be possible.\n\n\
Note: your commands will be somewhat limited, and in order to set a test \n\
char up for the guild, please use the '"+HIW+"testchar"+NORM+NORM+"' command.\n");
    log_file(LOG_CLONE, (string)WAXFUNS->date_time()+" - "
      + HIR+"SENIOR CLONED GOB: "+name+"\n"+NORM+NORM);
    return 1;
  }
  
  tell_object(ob, "\
You may not clone this guild object, nor may you join this guild in any \n\
capacity.  Do not keep attempting to clone this, or you will have your hands\n\
full trying to undo what will be done to you.  Do not try to put this guild\n\
object on others, there are means for them to restore their guild objects if\n\
they are a valid member of the guild.  Do not test my patience on this.\n");
  log_file(LOG_CLONE, (string)WAXFUNS->date_time()+" - "
    + "WIZARD CLONED GOB: "+name+"\n"+NORM+NORM);
  return 0;
}
/* ********************************************************************** 
 * Function name: query_member
 * Description:   Returns whether ob is an official member
 * Arguments:     object ob - ob to check on, or name to check
 * Returns:       status - 0 not member, 1 is member
 * *********************************************************************/
varargs
status
query_member(object ob, string name)
{
  string t;
  
  t = (ob ? (string)ob->query_real_name() : name);
  
  if (!t)
    return 0;
    
  if (!MembersMap)
    load_info();
    
  return (member(MembersMap, t));
}
/* ********************************************************************** 
 * Function name: add_member
 * Description:   Add a member to the guild
 * Arguments:     name to add, their guild stats, their recruiter
 * Returns:       void
 * *********************************************************************/
void
add_member(string name, mixed *gstats, string recruiter)
{
  if (!MembersMap)
    load_info();
    
  MembersMap[name] = ({ gstats[GLEVEL], gstats[GRANK], gstats[GTITLE], 
    (string)WAXFUNS->date_time() });
  save_info();
  write_file(ADD_MEMBER, (string)WAXFUNS->date_time()
    + " - "+name+" added by "+recruiter+".\n");
}
/* ********************************************************************** 
 * Function name: perform_rapage
 * Description:   When a player is booted or leaves guild.
 * Arguments:     object ob - the player object do rapage upon
 * Returns:       void
 * *********************************************************************/
void
perform_rapage(object ob)
{
  object gob;
  string *stats;
  int i, cash, exp, level, xlevel;
  
  stats = ({ "str", "sta", "mag", "luc", "int", "dex", "ste", "pie" });
  i = 8;
  cash = (int)ob->query_money();
  exp = (int)ob->query_experience();
  level = (int)ob->query_level();
  xlevel = (int)ob->query_extra_level();
  
  write_file(RAPAGE, (string)WAXFUNS->date_time() + " - "
    + "Name: "+capitalize((string)ob->query_real_name())
    + " Level: "+level+"+"+xlevel+" Exp: "+exp+" Coins: "+cash
    + "\n                 ");

  while(i--)
  {
    write_file(RAPAGE, capitalize(stats[i])+" "+(int)ob->query_attrib(stats[i]));
    
    if (i) 
      write_file(RAPAGE, ", ");
      
    ob->set_attrib(stats[i], 1);
  }
  
  write_file(RAPAGE, "\n");
  ob->add_exp(-exp + 1);
  ob->set_level(1);
  ob->set_extra_level(0);
  ob->add_money(-cash);
  ob->set_home(BANNED_HOME);
  ob->set_pretitle(BANNED_PRETITLE);
  ob->set_title(BANNED_TITLE);
  ob->set_race(BANNED_RACE);
  ob->set_description(BANNED_DESC);
  ob->set_guild_rank(0);
  ob->set_guild_name(0);
  ob->set_guild_file(0);
  tell_object(ob, HIK+"\
Shardak tells you, '"+NORM+NORM+RED+
                   "You are less than nothing in my eyes now.  Everything\n\
I have given you, I have taken away, and you are now as a newborn babe.  \n\
Do not whine, do not cry.  You made your decisions, and I have made mine.\n\
Do not ever attempt to rejoin my followers, do not complain to wizards \n\
or gods about what has been done to you.  You were advised of the \n\
consequences of leaving this order when you joined.  Begone, and beware\n\
my minions.  They will thirst for your blood forever."+HIK+"'\n"+NORM+NORM);

  if ((gob = present(GOB_ID, ob)))
    destruct(gob);
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
void
add_banned(string name, string reason)
{
  object ob;
  
  if (!MembersMap)
    load_info();
    
  if (member(MembersMap, name))
    MembersMap = m_delete(name);
  
  Banned += ({ name, reason });  
  write_file(BANNED, (string)WAXFUNS->date_time()+" - "
    + name + ": "+reason+".\n");
    
  if ((ob = find_player(name)))
    perform_rapage(ob);
    
  cp("/"+DATADIR+".o", BANISHDIR+name+".banished");
  rm("/"+DATADIR+".o");
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
string *query_banned_list() { return Banned; }
mapping query_members_map() { return MembersMap+([ ]); }

mixed 
*query_members_arr() 
{ 
  return transpose_array(m_indices(MembersMap), m_values(MembersMap)); 
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
