#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("mbag");
  set_name("Magic Bag");
  set_color_name(HIG+"Magic Bag"+NORM);
  set_level(2);
  set_school("enchantment");
  set_stat("will power");
  set_component_id("corpse");
  set_component_string("corpse");
  set_sp_cost(MBAG_COST);
  set_cost_string(MBAG_COST + " sp + " + query_component_string());
  set_descrip(
	"Call upon the powers of enchantment to turn a corpse into a magic bag.\n"
  );
}


spell()
{
  object obj;
  string name;

  if(!spell_cast())
	return 0;

  obj = present(query_component_id(), tp);
  if(!obj) obj = present(query_component_id(), env);
  if(!obj) return 0;	/* this shouldn't happen */

  write("You cast a " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell and "+RED+"ruin"+NORM+" a perfectly good corpse!\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell.\n");
	tp->add_spell_point(-5);
	destruct(obj);
	return 1;
  }

  name = obj->query_name();
  destruct(obj);
  obj = clone_object("players/pavlik/guild/mages/obj/corpse_bag");
  obj->set_name(name);
  move_object(obj, tp);

  tell_room(env,
  ME+" casts a "+GRN+"vile spell"+NORM+" and strips the flesh from a corpse!\n"+
  ME+" treats the hide with a "+MAG+"bubbling potion"+NORM+" and makes a bag!\n");
  write("You now have a Bag made from "+name+" hide!\n");
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
