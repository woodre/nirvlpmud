/* **********************************************************************
 * File:                   ~/closed/shardak/new/daemons/commandsd.c     *
 * Function:               Controls all aspects of commands for guild.  *
 * Author(s):              Earwax@Nirvana                               *
 * Copyright:              Copyright (c) 2004 Earwax                    *
 *                                 All Rights Reserved.                 *
 * Source:                 06/14/04                                     *
 * Notes:                                                               *
 * Change History:                                                      *
 * *********************************************************************/

#include "../defs.h"

#define CTYPE CommandsMap[verb][0]
#define CGL CommandsMap[verb][1]
#define CGR CommandsMap[verb][2]
#define CPK CommandsMap[verb][3]
#define CHP CommandsMap[verb][4]
#define CSP CommandsMap[verb][5]
#define CSAC CommandsMap[verb][6]
#define CEXP CommandsMap[verb][7]
#define CTASK CommandsMap[verb][8]
#define CARG CommandsMap[verb][9]
#define CCOMPONENTS 10

/* Global Variables */
mapping CommandsMap;   /* ([ commandname : ({ CTYPE, (Command type)
                        *                     CGL,   (Guild level req)
                        *                     CGR,   (Guild rank req)
                        *                     CPK,   (Is pk req)
                        *                     CHP,   (HP cost)
                        *                     SSP,   (SP cost)
                        *                     CSAC,  (Sac pool cost)
                        *                     CEXP,  (Exp cost)
                        *                     CARG,  (arg test to use)
                        *                     CCOMPONENTS (Components)
                        *                   }) ])
                        */

/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
void
load_map()
{
    int i;
    string *lines, t;
    
    CommandsMap = ([ ]);
    i = sizeof(lines = explode(read_file(COMMANDS_DATA), "\n"));
    
    while(i--)
    {
      if (lines[i][0] == '/')
        continue;
          
      sscanf(lines[i], "%s:%s", t, lines[i]);
      CommandsMap[t] = explode(lines[i], ":");
    }
}
/* ********************************************************************** 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 * *********************************************************************/
string 
*get_commands() 
{ 
  if (!CommandsMap) 
    load_map(); 
    
  return m_indices(CommandsMap);
}

string *rehash() { load_map(); return m_indices(CommandsMap); }
mapping get_full_map() { if (!CommandsMap) load_map(); return CommandsMap+([ ]); }
/* ********************************************************************** 
 * Function name: generate_emote
 * Description:   Create emotes based on who will to see them.
 * Arguments:     argument, modifier, user and target objects
 * Returns:       string (completed emote)
 * *********************************************************************/
string
generate_emote(string arg, string mod, object me, object target, object who)
{
  string *t;
  string mn,ms,mp,mo,tn,ts,tp,to;
  int i;
  status male;
  
  if (who != me)
  {
    male = ((string)me->query_gender() == "male");
    mn = (string)me->query_name();
    ms = (male ? "him" : "her"); 
    mp = (male ? "his" : "her"); 
    mo = (male ? "he" : "she"); 
  }
  else
  { 
    mn = "you";
    ms = "your";
    mp = "your";
    mo = "you"; 
  }
  
  if (who != target)
  {
    male = ((string)target->query_gender() == "male");
    tn = (string)target->query_name();
    ts = (male ? "him" : "her"); 
    tp = (male ? "his" : "her");
    to = (male ? "he" : "she"); 
  }
  else
  { 
    tn = "you";
    ts = "your";
    tp = "your";
    to = "you"; 
  }
     
  i = sizeof(t = explode(NORM+arg+NORM, "$"));
  
  while(i--)
  {
    if (i >= 0 && t[(i - 1)][strlen(t[i]) - 1] == '\\')
    {
      t[i] = "$";
      continue;
    }
    else
    {      
      switch(t[i])
      {
        case "MN"  : t[i] = mn; break;
        case "MS"  : t[i] = ms; break;
        case "MP"  : t[i] = mp; break;
        case "MO"  : t[i] = mo; break;
        case "MOD" : t[i] = mod; break;
        case "TN"  : t[i] = tn; break;
        case "TS"  : t[i] = ts; break;
        case "TP"  : t[i] = tp;  break;
        case "TO"  : t[i] = to; break;
      }
    }
  }

  return capitalize(implode(t, ""));
}
/* ********************************************************************** 
 * Function name: shardak_says
 * Description:   Notify_fail a failure message and return 0
 * Arguments:     string arg - stuffs to say
 * Returns:       status 0
 * *********************************************************************/
status
shardak_says(string arg)
{
  if (strlen(arg) > LINEWRAP)
    arg = (string)WAXFUNS->line_wrap(arg);
    
  notify_fail(HIK+"Shardak tells you, '"+NORM+RED+arg+HIK+"'\n"+NORM+NORM);
  return 0;
}
/* ********************************************************************** 
 * Function name: command_hook
 * Description:   Process and direct commands, deduct costs, failure msgs
 * Arguments:     string verb, string arg, mixed *gstats, string *spells
 * Returns:       status: 0 failure, 1 success
 * *********************************************************************/
status
command_hook(string verb, string arg, mixed *gstats, string *spells, object gob)
{
  object ob, *comps;
  int level, i, hp, sp, sac, exp;
  string *t, name;
    
  level = (int)this_player()->query_level();
  name = capitalize((string)this_player()->query_real_name());
  
  if (level && (string)this_player()->query_guild_name() == "shardak")
    this_player()->set_al(-1000); /* Shards are always evil. */
  
  if (!CommandsMap) /* Should be impossible, but you never know */
    load_map();
    
  /* 
   * EMOTE
   */
     
  if (CTYPE == "emote")
  {
    string to_me, to_target, to_room, modifier;
    string *messages;
    object me, target;
    
    modifier = "";
    me = this_player();
    
    if (!(target = find_player(arg)))
      target = present(arg, environment(me));
      
    if (!target && sscanf(arg, "%s %s", arg, modifier) == 2)
    {
      if (!(target = find_player(arg)))
        if (!(target = present(arg, environment(me))))
          modifier = arg + " " + modifier;
    }
    else
      modifier = (target ? "" : arg);

    messages = (string *)(EMOTESBIN+verb)->get_messages();
    
    if (!target)
    {
      write(generate_emote(messages[0], modifier, me, target, me));
      say(generate_emote(messages[0], modifier, me, target, 0));    
      return 1;
    }
    
    if (environment(target) != environment(me))
    {
      write(generate_emote(messages[2], modifier, me, target, me));
      say(generate_emote(messages[2], modifier, me, target, target));
      return 1;
    }
    
    to_me = generate_emote(messages[1], modifier, me, target, me);
    to_target = generate_emote(messages[1], modifier, me, target, target);
    to_room = generate_emote(messages[1], modifier, me, target, 0);
  
    write(to_me);
    tell_object(target, to_target);
    
    ob = first_inventory(environment(me));
    
    while(ob)
    {
      if (living(ob) && ob != target && ob != me)
        tell_object(ob, to_room);
        
      ob = next_inventory(ob);
    }
    
    return 1;
  }    
  
  /* 
   * MAGUS COMMAND 
   */
  if (CTYPE == "magus")
  {
    if (level < 21)
      return shardak_says("Nice try mortal but you imperil your soul.");
      
    if (level > 99 && gstats[GRANK] != "magus")
    {
      status flag;
      
      write("Shardak obeys your will, senior.\n");
      flag = (status)MAGUSBIN->main(arg, gstats);
      
      if (!flag)
        return 0;
      
      write_file(GLOG, (string)WAXFUNS->date_time()+" - "
        + capitalize((string)this_player()->query_real_name())
        + ": "+HIW+verb+NORM+NORM+" "+arg+"\n");
        
      return 1;
    }
    
    if (gstats[GRANK] != "magus")
      return shardak_says("That command is reserved for magi, wizard.\n");
      
    return (status)MAGUSBIN->main(arg, gstats);
  }
  
  if (level < 19)
    return shardak_says("FOOL!  You are too puny to use my gifts!\n");
   
  if (gstats[GRANK] < CGR)
    return shardak_says("You rank too low amongst my Servants to "
      + verb+".\n");
   
  if (gstats[GLEVEL] < CGL)
    return shardak_says("You aren't experienced enough within the Servants to "
      + verb+".\n");
  
  if (CPK && !((int)this_player()->query_pl_k()))
    return shardak_says("You are too cowardly!\n");
    
  /*
   * COMMAND
   */
  if (CTYPE == "command")
    return (status)(COMMANDSBIN+verb)->main(arg, gstats);
    
  /*
   * SPELL
   */
  if (!spells || !sizeof(spells) || member_array(CTASK, spells) < 0)
    return shardak_says("Very amusing.  You have not earned the "
      + verb + " power yet however.\n");
  
  if(CHP > (int)this_player()->query_hp())
    return shardak_says("Use of this power would destroy your body right now.\n");

  if (CSP > (int)this_player()->query_sp())
    return shardak_says("You lack the spiritual energy.\n");
  
  if (CSAC > gstats[SACPOINTS])
    return shardak_says("UNGRATEFUL CUR!  Ask not what your dark evil dragon-god of destruction can do you for you, but what you can do for your dark evil dragon-god of destruction!\n");
    
  i = sizeof(CommandsMap[verb]);
  
  if (i > 9)
  {
    i = sizeof(t = CommandsMap[verb][10..(i - 1)]);
    comps = allocate(i);
    
    while(i--) 
      if (!(comps[i] = present(t[i], this_player())))
        return shardak_says("You lack a physical component.\n");
  }

  if (CSAC)
    write(HIK+"You attempt to call upon the power of Shardak...\n"+NORM+NORM);
  
  if (!((status)(SPELLSBIN+verb)->main(arg, gstats)))
    return 0;
    
  if (CHP)
  {
    say(HIK+name+"'s body is contorts in pain from the effort of calling upon Shardak.\n"+NORM+NORM);
    this_player()->add_hp(-CHP);
  }
  
  if (CSP)
    this_player()->add_sp(-CSP);
  
  if (CSAC)
    gob->add_sac_points(-CSAC);
    
  if (CEXP)
    this_player()->add_xp(-CEXP);
    
  i = sizeof(comps);
  
  if (i)
    write(RED+"Your components burst into flames and are consumed.\n"+NORM+NORM);
  
  while(i)
  {
    string q;
    
    q = (string)comps[i]->short()+NORM+RED;
    switch(random(10)) /* Just a bit of flavor and variety. */
    {
      case 0 : say(RED+name+" grunts as their "+q+" bursts into flames and consumes itself.\n");
      case 1 : say(RED+name+"'s "+q+" explodes into flames suddenly!\n");
      case 2 : say(RED+"Agony and ecstasy fight for control of "+name+"'s face as their "+q+" consumes itself in a rush of flames!\n");
      case 3 : say(RED+"A "+q+" carried by "+name+" suddenly bursts into flames!\n");
      case 4 : say(RED+"In a billowing flame that ends as abruptly as it begins.  "+name+"'s "+q+" disappears.\n");
      case 5 : say(RED+name+" sacrifices their "+q+" to Shardak in an eruption of flames.\n");
      case 6 : say(RED+"Shardak exacts his price on "+name+" by calling for the sacrifice of their "+q+".\nIt consumes itself in a short conflagration.\n");
      default : say(RED+name+"'s "+q+" is suddenly consumed by flames.\n");
    }
      
    say(NORM+NORM);
    transfer(comps[i], JUNKROOM);
    destruct(comps[i]);
  }
  
  return 1;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
