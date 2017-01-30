#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("detox");
  set_name("Detoxification");
  set_color_name(HIB+"Detoxification"+NORM);
  set_level(4);
  set_school("evocation");
  set_stat("will power");
  set_type("heal");
  set_sp_cost(DETOX_COST);
  set_cost_string(DETOX_COST + " sp");
  set_descrip(
	"Use the powers of magic to re-equalize your body.  This spell " +
	"will lower your alchohol, food and soak levels.\n"
  );
}


spell()
{
  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	write(
	  "You "+HIR+"miscast"+NORM+" the spell!\n" +
	  "Your head feels "+HIM+"fuzzy"+NORM+" and "+HIG+"wave of nausea"+NORM+" sweeps over you.\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell!\n");
        tp->drink_alcohol(5);
        tp->eat_food(10);
        tp->drink_soft(10);
        tp->add_spell_point(-(query_sp_cost()/2));
        return 1;
  }

  write("You use the powers of "+HIM+"magic"+NORM+" to "+HIC+"equalize"+NORM+" your body.\n");
  say(ME+" casts a "+HIC+"spell"+NORM+" and "+HIM+"equalizes"+NORM+" "+PO+" body.\n");
  tp->drink_alcohol(-(2 + guild->query_total_guild_stat("evocation")/12));
  tp->eat_food(-(2 + guild->query_total_guild_stat("evocation")/12));
  tp->drink_soft(-(2 + guild->query_total_guild_stat("evocation")/12));

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-(query_sp_cost()));

  return 1;
}

