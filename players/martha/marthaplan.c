#include "/obj/ansi.h"
/*define PLAN "/open/pub_plans/martha.plan"
*/
#define pub_plans "/open/pub_plans/martha.plan"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(pub_plans, HIC+"Areas\n"+NORM);
  write_file(pub_plans, WHT+"Games Galore\n"+NORM);
  write_file(pub_plans, HIM+"Candyland"+NORM+"......................"+MAG+"80% done\n"+NORM);
  write_file(pub_plans, HIB+"Clue"+NORM+"..........................."+BLU+"5% done\n"+NORM);
  write_file(pub_plans, HIR+"Monopoly"+NORM+"......................."+RED+"planning\n"+NORM);
  write_file(pub_plans, WHT+"MusicaFestivus\n"+NORM);
  write_file(pub_plans, HIG+"Stage One"+NORM+"......................"+GRN+"planning\n"+NORM);
  write_file(pub_plans, HIY+"Stage Two"+NORM+"......................"+YEL+"planning\n"+NORM);
  write_file(pub_plans, HIC+"Stage Three"+NORM+"...................."+CYN+"planning\n"+NORM);
  write_file(pub_plans, WHT+"Moviemania\n"+NORM);
  write_file(pub_plans, HIR+"Joe Dirt"+NORM+"......................."+RED+"planning\n"+NORM);
  write_file(pub_plans, HIB+"Dude, Where's My Car?"+NORM+".........."+BLU+"planning\n"+NORM);
  write_file(pub_plans, HIC+"Bubble Boy"+NORM+"....................."+CYN+"planning\n"+NORM);
  destruct(this_object());
}
