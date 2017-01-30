/*
 *      File:                   /bin/wiz/_mk.c
 *      Function:               MK command: updates and reloads a file,
 *                              displays error messages, deletes log
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  See wizhelp files for 'mk' 'paths'
 *                              This is a recode of the mk done by Verte 
 *                              07/08/01 that was later updated by Illarion
 *                              original header is at the end of the file,
 *                              my recode was pretty much total however
 *      Change History:
 */

#include "/sys/security.h"

status
cmd_mk2(string arg)
{
  object ob, here;
  int junk;
  string error, log;
  string junk2, name;
  status flag_here,   /* recloning environment              */
         flag_inv,    /* recloning an item in inventory     */
         flag_env;    /* recloning an object in environment */
  
  if((int)this_player()->query_level() < CREATE)
    return 0;

  if(!arg)
  {
    write("MK: syntax: mk <filename>\n");
    return 1;
  }

  here = environment(this_player());

  if(arg == "here") 
  {
    arg = object_name(here);
    flag_here = 1;
    sscanf(arg, "%s#%d", arg, junk);
  }
  else if (ob = present(arg, this_player()))
  {
    arg = object_name(ob);
    flag_inv = 1;
    sscanf(arg, "%s#%d", arg, junk);
  }
  else if (ob = present(arg, here))
  {
    arg = object_name(ob);
    flag_env = 1;
    sscanf(arg, "%s#%d", arg, junk);
  }
  else if (!(arg = normalize_path(arg)))
  {
    printf("MK: Cannot find or resolve path to %s\n", arg);
    return 1;
  }
    
  if (arg[<2..] != "\.c") arg = sprintf("%s.c", arg);
  if (arg[0] != '/') arg = sprintf("/%s", arg);

  printf("MK: Attempting to mk: %s.\n",arg);
  printf("MK: Checking for file ... ");
  
  if(file_size(arg) < 0)
  {
    printf("Invalid path or insufficient privileges.\n");
    return 1;
  }              

  if(ob = find_object(arg))
  {
    write("Object found ... updating old copy ... ");
    
    if(ob == here) 
      move_object(this_player(), "/room/void");

    /* Move to using remove() lfun for destruction */
    ob->remove();
    if (ob) destruct(ob);
    write("Destructed.\n");
  }
  else
  {
    write("No object found.\n");
  }
  
  write("Loading new copy ... ");

  if (!(error = catch(arg->load_me())) && ob = find_object(arg))
  {
    write("Loaded.\n");
    
    if (flag_here)
    {
      move_object(this_player(), ob);
      write("Returned you to the room.\n");
    }
    else if (flag_inv)
    {
      move_object(ob, this_player());
      write("Returned object to your inventory.\n");
    }
    else if (flag_env)
    {
      move_object(ob, here);
      write("Returned object to your environment.\n");
    }
    
    write("Success!\n");
  }
  else
  {
    if (error)
      printf("ERROR: \n%s\n", error);
    log = (sscanf(arg, "/players/%s/%s", name, junk2) == 2
    ? sprintf("/log/%s", name) : "/ldmud.log");
    printf("<%-78'-'s>", "");
    
    if(file_size(log) > 0)
    {
      printf("LOGFILE: %s (check /debug.log as well)\n", log);
      tail(log);
    }
    else
    {
      printf("LOGFILE:  Not found: %s.\nDisplaying /debug.log\n", log);
      tail("/debug.log");
    }
    
    printf("<%-78'-'s>", "");
    
    if (name)
    {
      if (name == (string)this_player()->query_real_name())
      {  
        command("rlog", this_player());
        write("Error log deleted.\n");
      }
      else if ((int)this_player()->query_level() >= SENIOR
      && (string)this_player()->query_log() == log)
      {
        if (command(sprintf("rlog %s", name), this_player()))
        {
          printf("Deleted log: %s\n", log);
        }
        else
        {
          printf("Error log removal failed: %s\n", log);
        }
      }
    }
    else 
      printf("Log not deleted (it's not yours): %s", log);
  }
  
  return 1;
}

 /*
 * Standard Load/Update cmd by V [7.8.01]
 * Also catches a load error and shows the log
 *
 * Updated by Illarion:
 * tails the proper log for other dirs
 * doesn't delete the log if it's another wizard's
 * doesn't try to load a file the wizard can't read
 * resolves .. and ~wizardname format
 *
 * if it breaks, replace it with _mk.bak
 *
 */
