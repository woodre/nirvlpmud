/*
 *      File:                   /std/wildcards.c
 *      Function:               Return file or files responding to
 *                              wildcards specified.
 *      Author(s):              Ew@Nirvana
 *      Copyright:              Copyright (c) 2006 Ew/David Halek
 *                                      All Rights Reserved.
 *      Source:                 07/31/06
 *                              Was used as a daemon for DR driver version.
 *                              Recoded to be used as an inherit.
 */

#include "/sys/files.h"
#pragma weak_types

/* Global Variables */
string  path_to_use;
mixed  *all_info;

status filter_out_files(mixed *t) { return t[2] == -2; }
status filter_out_dirs(mixed *t) { return t[2] >= 0;  }
status ascending(mixed *t, mixed *t2) { return t[0] > t[1]; }

/*  
 * Function name:  get_files()
 * Description:    Returns an array of files matching wildcard criteria.
 * Arguments:      String dir, or filename with or without wildcards
 *                 string path - path/mask to return
 *                 flag_get_all:   1 to return all dirs and files
 *                 flag_just_dirs: 1 to return just the directories
 * Returns:        Array of files matching specified wildcards.
 *                  0 if file or dir does not exist.
 */
 
varargs status 
get_files(string path, status flag_get_all, status flag_just_dirs)
{
  int siz;
  
  path_to_use = 0;

  if (!(path = normalize_path(path)))
    return 0; /* Not sure this can happen, but just in case */
    
  if (path[<1] != '/' && file_size(path) == -2)
    path = sprintf("%s/", path);
    
  all_info = transpose_array( ({ get_dir(path, GETDIR_NAMES|GETDIR_UNSORTED)
                               , get_dir(path, GETDIR_PATH|GETDIR_UNSORTED)
                               , get_dir(path, GETDIR_SIZES) }) );
  if (!all_info || !sizeof(all_info)) 
  {
    return 0;
  }
  
  if (!flag_get_all)
  { 
    string t;
    
    t = (flag_just_dirs ? "filter_out_files" : "filter_out_dirs");
    all_info = filter(all_info, t);
  }
  
  all_info = sort_array(all_info, "ascending");
  siz = strrstr(all_info[<1][1], "/");
  path_to_use = all_info[<1][1];
  path_to_use = sprintf("/%s", path_to_use[0..siz]);
  siz = sizeof(all_info);
  while(siz--) all_info[siz][1] = sprintf("/%s", all_info[siz][1]);
  
  return 1;
}

string get_path_for(string arg)
{
  int pos;
  
  if (!arg) return 0;
  
  pos = strrstr(arg, "/");
  
  if (pos < 0) return 0;
  
  arg = arg[0..pos];
  
  if (arg[0] != '/')
    arg = sprintf("/%s", arg);
    
  return arg;
}

string strip_path(string arg)
{
  int pos;
  
  if (!arg || arg[<1] == '/') return 0;
  
  pos = strrstr(arg, "/");
  
  if (pos < 0) return 0;
  
  return arg[pos+1..];
} 

#ifdef 0
void reset(status arg) {
  int i, siz;
  mixed err;
  
  if (arg) return;
  
  err = catch(get_files("/obj/../players/earwax/../earwax/blah.c"));
  if (err)
  { write("ERROR FOUND.\n");write(err);write("\n"); return; }
  
  if (!all_info || !sizeof(all_info))
  {
    write("NO files found.\n"); write("Path was: "+path_to_use+"\n");
    return;
  }
  
  
  
  
  foreach(mixed *blah : all_info) { printf("%s\n", blah[1]); }
  printf("IN RESET PATH IS: %s\n",path_to_use);
}
#endif