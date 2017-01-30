#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("sdagger");
  set_name("Shadow Dagger");
  set_color_name(HIBLK+"Shadow Dagger"+NORM);
  set_level(1);
  set_school("illusion");
  set_stat("intelligence");
  set_type("damage");
  set_sp_cost(SDAGGER_COST);
  set_cost_string(SDAGGER_COST + " sp + Silver Needle");
  set_component_id(SDAGGER_COMPONENT_ID);
  set_component_string("Silver Needle");
  set_combat_spell(1);
  set_descrip(
	"Create an illusionary attack so realistic that your enemy will think " +
	"that it's real and therefore suffer real damage.\n"
  );
}

query_dmg()
{
  if(present("mage_casting_object", tp))
	return 15 + random(100) / 5;
  else
	return SDAGGER_DAMAGE;
}


spell()
{
  object obj;
  int dmg;
  int r;

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-10);
	return 1;
  }

  obj = tp->query_attack();

  write(
    "You weave the "+HIBLK+"illusion"+NORM+" of a "+HIG+"swarm of daggers"+NORM+" speeding through the air at "+IT+".\n" +
    IT+" feels "+HIM+"real pain"+NORM+" as the illusionary daggers "+HIG+"pierce"+NORM+" "+obj->query_possessive()+" body!\n");
  say(
   ME+" waves the "+HIBLK+"illusion"+NORM+" of a "+HIG+"swarm of daggers"+NORM+" speeding through the air at "+IT+".\n" +
   IT+" feels "+HIM+"real pain"+NORM+" as the illusionary daggers "+HIG+"pierce"+NORM+" "+obj->query_possessive()+" body!\n");

  dmg = query_dmg();
  if(dmg > 50)
	dmg = 50;

  if(!present("mage_casting_object", tp))
  {
	tp->add_spell_point(-(query_sp_cost()));
	if(present(component_id, tp))
		destruct(present(component_id, tp));
  }

  tell_damage(dmg, obj);
  obj->do_damage(({dmg}), ({"other|evil"}));
  return 1;
}

