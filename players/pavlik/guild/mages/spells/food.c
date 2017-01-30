#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("food");
  set_name("Create Food");
  set_color_name(YEL+"Create "+NORM+BLU+"Food"+NORM);
  set_level(4);
  set_school("enchantment");
  set_stat("widom");
  set_component_id("corpse");
  set_component_string("corpse");
  set_sp_cost(FOOD_COST);
  set_cost_string(FOOD_COST + " sp + corpse");
  set_descrip(
	"This handy spell turns a foul corpse into a healthy meal.\n"
  );
}


spell()
{
  object obj;
  int heal, msg;

  if(!spell_cast())
	return 0;

  obj = present(query_component_id(), tp);
  if(!obj) obj = present(query_component_id(), env);
  if(!obj) return 0;    /* this shouldn't happen */

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell and "+YEL+"ruin"+NORM+" a perfectly good corpse.\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell and "+YEL+"ruins"+NORM+" a perfectly good corpse.\n");
	destruct(obj);
	return 1;
  }

  write(
    "You withdraw a "+MAG+"bubbling"+NORM+" concotion from your robes and "+HIW+"pour"+NORM+" it over the corpse.\n" +
    "The corpse "+YEL+"steams"+NORM+" and "+RED+"boils"+NORM+" until only a small cube remains.\n" +
    "You turn a miserable smelly "+GRN+"corpse"+NORM+" into a "+HIW+"healthy meal"+NORM+"!\n");
  say(
    ME+" withdraws a "+MAG+"bubbling"+NORM+" concoction from "+PO+" robes and pours it over a corpse.\n"+
    "The corpse "+YEL+"steams"+NORM+" and "+RED+"boils"+NORM+" until only a small cube remains.\n" +
    ME+" has turned the miserable smelly "+GRN+"corpse"+NORM+" into a "+HIW+"healthy meal"+NORM+"!\n");

  heal = obj->heal_value();
  destruct(obj);

  obj = clone_object(OBJ_DIR + "corpse_burger");
  move_object(obj, tp);
  obj->set_amount(heal * 4 / 3);
  tp->add_spell_point(-query_sp_cost());
  return 1;

}
