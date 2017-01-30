#include <ansi.h>
#define AllowedExtensions ({ "c", "h" })
#define MAX_BACKUPS       5
#define CMD_DEBUG_MODE    1

string
convert_time()
{
    int m;

    switch(ctime()[4..6])
    {
      case "Jan": m = 1; break;
      case "Feb": m = 2; break;
      case "Mar": m = 3; break;
      case "Apr": m = 4; break;
      case "May": m = 5; break;
      case "Jun": m = 6; break;
      case "Jul": m = 7; break;
      case "Aug": m = 8; break;
      case "Sep": m = 9; break;
      case "Oct": m = 10; break;
      case "Nov": m = 11; break;
      case "Dec": m = 12; break;
    }

    return ("" + m + "." + ctime()[8..9] + "." + ctime()[22..23]);
}

status
main(string arg)
{
    int s, c, i;
    string file, heh, x, root_dir, extension, backup, dstamp;

    if(!arg)
    { 
      notify_fail("Backup what file?\n");
      return 0;
    }
#ifdef CMD_DEBUG_MODE
    write("INITIAL ARG: " + arg + "\n");
#endif

    if(arg[0] != '/')
#ifdef CMD_DEBUG_MODE
    write("arg[0] != '/'. adding /.\n");
#endif
      arg = (string)this_player()->get_path() + arg;
#ifdef CMD_DEBUG_MODE
    write("After arg[0] -> " + arg + "\n");
#endif

    if(((s = strlen(arg)) >= 2) &&
       arg[s-2] != '.')
      arg += ".c";

#ifdef CMD_DEBUG_MODE
    write("Final arg: " + arg + "\n");
#endif

    if(!exists(arg))
    {
      notify_fail("File does not exist...\n");
      return 0;
    }

    dstamp = convert_time();
    c = 1;
    i = 1;

    if(sscanf(arg, "%s.%s", file, extension) == 2 &&
       member_array(extension, AllowedExtensions) != -1)
      while(i < (MAX_BACKUPS + 1) && c)
        c = exists(x = (file + "." + dstamp + "." + i++));
    
#ifdef CMD_DEBUG_MODE
    write("x: " + x + "\n");
#endif
    cp(arg, x);
    write("Backup complete.\n");
    return 1;
}

get_help()
{
  string help;
  help = "Syntax: backup <file>";
  return help;
}