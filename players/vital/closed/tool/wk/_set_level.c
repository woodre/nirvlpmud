/* sets a player's level */
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  string who, slev;
  int lev, xlev;
  object freak;
  if(!str || sscanf(str,"%s %s",who,slev) != 2)
  {
    notify_fail("Syntax: 'set_level <freak> <lev>'\n");
    return 0;
  }
  freak = find_player(who);
  if(!freak)
  {
    notify_fail("Freak not logged on.\n");
    return 0;
  }
  if(sscanf(slev, "%d+%d", lev, xlev) != 2)
    sscanf(slev, "%d", lev);
  if(lev) freak->set_level(lev);
  if(xlev) freak->set_extra_level(xlev);
  command("save",freak);
  write("\nYou adjusts " + freak->query_real_name() + " to the level of: " +
    BOLD + BLK + slev + NORM + "\n\n");
  return 1;
}

get_help()
{
  string help;
  help = "Set players level - Syntax: set_level <player> <level>[+<xlevel>]";
  return help;
}
