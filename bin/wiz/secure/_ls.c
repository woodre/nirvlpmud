/*
 *      File:                   /bin/wiz/secure/_ls.c
 *      Function:               
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/24/06
 *      Notes:                  
 *      Change History:
 */

#include "/sys/files.h"
#include "/sys/ansi.h"
#include "/sys/security.h"

/* 
 * Function name:
 * Description:
 * Arguments:      Flags: d - date stamp
 *                        q - 'quick' ls - unformatted for large dirs
 *                        l - large terminal width
 * Returns:
 */

nomask status cmd_ls(string arg)
{
  status  flag_date, flag_quick;
  int     width;
  int     i, j, k, siz, siz2;
  mixed  *file_info;
  string *names;
  string *paths;
  string  colord, colorh, coloro, colorc;
  int     temp_length, max_length, temp_size;
  int     total_files, total_dirs, total_size;
  string  arg1, arg2;
  string  alltext;
  mapping colors;
  
  flag_quick = flag_date = 0;
  width = 80;

  /* Parse flags passed */  
  if (arg && sscanf(arg, "%s %s", arg1, arg2) == 2)
  {
    if (arg1[0] == '-')
    {
      arg = arg2;
    }
    else if(arg2[0] == '-')
    {
      arg = arg1;
      arg1 = arg2;
    }
  }
  else if (arg && arg[0] == '-')
  {
    arg1 = arg;
    arg = "";
  }
 
  if (arg1)
  {
    for (i = 0, siz = strlen(arg1); i < siz; i++)
    {
      switch(arg1[i])
      {
        case 'd': flag_date  = 1; break;
        case 'q': flag_quick = 1; break;
        case 'l': width = 120; break;
      }
    }
  }  

  arg = normalize_path(arg, this_player());
  
  if (file_size(arg) == -2 && arg[<1] != '/')
    arg = sprintf("%s/", arg);

  printf("LS: %s\n", arg);

  /* Perform quick directory - basically minimal formatting, only filename */
  if (flag_quick)
  {
    names = get_dir(arg, GETDIR_NAMES);
    
    if (!names)
    {
      printf("LS: Invalid path or insufficient priveleges: %s\n", arg);
      return 1;
    }
    
    i = siz = sizeof(names);
    printf("LS: Quick-list of: %s\n", arg);  
    printf("%-*#s\n", width, implode(names, "\n"));    
    printf("\n\t%d items listed.\n", sizeof(names));
    return 1;
  }

  /* Retrieve file info and turn it into output */
  paths = get_dir(arg, GETDIR_PATH);
  
  if (!paths)
  {
    printf("LS: Invalid path or insufficient priveleges: %s\n", arg);
    return 1;
  }
  
  file_info = get_dir(arg, (flag_date ? GETDIR_ALL : GETDIR_NAMES|GETDIR_SIZES));

  siz = sizeof(file_info);
  siz2 = siz / (flag_date ? 3 : 2);
  names = allocate(siz2);
  /* Get their color scheme */
  colord = (string)this_player()->get_ansi_pref("ls directory");
  colorc = (string)this_player()->get_ansi_pref("ls .c");
  colorh = (string)this_player()->get_ansi_pref("ls .h");
  coloro = (string)this_player()->get_ansi_pref("ls otherFiles");
  colors = ([ "!d" : colord, "!c" : colorc, "!h" : colorh, "!o" : coloro, "!!" : NORM ]);
  

  j = 2 + 3 * flag_date;

  for (i = 0, k = 0; i < siz; i += j, k++)
  {
    string filecolor, loaded;
    
    /* It's a directory */
    if (file_info[i+1] == -2)
    {
      filecolor = (colord ? "@" : "");
      names[k] = "   ";
      total_dirs++;
      loaded = " ";
      file_info[i] = sprintf("%s/", file_info[i]);
    }
    else /* It's a file */
    {
      switch(file_info[i][<2..])
      {
        case ".c" : filecolor = (colorc ? "~" : ""); break;
        case ".h" : filecolor = (colorh ? "`" : ""); break;
        default:    filecolor = (coloro ? "^" : "");
      }
      
      loaded = (objectp(find_object(paths[k])) ? "*" : " ");
      total_files++;
      temp_size = file_info[i+1] / 1024 + (file_info[i+1] % 1024 > 512);
      total_size += file_info[i+1];
      
      if (!temp_size) 
        temp_size = 1;
        
      names[k] = sprintf("%3d", temp_size);
    }
    
    if (flag_date) 
      names[k] = sprintf("%s, %s %s", ctime(file_info[i+2]), 
                                      ctime(file_info[i+3]), names[k]);
      
    names[k] = sprintf("%s%s", names[k], loaded);
//  names[k] = sprintf("%s%^%s%^%s%^%s%^", names[k], filecolor, file_info[i], 
//    (filecolor != "" ? "!!" : "!="));
    names[k] = sprintf("%s%s%s%s", names[k], filecolor, file_info[i], 
      (filecolor != "" ? "!" : ""));
  }
  
  /* There's some way i can get this working, fuggit for now
  paths = copy(names);
  alltext = sprintf("%-*#s\n", width, implode(names, "\n"));
  write(terminal_colour(alltext, colors));
  printf("%-*#s\n", width, terminal_colour(implode(names, "\n"), colors));
  */
  
  alltext = sprintf("%-*#s\n", width, implode(names, "\n"));
  alltext = implode(explode(alltext, "!"), NORM);
  if (stringp(colord) && colord != "") alltext = implode(explode(alltext, "@"), colord);
  if (stringp(colorc) && colorc != "") alltext = implode(explode(alltext, "~"), colorc);
  if (stringp(colorh) && colorh != "") alltext = implode(explode(alltext, "`"), colorh);
  if (stringp(coloro) && coloro != "") alltext = implode(explode(alltext, "^"), coloro);
  write(alltext);
  total_size = total_size / 1024 + (total_size % 1024 > 512);

  printf("\t%d dirs, %d files, %d KB\n", total_dirs, total_files, total_size);
  return 1;
}

       
