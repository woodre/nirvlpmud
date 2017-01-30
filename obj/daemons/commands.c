/*
 *      File:                   /obj/daemons/comands.c
 *      Function:               Handle commands/nicknames/aliases
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/20/06
 *      Notes:                  
 *      Change History:
 */

#include <security.h>

/* Global Variables */
string *PlayerCommands;
string *SocialCommands;
string *WizardCommands;
string *ElderCommands;

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

string *load_commands(string arg)
{
  int i;
  string *files;
  
  i = sizeof(files = get_dir(arg+"_*.c"));
  
  while(i--)
#ifndef __LDMUD__ /* Rumplemintz */
    files[i] = files[i][1..-3];
#else
    files[i] = files[i][1..<3];
#endif
    
  return files;
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

void reset(status arg)
{
  if (arg)
    return;
  SocialCommands = load_commands("/bin/soul/");
  PlayerCommands = load_commands("/bin/play/");
  WizardCommands = load_commands("/bin/wiz/");
  ElderCommands  = load_commands("/closed/bin/");
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

/* Haven't decided whether to use this or to use xverb method */

string *get_commands(int level)
{
  if (level < WIZARD)
    return PlayerCommands + SocialCommands;
    
  if (level < ELDER)
    return PlayerCommands + SocialCommands + WizardCommands;
    
  return PlayerCommands + SocialCommands + WizardCommands + ElderCommands;
}
  
/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
  
int route_command(string verb, string arg, int level)
{
  if (level >= ELDER && member(ElderCommands, verb))
    return (int)call_other("/closed/bin/_"+verb, "cmd_"+verb, arg);
  if (level >= WIZARD && member(WizardCommands, verb))
    return (int)call_other("/bin/wiz/_"+verb, "cmd_"+verb, arg);
  if (member(PlayerCommands, verb))
    return (int)call_other("/bin/play/_"+verb, "cmd_"+verb, arg);
  if (member(SocialCommands, verb))
    return (int)call_other("/bin/soul/_"+verb, "cmd_"+verb, arg);
  
  return 0;
}

  
  


  
  
  
  
/* ========================================================================
 * Alias Processing
 * ========================================================================
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
int process_alias(string arg, mapping Aliases)
{
  string key, value;
  string *keys;
  int i;
  
  if (sscanf(arg, "%s %s", key, value) != 2)
  {
    /* Delete Alias */
    printf("Deleted the following alias: %s\nAssigned value of: %s\n", arg, Aliases[arg]);
    Aliases -= ([ arg ]);
    return 1;
  } 
 
  /* Overwrite an existing alias */
  if (member(Aliases, key))
  {
    printf("Overwriting alias: %s.\n", key);
    printf("Old definition: %s\nNew Definition: %s\n", Aliases[key], value);
    Aliases[key] = value;
    return 1;
  }    
    
  /* If fewer than 50 aliases existing, add alias */
  if (sizeof(m_indices(Aliases)) >= 50)
  {
    write("Limited to 50 aliases, delete or overwrite an existing one.");
    return 1;
  }
  
  printf("Adding new alias: %s - %s\n", key, value);
  Aliases[key] = value;
  return 1;
}
 
/* ========================================================================
 * Nickname Processing
 * ========================================================================
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
int process_nickname(string arg, mapping Nicknames)
{
  string key, value;
  string *keys;
  int i;
  
  if (sscanf(arg, "%s %s", key, value) != 2)
  {
    /* Delete Alias */
    printf("Deleted the following nickname: %s\nAssigned value of: %s\n", arg, Nicknames[arg]);
    Nicknames -= ([ arg ]);
    return 1;
  } 
 
  /* Overwrite an existing nickname */
  if (member(Nicknames, key))
  {
    printf("Overwriting nickname: %s.\n", key);
    printf("Old definition: %s\nNew Definition: %s\n", Nicknames[key], value);
    Nicknames[key] = value;
    return 1;
  }    
    
  /* If fewer than 50 nicknames existing, add alias */
  if (sizeof(m_indices(Nicknames)) >= 50)
  {
    write("Limited to 50 nicknames, delete or overwrite an existing one.");
    return 1;
  }
  
  printf("Adding new nickname: %s - %s\n", key, value);
  Nicknames[key] = value;
  return 1;
}
 
 
 
/* ========================================================================
 * List Aliases or Nicknames, convert Aliases or Nicknames
 * ========================================================================
 */
status list_subs(string which, mapping maptouse)
{
  int i, siz;
  string *keys;
  
  siz = sizeof(keys = m_indices(maptouse));
  
  write("========================================================================\n");
  printf("Your %s.", which);
  write("========================================================================\n");
  
  for (i = 0; i < siz; i++)
  {
    printf("%-15s %s\n", keys[i], maptouse[keys[i]]);
  }

  write("========================================================================\n");
  printf("Total number of %s:%d.", which, siz);
  write("========================================================================\n");
  return 1;
} 

void convert_substitutions(string *saved_aliases, mapping Aliases, 
                           string *saved_nicknames, mapping Nicknames)
{
  int i, siz;
  
  if (saved_aliases)
  {
    Aliases = ([ ]);
    
    for (i = 0, siz = sizeof(saved_aliases); i < siz; i += 2)
      Aliases[saved_aliases[i]] = saved_aliases[i+1];
      
    saved_aliases = 0;
  }
   
  if (saved_nicknames)
  {
    Nicknames = ([ ]);
    
    for (i = 0, siz = sizeof(saved_nicknames); i < siz; i += 2)
      Aliases[saved_nicknames[i]] = saved_nicknames[i+1];
      
    saved_nicknames = 0;
  }
}
  
