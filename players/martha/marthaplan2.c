#include "/obj/ansi.h"
/*define PLAN "/open/pub_plans/martha.plan"
*/
#define pub_plans "/open/pub_plans/martha.plan"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIC+"Areas\n"+NORM);
  write_file(PLAN, WHT+"Games Galore\n"+NORM);
  write_file(PLAN, HIM+"Candyland"+NORM+"......................"+MAG+"80% done\n"+NORM);
  write_file(PLAN, HIB+"Clue"+NORM+"..........................."+BLU+"5% done\n"+NORM);
  write_file(PLAN, HIR+"Monopoly"+NORM+"......................."+RED+"planning\n"+NORM);
  write_file(PLAN, WHT+"MusicaFestivus\n"+NORM);
  write_file(PLAN, HIG+"Stage One"+NORM+"......................"+GRN+"planning\n"+NORM);
  write_file(PLAN, HIY+"Stage Two"+NORM+"......................"+YEL+"planning\n"+NORM);
  write_file(PLAN, HIC+"Stage Three"+NORM+"...................."+CYN+"planning\n"+NORM);
  write_file(PLAN, WHT+"Moviemania\n"+NORM);
  write_file(PLAN, HIR+"Joe Dirt"+NORM+"......................."+RED+"planning\n"+NORM);
  write_file(PLAN, HIB+"Dude, Where's My Car?"+NORM+".........."+BLU+"planning\n"+NORM);
  write_file(PLAN, HIC+"Bubble Boy"+NORM+"....................."+CYN+"planning\n"+NORM);
  destruct(this_object());
}
