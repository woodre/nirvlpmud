#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("sdrain");
  set_name("Souldrain");
  set_color_name(HIM+"Soul"+HIK+"Drain"+NORM);
  set_level(4);
  set_school("evocation");
  set_stat("power");
  set_type("special");
  set_sp_cost(0);
  set_cost_string("");
  set_combat_spell(1);
  set_component_id("orb of souls");
  set_component_string("Orb of Souls");
  set_descrip(
	"Drain mana from an opponent.\n"
  );
}

query_sp_cost()
{
	return 0;
}

query_cost_string(){ return query_sp_cost() + " sp + Orb of Souls"; }


spell()
{
  object ob, obj;
  int dmg, acid_dmg;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-15);
	return 1;
  }
  
  if(!obj->is_player() || obj->query_sp() <= 0)
  {
    write("It has no effect.\n");
    return 1;
  }


write("You maliciously "+HIK+"drain"+NORM+" "+obj->query_name()+"'s "+HIC+"mana reserves"+NORM
+", sucking their very "+HIM+"soul"+NORM+".\n");

say(tp->query_name()+" maliciously "+HIK+"drains"+NORM+" "+obj->query_name()
+"'s "+HIC+"mana reserves"+NORM+", sucking their very "+HIM+"soul"+NORM+".\n");

  {
    int wil, intel;
    wil = (guild->query_total_guild_stat("will power") / 10);
    intel = (guild->query_total_guild_stat("intelligence") / 10);
   if(present("mage_casting_object", tp))
	  acid_dmg = 20 + random(10);
   else
	  acid_dmg = 10 + intel + random(wil);
  }
	
	tp->add_sp(acid_dmg);
	obj->add_sp(-acid_dmg);
	
	tp->spell_object(obj, "souldrain", 0, 0, "","","");

  if(!present("mage_casting_object", tp))
  {
	tp->add_spell_point(-(query_sp_cost()));
	if(present(component_id, tp))
		destruct(present(component_id, tp));
  }

  return 1;
}

