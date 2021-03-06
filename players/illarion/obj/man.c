/* man
 *
 * Something to make finding info a little easier.
 *
 * -Earwax 5/20/04
 *
 * Modified by Illarion in Nov 2004
 *
 */

#define DATA "/doc/doc.tree"

#include <ansi.h>

#pragma weak_types

/* Global Variables */
mixed *Directories;
int Size_of_Dirs;
int Field_Size;

/*
 * cmd_man
 *
 * Search the directories, display results.
 *
*/

int cmd_man(string arg)
{
  int i, siz, count, dirs, files;
  string *t1, *t2;
  string filetext;

  write(HIK+"======================================================================\n"+NORM+NORM);
/*
  if (!Size_of_Dirs)
*/
  {
    write("Generating the directory list...\n");
    filetext = read_file(DATA);
    siz = sizeof(t1 = explode(filetext, "\n"));
    Size_of_Dirs = siz;
    Directories = allocate(siz);

    for (i = 0; i < siz; i++)
    {
      Directories[i] = allocate(2);
      sscanf(t1[i], "%s:%s", Directories[i][0], Directories[i][1]);
      write(Directories[i][1]+": "+file_size(Directories[i][1])+"\n");
      if (strlen(Directories[i][0]) > Field_Size)
        Field_Size = strlen(Directories[i][0]);
    }
  }
  return 1;
  count = dirs = files;
  t1 = ({ }); t2 = ({ });

  if (!arg)
  {
    write(CYN+"Directories in /doc: \n"+NORM+NORM);
    write(HIK+"======================================================================\n"+NORM+NORM);

    for (i = 0; i < Size_of_Dirs; i++)
    {
      write(pad("  "+Directories[i][0], Field_Size+2) + ": "+Directories[i][1]+"\n");
    }

    write(CYN+Size_of_Dirs+" total subdirectories.\n"+NORM+NORM);
    write(HIK+"======================================================================\n"+NORM+NORM);
    return 1;
  }

  i = strlen(arg) - 1;

/*
*/
  if (arg[i] == '/')
    arg = arg[0..(i - 1)];

  write(CYN+"Searching directories for: "+arg+".\n"+NORM+NORM);
  write(HIK+"======================================================================\n"+NORM+NORM);

  for (i = 0; i < Size_of_Dirs; i++)
  {
    if (member_array(arg, Directories[i]) > -1)
    {
      string *q;
      int j;

      dirs++;
      write("\t"+pad(Directories[i][0], Field_Size)+": "+Directories[i][1]+"\n");
      siz = sizeof(q = get_dir(Directories[i][1]));

      for (j = 0; j < siz; j++)
        t1 += ({ Directories[i][1] + q[j] });
    }

    if (file_size(Directories[i][1] + arg) > -1)
    {
      t2 += ({ Directories[i][1] + arg });
      files++;
    }
  }

  write(CYN+"\nSearching files for: "+arg+".\n"+NORM+NORM);
  files = sizeof(t1);

  for (i = 0; i < files; i++)
    write("\t"+t1[i] + "\n");

  write(CYN+(dirs + files)+" general matches ("+dirs+" directories and "+files+" files).\n"+NORM+NORM);
  files = sizeof(t2);

  write(CYN+"\nListing specific file matches:\n"+NORM+NORM);

  for (i = 0; i < files; i++)
    write("\t"+t2[i]+"\n");

  for (i = 0; i < files; i++)
  {
    write(HIK+"----------------------------------------------------------------------\n"+NORM+NORM);
    write(CYN+"Filename: "+t2[i]+"\n"+NORM+NORM);
    write(read_file(t2[i]));
  }

  write(HIK+"----------------------------------------------------------------------\n"+NORM+NORM);

  if (files)
    write(CYN+files+" specific file matches.\n"+NORM+NORM);

  write(HIK+"======================================================================\n"+NORM+NORM);
  return 1;
}
