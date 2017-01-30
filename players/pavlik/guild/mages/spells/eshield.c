#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("eshield");
  set_name("Energy Shield");
  set_color_name(HIY+"Energy "+HIB+"Shield"+NORM);
  set_level(3);
  set_school("evocation");
  set_stat("intelligence");
  set_type("protection");
  set_component_id(ESHIELD_COMPONENT_ID);
  set_component_string("Onyx Powder");
  set_sp_cost(ESHIELD_COST);
  set_cost_string(ESHIELD_COST + " sp + Onyx Powder");
  set_descrip(
	"Use the powers of magic to create a protective barrier " +
	"around yourself or another player.  The energy shield will " +
	"absorb damage in combat and has a varying life span\n"
  );
}


spell(str)
{
  object ob, obj;

  if(!str)
	obj = tp;
  else
	obj = present(str, env);

  if(!obj)
  {
	notify_fail("Cast an Energy Shield over who?\n");
	return 0;
  }

  if(!obj->is_player())
  {
	notify_fail("Energy Shield may only be cast on players.\n");
	return 0;
  }

  if(present("energy_shield_obj", obj))
  {
	if(obj == tp)
		notify_fail("You already have a shield.\n");
	else
		notify_fail(capitalize(str)+" is already protected by an Energy Shield.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  write("You cast an " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" casts a spell, but nothing happens.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  say(ME+" recites the "+CYN+"ancient"+NORM+" words of a "+CYN+"powerful spell"+NORM+".\n");
  tell_room(env,
    "A "+HIY+"shooting star"+NORM+" "+MAG+"streaks"+NORM+" across the clear sky ...\n"+
    "   ...The air around you "+HIG+"tingles"+NORM+" with "+HIY+"unknown energy"+NORM+" ...\n"+
    "       A "+HIB+"crackling energy shield"+NORM+" appears around "+IT+".\n");
  tell_object(obj, CYN+"You are now surrounded by a magical energy shield.\n"+NORM);

  ob = clone_object(OBJ_DIR + "energy_shield");
  move_object(ob, obj);
  ob->set_shield_amount(ESHIELD_SHIELD_AMOUNT);
  ob->set_max_hits(ESHIELD_MAX_HITS);
  ob->start();

  tp->add_spell_point(-(query_sp_cost()));

  if(obj == tp)
	guild->add_spell_object("eshield", ob);

  if(present(component_id, tp))
	destruct(present(component_id, tp));

  return 1;
}

