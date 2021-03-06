/* ls(string PathAndPattern)
 *
 * Earwax 5/20/04
*/

/* for now... */


#include <ansi.h>
#include <security.h>

#define DIVISOR 1000
#define MAX_WIDTH 55
#define MAX_COLUMNS 5

#pragma weak_types
#pragma combine_strings

/* Prototypes */
status format_output(string path, string *files, int columns);

/* Global Variables */
mapping Completed; /* ([ Path : columns ]) to make it a little faster */

int
cmd_ls(string path)
{
  string a,b, pattern, output, c_color, h_color, dir_color, other_color;
  int size, mod, old;
  int i, siz, len, totalsize, ds, fs;
  string *files;
  mixed  *info;
  
  if(this_player()->query_level() < EXPLORE)
    return 0;

  if(path)
    if(sscanf(path,"-old %s",a)==1 || path == "-old") {path = a; old = 1;}
 
  if(!Completed) Completed = ([ ]);
  if (path == "clear")
  {
    path = (string)this_player()->query_pwd();
    Completed = m_delete(Completed, path);
  }

  if (!path || !strlen(path))
    path = (string)this_player()->query_pwd();

  if (sscanf(path, "clear %s", path) == 1 || sscanf(path, "%s clear", path) == 1)
    m_delete(Completed, path);

/* use old behavior to make wildcards work and when asked -Bp */

  if(sscanf(path,"%s*",a)==1 || sscanf(path,"*%s",a)==1 
     || sscanf(path,"%s*%s",a,b)==2 || old == 1) {
    string str;
    str = resolv_path((string)this_player()->get_path(), path);
    if (str == "/players") {
       write("You can't ls in /players.\n");
       return 1;
    }
    ls(str);
    return 1;
  }

  ds = fs = 0;
  path = resolve_path(path);
  pattern = "";
  len = strlen(path) - 1;

  /* Set default colors and retrieve any ansiprefs set. */
  c_color = (string)this_player()->get_ansi_pref("ls .c");
  h_color = (string)this_player()->get_ansi_pref("ls .h");
  dir_color = (string)this_player()->get_ansi_pref("ls directory");
  other_color = (string)this_player()->get_ansi_pref("ls otherFiles");
  if (!c_color) c_color = "";
  if (!h_color) h_color = "";
  if (!dir_color) dir_color = "";
  if (!other_color) other_color = "";

  if (path[len] == '/' && (text_contains(path,"*") || text_contains(path,".")))
    for (i = len; i >= 0; i--)
      if (path[i] == '/')
      {
        pattern = path[(i+1)..len];
        path = path[0..i];
        i = -1;
      }

  write("LS: "+path+pattern+"\n");
  if (path == "/players/")
  {
    write("You cannot ls in /players.\n");
    return 1;
  }

  if (file_size(path) > -2)
  {
    /* Use old behavior here. -Bp 
    write("Directory does not exist.\n");
    */
    ls(path);
    return 1;
  }

  siz = sizeof(files = get_dir(path+pattern));
  info = allocate(siz);
  totalsize = 0;

  for (i = 0; i < siz; i++)
  {
    info[i] = allocate(2);
    len = file_size(path+files[i]);

    if (len > -2)
    {
      fs++;
      files[i] = (find_object(path+files[i]) ? "*" : " ") + files[i];
      totalsize += len;
      size = len / DIVISOR;
      mod = len - (size * DIVISOR);
      len = (mod >= 500 ? (size+1) : size);
      len += (len == 0 ? 1 : 0);

      switch(len)
      {
        case 0..9 : files[i] =  "  "+len+files[i]; break;
        case 10..99 : files[i] =  " "+len+files[i]; break;
        case 100..999 : files[i] =  ""+len+files[i]; break;
        default : files[i] = files[i]; break;
      }

      len = strlen(files[i]) - 1;
      output = files[i][(len - 1)..len];
      
      switch(output)
      {
        case ".c" : files[i] = c_color + files[i]; break;
        case ".h" : files[i] = h_color + files[i]; break;
        default   : files[i] = other_color + files[i]; break;
      }

      info[i][0] = " " + files[i] + " " + NORM + NORM;
      info[i][1] = len + 3;
    }
    else
    {
      len = strlen(files[i]) + 7;
      ds++;
      info[i][0] = "     "+dir_color+files[i]+"/ "+NORM+NORM;
      info[i][1] = len;
    }
  }

  i = totalsize / DIVISOR;
  totalsize = i + (totalsize - (i * DIVISOR) >= 500 ? 1 : 0);

  if (!Completed)
    Completed = ([ ]);

  output = path+pattern;
  i = (member(Completed, output) ? Completed[output][0] : MAX_COLUMNS);

  if (!format_output(output, info, i))
  {
    output = "";
    siz = sizeof(files);

    for (i = 0; i < siz; i++)
      output += info[i][0]+"\n";

    write(output);
  }

  write("Size: "+totalsize+"   ("+fs+" Files, "+ds+" Directories)\n");
  return 1;
}


int
format_output(string path, mixed *files, int columns)
{

  int *max_width;
  int t, i, j, siz, rows, len, clen;
  string output;

  output = "";
  siz = sizeof(files);
  rows = siz / columns;
  rows += ((siz - (columns * rows)) ? 1 : 0);
  max_width = allocate(6);

  if (!member(Completed, path))
  {
    for (i = 0; i < rows; i++)
    {
      clen = 0;

      for (j = 0; j < columns; j++)
      {
        t = j * rows + i;
        if (t < siz)
        {
          len = files[t][1];
          max_width[j] = (len >= max_width[j] ? len : max_width[j]);
          clen += len;

          if (clen >= MAX_WIDTH)
            return (columns > 2 ? format_output(path, files, (columns - 1)) : 0);
        }
      }
    }

    Completed[path] = allocate(6);
    Completed[path][0] = columns;

    for (i = 0; i < 5; i++)
      Completed[path][(i + 1)] = max_width[i];
  }
  else
  {
    columns = Completed[path][0];
    max_width = Completed[path][1..5];
  }


  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < columns; j++)
    {
      t = j * rows + i;

      if (t < siz)
      {
        string pad;

        pad = "                                             "[0..(max_width[j] - files[t][1] )];
        write(files[t][0] + pad);
      }
    }

    write("\n");
  }

  return 1;
}
