#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("lifesteal");
  set_name("Life Steal");
  set_color_name(HIW+"Life "+NORM+HIR+"Steal"+NORM);
  set_level(4);
  set_school("necromancy");
  set_sp_cost(LIFESTEAL_COST);
  set_cost_string(LIFESTEAL_COST+" + per round cost.");
  set_combat_spell(1);
  set_type("damage");
  set_descrip(
	"This dangerous spell will suck the life force from an enemy " +
	"and heal the spell-caster.  The spell creates a magic conduit " +
	"between two beings and life force is transferred through the " +
	"counduit.  Beware - a strong-willed opponent may be able to " +
	"reverse the flow and suck the life from the spell-caster!\n" +
	"\n" +
	"The spell costs 50 spell points to initiate and more spell " +
	"points are required each round to maintain the spell.\n"
  );
}


spell(str)
{
  object ob, obj;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  write("You cast a " + query_color_name() + " spell ...\n");
  say(ME+" casts a spell.\n");

  /* NOTE: no standard spell_fail */

  write(
    "A "+HIY+"blinding conduit"+NORM+" of "+HIW+"white energy"+NORM+" appears between you and "+IT+".\n" +
    "You feel extremely "+RED+"vulnerable"+NORM+" as the conduit "+HIW+"connects"+NORM+" your "+HIM+"souls"+NORM+" together...\n");
  say("A "+HIY+"blinding conduit"+NORM+" of "+HIW+"white energy"+NORM+" appears between "+ME+" and "+IT+".\n");

  ob = clone_object(OBJ_DIR + "life_steal");
  ob->set_owner(tp);
  ob->set_target(obj);
  move_object(ob, tp);
  guild->add_spell_object("lifesteal", ob);
  guild->set_casting(1);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}

