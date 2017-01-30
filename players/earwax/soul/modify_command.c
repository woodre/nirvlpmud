/*
 *      File:                   /obj/player/modify_command.c
 *      Function:               Process commands before driver sees them -
 *                              Aliases, Nicknames
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/20/06
 *      Notes:                  Inherited by player.c
 *                              Processes nicknames/aliases in /obj/daemons/commands
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* Global Variables */
string *saved_aliases;   /* Legacy Support                     */
string *saved_nicknames; /* Legacy Support                     */
mapping Aliases;         /* ([ alias: definition ])            */
mapping Nicknames;       /* ([ nickname: text to substitute ]) */

static string *ActionHistory;
static int     ActionTicker;

/* ========================================================================
 * Action history functions
 * ========================================================================
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        
 */

string add_action_history(string cmd)
{
  string text_to_add;
  
  if (!cmd) return 0;

  if (!ActionHistory)
    ActionHistory = allocate(31);
    
  ActionTicker++;
  text_to_add = sprintf("%5d: %s", ActionTicker, cmd);

  if (ActionTicker < 30)
    ActionHistory[ActionTicker] = text_to_add;
  else
  {
    ActionHistory[30] = text_to_add;
    ActionHistory = ActionHistory[1..];
  }
    
  ActionTicker++;
  return cmd;
}

string * query_action_history()
{
  if (!this_player() 
  || (int)this_player()->query_level() < (int)this_object()->query_level()
  || ((int)x->query_level() < 99999 && (int)this_object()->query_privblk()))
   return 0;
   
  return (ActionTicker < 30 ? ActionHistory[0..ActionTicker-1] 
                            : ActionHistory[0..29]);
}

int query_action_ticker()
{
     return ActionTicker;
}

string query_action_history_position(int pos)
{
  if (!this_player() 
  || (int)this_player()->query_level() < (int)this_object()->query_level())
    return 0;  
    
  return action_history[pos];
}

/* ========================================================================
 * Alias and Nickname functions
 * ========================================================================
 * Function name:  
 * Description:    
 * Arguments:      
 * Returns:        1 to tell driver not to process the command
 */

status list_subs(string which, mapping subs)
{
  printf("<%-78'-'s>\n", "");
  printf("Your %s.\n", which);
  printf("<%-78'-'s>\n", "");
  foreach(string bleh: subs)
  {
    printf("%-15s: %s\n", bleh, subs[bleh]);
  }
  printf("<%-78'-'s>\n", "");
  printf("Total number of %s:%d\n", lower_case(which), sizeof(subs));
  printf("<%-78'-'s>\n", "");
  add_action_history(lower_case(which));
  return 1;
}

status process_sub(string arg, string which, mapping subs)
{
  string index, value;
  
  if (sscanf(arg, "%s %s", index, value) != 2)
  {
    if (member(subs, index))
    {
      printf("Deleting %s %s: %s\n", which, arg, subs[arg]);
      subs -= index;
    }
    else printf("No %s defined for %s.\n", which, arg);
  }
  else if (member(subs, index))
  {
    printf("Replacing %s.\nOld value: %s\nNew value: %s\n"
    , index, subs[index], value);
    subs[index] = value;
  }
  else if (sizeof(subs) >= 50)
    printf("You can only have 50 %s defined.\n"
    , (which == "alias" ? "aliases" : "nicknames"));
  else
  {
    printf("Assigning %s to %s: %s\n", which, index, value);
    subs[index] = value;
  }
  
  add_action_history(sprintf("%s %s", which, arg));
  this_object()->save_me();
  return 1;
}
      
/* ========================================================================
 * modify_command
 * ========================================================================
 * Function name:  modify_command
 * Description:    Modify commands before they go to the driver for parsing
 * Arguments:      (string) command as typed by player
 * Returns:        0 - use unmodified command
 *                 (string) modified command to pass to driver
 *                 non-zero integer - ignore the command altogether
 */

mixed 
modify_command(string command)
{
  string verb, arg;
  string *subs, *args;
  int i, t, siz;
  
  if (!command)
    return 1;
   
  if ((string)this_object()->query_afk_message() && !query_idle(this_object()))
  {
    write("You return from being afk.\n");
    say(sprintf("%s returns from being afk.\n", (string)this_object()->query_name())
    , this_object());
    this_object()->set_afk_message(0);
  }
       
  if ((!Aliases || Aliases == ([ ])) && sizeof(saved_aliases))
  {
    Aliases = ([ ]);
    
    for (i = 0, siz = sizeof(saved_aliases); i < siz; i += 2)
      Aliases[saved_aliases[i]] = saved_aliases[i+1];
  }  

  if ((!Nicknames || Nicknames == ([ ])) && sizeof(saved_nicknames))
  {
    Nicknames = ([ ]);
    
    for (i = 0, siz = sizeof(saved_nicknames); i < siz; i += 2)
      Nicknames[saved_nicknames[i]] = saved_nicknames[i+1];
  }  
     
  /* Parse into verb and argument */
  if (sscanf(command, "%s %s", verb, arg) != 2)
    {
    verb = command;
    arg = 0;
  }

  /* Expand and return the standard aliases */
  switch(verb) {
    case "n"  : return add_action_history("north");
    case "ne" : return add_action_history("northeast");
    case "nw" : return add_action_history("northwest");
    case "s"  : return add_action_history("south");
    case "se" : return add_action_history("southeast");
    case "sw" : return add_action_history("southwest");
    case "u"  : return add_action_history("up");
    case "d"  : return add_action_history("down");
    case "heals+" : return add_action_history("heals_all");
  }

  /* Check if it's an alias, if so, substitute it out */
  if (Aliases && member(Aliases, verb))
  {
    verb = Aliases[verb];
  }
  
  /* Now parse it into verb and argument again */
  if (arg) verb = sprintf("%s %s", verb, arg);
  if (sscanf(verb, "%s %s", verb, arg) != 2) arg = 0;
  
  /* If it's a nickname or alias command, process it */
  if (verb == "alias" || verb == "unalias")
  {
    return (arg ? list_subs("Aliases", Aliases) 
                : process_sub(arg, "alias", Aliases));
  }

  if (verb == "nickname" || verb == "unnickname")
  {
    return (arg ? list_subs("Nicknames", Nicknames) 
                : process_sub(arg, "nickname", Nicknames));
  }

  /* Check if a nickname is involved, if so, substitute it out */
  if (!arg || !sizeof(Nicknames)) return add_action_history(verb);
  
  arg = implode(map(explode(arg, " "), Nicknames), " ");
  
  return add_action_history(sprintf("%s %s", verb, arg)); 
} 
  
  
  
