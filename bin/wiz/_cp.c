/*
 *      File:                   /wiz/bin/_cp.c
 *      Function:               Cp command
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
#define WILDCARDS "/obj/daemons/wildcards"

/* Prototype declarations */
status main(string verb, string path);

/* 
 * Function name:  cmd_cp
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

status cmd_cp(string arg) 
{
  string src, dst, check;
  if(!arg)
  {
    notify_fail("Usage: 'cp <file> <dest>'\n");
    return 0;
  }
  if(sscanf(arg, "%s %s %s", src, dst, check) !=3) 
    sscanf(arg, "%s %s", src, dst);
  if(check_me(dst,check)) return 1;
/* above, check for mudlib core password. below, rebuild arg -Bp */
  arg = src + " " + dst;
#if 0
  write("Calling CP " + arg + "\n");
#endif
  return main("CP", arg); 
}

/* 
 * Function name:  single_file
 * Description:    Does mv or cp on a single file.
 * Arguments:      verb  - command to perform
 *                 sfile - source path/file
 *                 dfile - destination path/file
 * Returns:        0 failure, 1 success
 */

status single_file(string verb, string sfile, string dfile)
{
  status i;
  
  if (sfile[strlen(sfile)-1] == '.') return 0;
  if (text_contains(sfile, "\..")) return 0;
  if (file_size(sfile) < 0) return 0;
#ifndef __LDMUD__ /* Rumplemintz */
  i = (verb == "MV" ? rename(sfile, dfile) : cp(sfile, dfile));
#else
  i = (verb == "MV" ? rename(sfile, dfile) : copy_file(sfile, dfile));
#endif
#ifndef __LDMUD__ /* Rumplemintz */
  write((i < 1 ? "Error encountered doing "+lower_case(verb) : verb));
  write(": "+sfile+" to "+dfile+"\n");
#else
  write((i != 0 ? "Error encountered doing " + lower_case(verb) : verb));
  write(": " + sfile + " to " + dfile + "\n");
#endif
  return i;
}

/* 
 * Function name:  strip_path
 * Description:    Strip file pattern from path
 * Arguments:      string spath
 * Returns:        Path without file mask
 */

string strip_path(string spath)
{
  int i;
  
  i = strlen(spath);
  
  if (spath[i-1] == '/') return spath;
  
  while(i--)
    if (spath[i] == '/')
      return spath[0..i];
        
  return spath;
}

/* 
 * Function name:  main
 * Description:    Get file(s) to transfer and execute the command.
 * Arguments:      verb - command to perform
 *                 path - path given by user
 * Returns:        status - 0 (failure) or 1 (success)
 */

status main(string verb, string path)
{
  string sfile, dfile, spath, dpath;
  string *files, *t;
  int i, siz, q;

  if (!verb || (int)this_player()->query_level() < EXPLORE) return 0;  
    
  /*
   * Parse path into source and destination and standardize them
   */
  if (sscanf(path, "%s %s", spath, dpath) != 2)
  {
    /* It's <dest> to current dir format */
#if 0
    write("<dest> to current dir format\n");
    write("source path = " + spath + "\n");
#endif
    dpath = (string)this_player()->query_pwd();
#if 0
    write("dest path is now " + dpath + "\n");
#endif
    spath = path;
  }
#if 0
  write("Calling resolve_path on spath and dpath\n");
#endif
  spath = resolve_path(spath);
  dpath = resolve_path(dpath);
#if 0
  write("spath is now " + spath + "\n");
  write("dpath is now " + dpath + "\n");
#endif
  
  /*
   * See if it's just a single file 
   */
   
  if (file_size(spath) > -1)
  {
    /* See if it's a directory or specific file for destination */
    if (file_size(dpath) == -2) /* It's a directory, strip filename. */
    {    
      i = sizeof(t = explode(spath, "/")) - 1;
      dfile = dpath + t[i];
    }
    else dfile = dpath; /* Dest is a specific filename apparently */
    single_file(verb, spath, dfile);    
    return 1;
  }
  
  /*
   * Have to check for multiple source files.
   */
   
  /* Get the file(s) to be copied. */
  siz = sizeof(files = (string *)WILDCARDS->get_files(spath, 1));
  
  if (!siz) 
  {
    write("CP aborted, no source files: "+spath+"\n");
    return 1;
  }
  
  /* If it's a single file, just figure out if it's a specific filename
   * or just a general dir to cp/mv file to.
   */
  if (siz == 1)
  {
    dfile = (file_size(dpath) == -2 ? dpath+files[0] : dpath);
    spath = strip_path(spath);
    single_file(verb, spath+files[0], dfile);
    return 1;
  }  
  /* It's multiple source files, make sure that the destination is a dir */
  if (file_size(dpath) != -2)
  {
    write("Copying multiple files requires specifying a destination directory.\n");
    write("Destination given: "+dpath+"\n");
    return 1;
  }

  write(verb+": "+spath+" to "+dpath+"\n");
  write("----------------------------------------------------------------------\n");
  spath = strip_path(spath);  
  q = 0;
  
  for (i = 0; i < siz; i++)
    q += single_file(verb, spath+files[i], dpath+files[i]);
  
  write("----------------------------------------------------------------------\n");  
  write(q + " files affected.\n");  
  return 1;
}
