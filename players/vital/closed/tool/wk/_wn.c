#include "/obj/security.h"
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  if(!str) { tail("/players/vital/logs/notes.log"); return 1; }
  else
  write_file("/players/vital/logs/notes.log", ctime(time()) + " " + RED +
    "-->" + NORM + " " + str + "\n");
  write(HIB+"Note completed."+NORM+"\n");
  return 1;
}



string
get_help()
{
  string help;
  help = "Create a note in ~logs/notes.log";
  return help;
}
