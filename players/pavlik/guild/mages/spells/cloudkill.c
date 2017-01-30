#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("cloudkill");
  set_name("Cloudkill");
  set_color_name(HIW+"Cloud"+RED+"Kill"+NORM);
  set_level(7);
  set_school("conjuration");
  set_stat("power");
  set_type("damage");
  set_combat_spell(1);
  set_sp_cost(CLOUDKILL_COST);
  set_cost_string(CLOUDKILL_COST+" sp");
  set_descrip(
	"Conjure a cloud of toxic fumes that will choke your enemies.  Your enemies "+
	"will suffer damage and be unable to attack while the spell lasts.  This spell "+
	"affects an entire room, however not everything may suffer damage from this spell.\n"
  );
}


spell()
{
  object obj;
  int dmg;

  if(present("cloudkill", env))
  {
	notify_fail("This spell cannot be cast here right now.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  if(!present("mage_casting_object", tp) && tp->query_sp() < 100)
  {
	notify_fail("You are too weak to cast this spell right now.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-25);
	return 1;
  }

  if(present("mage_casting_object", tp))
  {
	dmg = CLOUDKILL_MAX_DAMAGE;
  }
  else
  {
	dmg = guild->query_total_guild_stat("conjuration") * 2;
	dmg += guild->query_total_guild_stat(query_stat());
	if(dmg > CLOUDKILL_MAX_DAMAGE) dmg = CLOUDKILL_MAX_DAMAGE;
  }

  write(
    "A deadly cloud of "+GRN+"noxious "+YEL+"fumes"+NORM+" appears!\n");
  say(
    ME+" casts a spell and a deadly cloud of "+GRN+"noxious "+YEL+"fumes"+NORM+" appears!\n");

  if(tp->query_level() > WIZLEVEL)
	write("cloudkill start: total_damage="+dmg+"\n");

  obj = clone_object(OBJ_DIR + "cloudkill");
  move_object(obj, env);
  obj->set_owner(tp);
  obj->set_total_damage(dmg);

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-query_sp_cost());

  return 1;

}

