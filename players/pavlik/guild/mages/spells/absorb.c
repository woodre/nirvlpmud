#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("absorb");
  set_name("Absorbtion");
  set_color_name(HIC+"Absorbtion"+NORM);
  set_level(5);
  set_school("evocation");
  set_stat("wisdom");
  set_sp_cost(ABSORB_COST);
  set_cost_string(ABSORB_COST + " sp");
  set_type("alteration");
  set_descrip(
	"Using this spell the caster can draw on the magical forces " +
	"of his or her surroundings to enhance magic abilities.\n" +
	"The delay time for alteration does not start until the " +
	"absorbtion spell ends.\n"
  );
}


spell(str)
{
  object ob;
  string stat, *stats;
  int i, amount;

  if(!spell_cast())
	return 0;

  if(tp->query_attack())
  {
	notify_fail("You can't concentrate enough.\n");
	return 0;
  }

  if(present("absorb_obj", tp))
  {
	notify_fail("You cannot cast this spell again yet.\n");
	return 0;
  }

  write("You cast an " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  write(
    "You cast the "+query_color_name()+" spell and drawn on the magic of your surroundings.\n" +
    "The world around you comes alive with "+HIM+"magic"+NORM+" and you feel a "+HIC+"heightened"+NORM+" sense of control.\n");
  say(ME+" casts a spell and the air around you tingles with magic.\n");

  amount = ABSORB_AMOUNT;
  if(amount > ABSORB_MAX_AMOUNT) amount = ABSORB_MAX_AMOUNT;

  if(str && (str == "all" || str == "ALL") && tp->query_level() > WIZLEVEL)
  {
	write(HIC+"All"+NORM+" of your abilities increase!!! ...what a "+HIY+"rush!\n"+NORM);
	stat = "ALL";
  }
  else if(random(guild->query_total_guild_stat("evocation")) >= 82)
  {
	write(HIC+"All"+NORM+" of your abilities increase!!! ...what a "+HIY+"rush!\n"+NORM);
	stat = "ALL";
  }
  else
  {
	stats = SCHOOLS;
	i = sizeof(stats) - 1;
	stat = stats[random(i)];
  }

  /* bonus amount */
  ob = clone_object(OBJ_DIR + "absorbtion");
  ob->set_amount(amount);

  /* bonus guild "stat" */
  ob->set_stat(stat);

  /* bonus guild "attrib" */
  stats = STATS;
  stat = stats[random(sizeof(stats)-1)];
  ob->set_attrib(stat);

  ob->set_expire(guild->query_total_guild_stat("wisdom") * 3);
  move_object(ob, tp);
  ob->do_spell();
  guild->add_spell_object("absorb", ob);

  tp->add_spell_point(-query_sp_cost());
  return 1;

}

