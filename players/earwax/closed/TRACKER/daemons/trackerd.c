/*
 *      File:                   /players/earwax/closed/TRACKER/daemons/trackerd.c
 *      Function:               Daemonize many of the tracker functions
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2004 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 10/19/05
 *      Notes:                  Just a simple daemon to take care of routine tasks.
 *      Change History:
 */

#include <security.h>
#include "../defs.h"

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
string
format_level(object ob)
{
  int lvl, xlvl;
  string level;

  lvl = (int)ob->query_level();
  level = (string)WAXFUNS->lalign(lvl,2);
  if (lvl == 19)
    if (xlvl = (int)ob->query_extra_level())
      level += "+"+xlvl;
  level = (string)WAXFUNS->lalign(level,6);
  return level;
}

string
format_date()
{
  string old, new;

  old = ctime();

  switch(old[4..6])
  {
    case "Jan" : new = "01"; break; 
    case "Feb" : new = "02"; break;
    case "Mar" : new = "03"; break;
    case "Apr" : new = "04"; break;
    case "May" : new = "05"; break;
    case "Jun" : new = "06"; break;
    case "Jul" : new = "07"; break;
    case "Aug" : new = "08"; break;
    case "Sep" : new = "09"; break;
    case "Oct" : new = "10"; break;
    case "Nov" : new = "11"; break; 
    case "Dec" : new = "12"; break;
  }
  
  new += "/" + old[8..9] + "/" + old[22..23] + " " + old[11..15];
  return (string)WAXFUNS->lalign(new,14);
}

string
format_guild(object ob)
{
  string name;

  name = (string)ob->query_guild_name();
  if (name == 0 || name == "0") name = "none";
  return capitalize(name);
}

int
get_base_points(object ob)
{
  int lvl, xlvl, points, modifier;
  object t;

  lvl = (int)ob->query_level();
  modifier = (lvl < 10 ? 0 : lvl);
  if (lvl == 19)
  {
    xlvl = (int)ob->query_extra_level();
    if (xlvl)
      modifier += 1 + ((int)ob->query_extra_level() / 10);
  }
  if (t = present(TRACKER_ID,ob))
    modifier += ((int)t->query_points() / 100);
  
  return modifier;
}
