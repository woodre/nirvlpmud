#ifndef __LDMUD__
/*
 *      File:                   /wiz/bin/_mv.c
 *      Function:               Mv command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See wizhelp files for 'cp' 'mv' 'paths' 
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/closed/file_auth.c"
/* These obviously will have to be switched. */
#define CP "/bin/wiz/_cp"
#define WILDCARDS "/obj/daemons/wildcards"

/* 
 * Function name:  cmd_mv
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

status cmd_mv(string arg) 
{
  string src, dst, check;
  if(!arg)
  {
    notify_fail("Usage: 'mv <file> <dest>'\n");
    return 0;
  }
 
  if(sscanf(arg, "%s %s %s", src, dst, check) !=3)
    sscanf(arg, "%s %s", src, dst);
  if(check_me(dst,check)) return 1;
  if(check_me(src,check)) return 1;
/* above, check for mudlib core password. below, rebuild arg -Bp */
  arg = src + " " + dst;
  return (status)CP->main("MV", arg);
}
#else

#include "/closed/file_auth.c"

status cmd_mv(string arg) {
  string *args;
  int i, t;

  if (!arg)
    args = ({ });
  else
    args = explode(arg," ")-({});
  if (sizeof(args) > 2) {
    if (file_size(args[<1]) != -2) {
#if 0
      notify_fail("mv: moving multiple files requires last argument to be "
                  "target directory.\n", -1);
#else
      notify_fail("mv: moving multiple files requires last argument to be "
                  "target directory.\n");
#endif
      return 0;
    }
    for (i=0; i<sizeof(args)-1; i++)
      write("mv " + args[i] + " " + args[<1] +
            ((!catch(t=rename(args[i],args[<1])) && !t) ?
             ": OK.\n" : ": Failed.\n"));
    return 1;
  }
  else
    if (sizeof(args) == 2 &&
        !catch(t=rename(args[0],args[1])) && !t)
      write("Ok.\n");
    else
      write("Failed.\n");
  return 1;
}
#endif
