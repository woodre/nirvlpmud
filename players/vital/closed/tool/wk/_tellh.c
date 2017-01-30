#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  object freak;
  if(!str) return 0;
  freak = find_player(str);
  if(!freak)
  {
    write("Freak not logged on.\n");
    return 1;
  }
  freak->write_tellhistory();
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: tellh <player>";
  return help;
}
