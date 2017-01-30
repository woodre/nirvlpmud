/* reset's a players vital statistics [register/hb] */
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  object freak; int x;
  if(!str)
  {
    notify_fail("Syntax: 'plreset <player>'\n");
    return 0;
  }
  freak = find_player(str);
  if(!freak)
  {
    notify_fail("Freak not logged on.\n");
    return 0;
  }
  freak->set_heart_beat(1);
  if(freak->query_fight_area()) x = 1;
  freak->reset(1);
  if(x) freak->set_fight_area();
  freak->heart_beat();
  freak->recalc_carry();
  freak->recalc_quest();
  write("You reset "+CAP(str)+"'s heart beat, carry, and quest.\n");
  tell_object(freak,
    BOLD + "You begin to feel better almost immediately.\n" + NORM);
  return 1;
}

get_help()
{
  string help;
  help = "Reset hb, carry and quest. Syntax: plreset <player>";
  return help;
}
