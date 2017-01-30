#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("werelite");
  set_name("Werelite");
  set_color_name(HIY+"Werelite"+NORM);
  set_level(1);
  set_school("conjuration");
  set_sp_cost(WERELITE_COST);
  set_cost_string(WERELITE_COST + " sp");
  set_descrip(
	"Create a magical orb of light.\n"
  );
}

spell()
{
  object ob, obj;

  if(!spell_cast())
	return 0;

  write(
   "You weave the powers of magic and a mystical "+HIY+"werelite"+NORM+" appears in your hand!\n");

  say(
   ME+" weaves the powers of magic and a mystical "+HIY+"werelite"+NORM+" appears!\n");

  ob = clone_object(OBJ_DIR + "werelite");
  move_object(ob, tp);
  command("rub light", tp);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}

