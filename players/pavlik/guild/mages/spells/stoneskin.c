#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("stoneskin");
  set_name("Stone Skin");
  set_color_name(HIW+"Stone "+NORM+CYN+"Skin"+NORM);
  set_level(5);
  set_school("enchantment");
  set_sp_cost(STONESKIN_COST);
  set_cost_string(STONESKIN_COST + " sp + Granite Powder");
  set_component_id(STONESKIN_COMPONENT_ID);
  set_component_string("Granite Powder");
  set_type("protection");
  set_descrip(
	"Use this spell to magically harden your skin and protect yourself " +
	"against physical attacks.\n"
  );
}


spell()
{
  object ob;
  int ac;
  int expire;

  if(present("stone_skin", tp))
  {
	notify_fail("You are already protected by a "+query_color_name()+" spell.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  write(
    "You take some powered granite from your belt and sprinkle it over your skin.\n" +
    "The powder "+HIY+"tingles"+NORM+" on your skin as the "+HIM+"magic "+NORM+" takes hold.\n" +
    "You feel your skin "+HIW+"harden"+NORM+" into a "+HIC+"stone-like armor"+NORM+"!\n");

  say(
    ME+" takes some granite powder and sprinkles it over "+PO+" skin.\n" +
    ME+" casts a "+HIM+"magic spell"+NORM+" and "+PO+" skin hardens into an "+HIC+"armored shell"+NORM+"!\n");

  if(present("mage_casting_object", tp))
  {
	ac = 10;
	expire = 800;
  }
  else
  {
	ac = guild->query_total_guild_stat("enchantment") / 10;
	expire = guild->query_total_guild_stat("power") * 8;
  }

  ob = clone_object(OBJ_DIR + "stone_skin");
  ob->set_ac_amount(ac);
  ob->set_expire(expire);
  move_object(ob, tp);
  ob->do_spell();

  if(guild)
	guild->add_spell_object("stoneskin", ob);

  if(!present("mage_casting_object", tp))
  {
	tp->add_spell_point(-query_sp_cost());
	if(present(component_id, tp))
		destruct(present(component_id, tp));
  }

  return 1;
}

