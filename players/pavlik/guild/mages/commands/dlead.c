#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("dlead");
  set_name("Donations Leaders");
  set_color_name(HIC+"Donation Leaders"+NORM);
  set_rank(1);
  set_descrip(
	"Mages are encouraged to make donations to the guild. " +
	"A guild member earns donation points when the deposit " +
	"money or objects into the guild vault. " +
	"Mages with high donation points may receive special guild bonuses\n" +
	"Use the 'dlead' command to view donation point totals " +
	"of all guild members currently on-line.\n"
  );
}


cmd(str)
{
  DONATOR->donations();
  return 1;
}
