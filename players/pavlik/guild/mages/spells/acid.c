#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("acid");
  set_name("Acid Arrow");
  set_color_name(GRN+"Acid "+YEL+"Arrow"+NORM);
  set_level(4);
  set_school("conjuration");
  set_stat("power");
  set_type("damage");
  set_sp_cost(0);
  set_cost_string("");
  set_combat_spell(1);
  set_component_id(ACID_COMPONENT_ID);
  set_component_string("Sulfur Powder");
  set_descrip(
	"Cast an arrow of deadly acid at your enemy.\n"
  );
}

query_dmg()
{
  if(present("mage_casting_object", tp))
	return 10 + random(100) / 10;
  else
	return ACID_DAMAGE;
}

query_sp_cost()
{
  if(present("mage_casting_object", tp))
	return 0;
  else
	return ACID_COST;
}

query_cost_string(){ return query_sp_cost() + " sp + Sulfur Powder"; }


spell()
{
  object ob, obj;
  int dmg, acid_dmg;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  if(present("acid_arrow", obj))
  {
	notify_fail("You cannot cast another "+query_color_name()+" spell on "+IT+" yet.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  write(
    "You "+MAG+"conjure"+NORM+" an arrow of "+YEL+"bubbling "+GRN+"acid"+NORM+" and cast it into "+IT+".\n" +
    "The arrow "+HIW+"thuds"+NORM+" into "+IT+"'s body and "+MAG+"splatters"+NORM+" it with "+GRN+"deadly acid"+NORM+"!\n");
  say(
    ME+" "+MAG+"conjures"+NORM+" an arrow of "+YEL+"bubbling "+GRN+"acid"+NORM+" and casts it into "+IT+".\n" +
    "The arrow "+HIW+"thuds"+NORM+" into "+IT+"'s body and "+MAG+"splatters"+NORM+" it with "+GRN+"deadly acid"+NORM+"!\n");

  ob = clone_object(OBJ_DIR + "acid_arrow");
  ob->set_target(obj);
  ob->set_owner(tp);

  if(present("mage_casting_object", tp))
	acid_dmg = 2 + random(100) / 3;
  else
	acid_dmg = 2 + random(guild->query_total_guild_stat("conjuration")) / 3;

  ob->set_acid_damage(acid_dmg);
  move_object(ob, obj);
  dmg = query_dmg();
  tell_damage(dmg, obj);
  obj->do_damage(({dmg}), ({"other|poison"}));

  if(!present("mage_casting_object", tp))
  {
	tp->add_spell_point(-(query_sp_cost()));
	if(present(component_id, tp))
		destruct(present(component_id, tp));
  }

  return 1;
}

