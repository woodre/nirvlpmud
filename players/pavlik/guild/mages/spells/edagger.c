#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("edagger");
  set_name("Ethereal Dagger");
  set_color_name(HIBLK+"Ethereal "+NORM+MAG+"Dagger"+NORM);
  set_level(4);
  set_school("illusion");
  set_stat("will power");
  set_sp_cost(EDAGGER_COST);
  set_cost_string(EDAGGER_COST + " sp");
  set_descrip(
	"Create an illusionary weapon so realistic that everyone, " +
	"especially your enemies, will be fooled.  The Ethereal Dagger " +
	"is a temporary but effective weapon.\n"
  );
}


spell(str)
{
  object ob;
  int wc;
  int ttl;

  if(!spell_cast())
	return 0;

  if(present("ethereal dagger", tp))
  {
	notify_fail("You already have an ethereal dagger.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" "+HIR+" miscasts"+NORM+" a spell.\n");
	tp->add_spell_point(-35);
  }

  write("As the spell-casting completes a "+HIBLK+"wicked "+NORM+MAG+"dagger"+NORM+" appears out of "+HIC+"thin air"+NORM+".\n");
  say(ME+" casts a spell and a "+HIBLK+"wicked "+NORM+MAG+"dagger"+NORM+" appears out of "+HIC+"thin air"+NORM+"!\n");

  /* how long will the weapon list */
  ttl = 30 + random(guild->query_total_guild_stat("illusion")) + random(guild->query_total_guild_stat("will power"));

  /* weapon class */
  wc = 7 + guild->query_total_guild_stat("illusion") / 7;
  if(wc > EDAGGER_MAX_WC) wc = EDAGGER_MAX_WC;

  ob = clone_object(OBJ_DIR + "ethereal_dagger");
  ob->set_class(0);		/* we have no physical weapon class */
  ob->set_dmg(wc);		/* the real damage is done here */
  ob->set_ttl(ttl);
  move_object(ob, tp);

  ob->set_silentwield(1);
  call_other(ob, "wield", "ethereal dagger");
  write("You wield the "+ob->query_name()+".\n");
  say(ME+" wields an "+ob->query_name()+".\n");
  ob->set_silentwield(0);

  if(tp->query_level() > WIZLEVEL)
	write("edagger:  wc="+wc+"   ttl="+ttl+"\n");

  tp->add_spell_point(-(query_sp_cost()));
  return 1;
}

