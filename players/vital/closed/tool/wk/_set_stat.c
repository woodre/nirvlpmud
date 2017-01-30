/* sets stat y to number z on player x */
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  string who, stat; int num; object freak;
  if(!str || sscanf(str,"%s %s %d",who,stat,num) != 3)
  {
    notify_fail("Syntax: 'set_stat <who> <stat> <num>'\n");
    return 0;
  }
  freak = find_player(who);
  if(!freak)
  {
    notify_fail("Player not logged on.\n");
    return 0;
  }
  freak->set_attrib(stat,num);
  command("save",freak);
  write("You set " + BOLD + who + NORM + "'s " + BOLD + stat + NORM +
    " to " + BOLD + num + NORM + ".\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: set_stat <who> <stat> <number>";
  return help;
}
