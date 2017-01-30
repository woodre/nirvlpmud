/*
 *      File:                   /obj/simul_efun/command_sfuns.c
 *      Function:               The sfuns pertaining to command system.
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax(David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/29/06
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* Global Variables */
mapping  command_mapping,
         level_required;
string  *command_types;
status   flag_loaded;
status   Flag_Override;

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
status query_override() { return Flag_Override; }
 
string strip_command(string arg) { return (arg ? arg[1..<3] : 0); } 
 
void load_command_arrays()
{

  level_required = ([ 
    "/bin/secure/" :     ELDER,
    "/bin/wiz/secure/" : CREATE,
    "/bin/wiz/" :        CREATE,
    "/bin/play/" :       0,
    "/bin/soul/" :       0
  ]);
  
  command_types = ({
    "/bin/secure/",
    "/bin/wiz/secure/",
    "/bin/wiz/",
    "/bin/play/",
    "/bin/soul/"
  });
  
  command_mapping = ([ ]);
  Flag_Override = 1;
  
  foreach(string type : command_types) 
  {
    command_mapping[type] = map(get_dir(sprintf("%s_*.c", type)), #'strip_command);
  }
  
  Flag_Override = 0;
  flag_loaded = 1;
  write_file("/ldmud.log", sprintf("%s: Commands loaded without problem.\n", ctime()));
}

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

varargs status execute_command(string verb, string arg, int level)
{
  int i;
  string err;
  string command_path, fun_to_call;
  
  if (!flag_loaded)
  {
    err = catch(load_command_arrays());
    
    if (err)
    {
      write_file("/ldmud.log", sprintf("%s: Commands did not load:\n%s\n", ctime(), err));
      printf("Commands did NOT load, kicking out of here.\n");
      return 0;
    }
  }
  
  if (arg && sscanf(arg, "%s %s", verb, arg) != 2)
  {
    arg = 0;
  }
    
  if (!verb) return 0;
  if (!arg) arg = 0;
  if (level < 19) level = 19;
    
  foreach(string type : command_types)
  {
    if (level >= level_required[type] && ((i = member(command_mapping[type], verb) > -1)))
    {
      status t;
      
      command_path = sprintf("%s_%s.c", type, verb);
      fun_to_call = sprintf("cmd_%s", verb);
      t = ((int)call_other(command_path,fun_to_call,arg) > 0);
      return t;
    }
  }
  
  return 0;
}
