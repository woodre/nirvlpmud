#if 1
/*
 *      File:                   /wiz/bin/_rm.c
 *      Function:               Cp command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See wizhelp files for 'rm' 'paths' 
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/closed/file_auth.c"
/* This obviously will have to be switched. */
#define WILDCARDS "/obj/daemons/wildcards"

/* 
 * Function name:  cmd_rm
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

status cmd_rm(string path) 
{
  int i, siz, q;
  string check;
  string *files;
  
  if(!path)
  {
    notify_fail("Usage: 'rm <filemask>'\n");
    return 0;
  }

/* lib core passwd check, -Bp */
  if(path[0]==' ') return 0;
  sscanf(path, "%s %s", path, check);
  if(check_me(path,check)) return 1;
#if 0
  write("cmd_rm called - path: " + path + "\n");
#endif

#ifndef __LDMUD__
  path = resolve_path(path);
#else
  if (path[0..1] == "//")
    path = path[1..];
#endif
  
  /* It's a single file. */
  if (file_size(path) > -1)
  {

    if (rm(path))
      write("RM: "+path+"\n");
    else
      write("Error encountered deleting: "+path+"\n");
      
    return 1;
  }
  
  siz = sizeof(files = (string *)WILDCARDS->get_files(path));

  if (!siz)
  {
    write("Aborting, no files to rm: "+path+"\n");
    return 1;
  }
  
  write("RM: "+path);
  write("\n----------------------------------------------------------------------\n");
  q = 0;
  
  for (i = 0; i < siz; i++)
  {
    if (!text_contains(files[i], "..") && files[i][strlen(files[i])-1] != '.')
    {
      if (rm(files[i]))
      {
        write("RM: "+files[i]+"\n");
        q++;
      }
      else
        write("Error encountered in RM: "+files[i]+"\n");
    }
  }
  write("----------------------------------------------------------------------\n");
  write(q+" files affected.\n");
  return 1;
}

#else

#include "/closed/file_auth.c"

status cmd_rm(string arg) {
  string *args;
  int i;

  if (!arg)
    args = ({ });
  else
    args = explode(arg," ")-({});

  if (!sizeof(args)) {
#if 0
    notify_fail("rm what?\n", -1);
#else
    notify_fail("rm what?\n");
#endif
    return 0;
  }

#if 0
  /* Security check */
  if (check_me(args[i], check))
    return 1;
#endif

  for (i=0; i<sizeof(args); i++)
    write("rm " + args[i] + (rm(args[i]) ? ": Ok.\n" : ": Failed.\n"));
  return 1;
}
#endif
