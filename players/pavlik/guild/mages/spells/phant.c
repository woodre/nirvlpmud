#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define PHANTASM_COST		50
#define PHANTASM_COMPONENT_ID	"spider"

reset(arg) {
  if(arg) return;
  set_verb("phant");
  set_name("Phantasmagoria");
  set_color_name(MAG+"Phantasmagoria"+NORM);
  set_level(6);
  set_school("illusion");
  set_stat("power");
  set_type("damage");
  set_sp_cost(PHANTASM_COST);
  set_cost_string(PHANTASM_COST + " sp + Spider");
  set_component_id(PHANTASM_COMPONENT_ID);
  set_component_string("Spider");
  set_combat_spell(1);
  set_descrip(
	"Weave massive hallucinatory images into the mind of your opponent.\n"
  );
}


spell()
{
  object obj, ob;
  mixed dmg;
  
  if(!spell_cast())
	return 0;
	
	obj = tp->query_attack();
	
	if(present("phantasmagoria", obj))
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

write("\
You weave the "+HIBLK+"illusion"+NORM+" of "+
MAG+"Phantasmagoria"+NORM+" into the mind of "+obj->query_name()+".\n");
say(tp->query_name()+" weaves the "+HIBLK+"illusion"+NORM+" of "+
MAG+"Phantasmagoria"+NORM+" into the mind of "+obj->query_name()+".\n");

  ob = clone_object(OBJ_DIR+"phantasm");
  ob->set_target(obj);
  ob->set_owner(tp);

  if(present("mage_casting_object", tp))
	  dmg = 2 + random(100) / 2;
  else
	  dmg = 2 + random(guild->query_total_guild_stat("illusion")) / 2;
	
	move_object(ob, obj);
	
	ob->set_damage(dmg);
	
	tell_damage(dmg, obj);
	obj->do_damage(({dmg}),({"other|evil"}));
  
  if(!present("mage_casting_object", tp))
  {
	tp->add_spell_point(-(query_sp_cost()));
	if(present(component_id, tp))
		destruct(present(component_id, tp));
  }
  

  return 1;
}

