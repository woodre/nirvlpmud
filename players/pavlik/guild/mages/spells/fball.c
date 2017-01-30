#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("fball");
  set_name("FireBall");
  set_color_name(HIR+"Fire"+NORM+CYN+"Ball"+NORM);
  set_level(5);
  set_school("conjuration");
  set_stat("intelligence");
  set_type("damage");
  set_sp_cost(FBALL_COST);
  set_cost_string(FBALL_COST + " sp");
  set_descrip(
	"Conjure a fire blast to attack all present enemies.\n"
  );
}


spell()
{
  object *targets;
  object ob;
  string obname;
  int num_of_targets;
  int i;
  int dmg;

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+"'s spell fizzles.\n");
	tp->add_spell_point(-25);
	return 1;
  }

  write("A fireball explodes across the room.\n");
  say("A fireball explodes across the room.\n");

  targets = get_targets();
  if(!targets || !sizeof(targets))
	targets = ({});

  num_of_targets = sizeof(targets);

  if(tp->query_level() > WIZLEVEL)
	write("fireball:  total_damage="+FBALL_TOTAL_DAMAGE+"   targets="+num_of_targets+"\n");

  if(num_of_targets <= 0)
  {
	write("Your spell makes alot of light and noise, but otherwise has no effect.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  ob = all_inventory(env);
  i = sizeof(ob);
  while(i--)
  {
	if(ob[i] == tp)
	{
		tell_room(env,
		  ME+" stands "+HIY+"untouched"+NORM+" in the midst of the "+RED+"explosion"+NORM+".\n",
		  ({tp}));
		write("You stand "+HIY+"untouched"+NORM+" in the midst of the "+RED+"explosion"+NORM+".\n");
		continue;
	}

	/* non-living things in the room can be destroyed */
	if(!living(ob[i]))
	{
		if(ob[i]->get() && !random(2))
		{
			tell_room(env,
			  ob[i]->short()+" is "+HIR+"~@ INCINERATED @~"+NORM+" by the blast!\n");
			destruct(ob[i]);
			continue;
		}
		else
			continue;
	}

	obname = ob[i]->query_name();
	if(obname) obname = capitalize(obname);
	else obname = "Someone";

	if(member_array(ob[i], targets) == -1)
	{
		tell_room(env,
		  obname+" "+CYN+"dives"+NORM+" out of the way and "+
		  HIC+"narrowly avoids"+NORM+" the blast!\n");
	}
	else
	{
		dmg = random(FBALL_TOTAL_DAMAGE / num_of_targets);
		if(dmg > 50) dmg = 50;
		if(dmg <= 5)
			tell_room(env,
			  obname+" is "+RED+"singed"+NORM+" by the blast.\n");
		else if(dmg <= 15)
			tell_room(env,
			  obname+" is "+HIR+"~"+NORM+RED+"burned"+HIR+"~"+NORM+" by the blast!\n");
		else if(dmg <= 25)
			tell_room(env,
			  obname+" is "+HIR+"~~"+NORM+RED+"charred"+HIR+"~~"+NORM+" by the blast!\n");
		else
			tell_room(env,
			  obname+" is "+HIR+"~~~"+NORM+RED+"scorched"+HIR+"~~~"+NORM+" by the blast.\n");

		ob[i]->do_damage(({dmg}), ({"other|fire"}));

		if(ob[i] && !ob[i]->query_attack())
			ob[i]->attack_object(tp);
	}
  }

  tp->add_spell_point(-query_sp_cost());
  return 1;

}


/*
 * generate list of targets that will be taking damage
 */
get_targets()
{
  object *targs;
  object ob;
  int i;

  targs = ({});

  ob = all_inventory(env);
  i = sizeof(ob);
  while(i--)
  {
	if(ob[i] == tp)
		continue;

	if(!living(ob[i]))
		continue;

	if(ob[i]->query_attack() == tp || tp->query_attack() == ob[i])
	{
		targs += ({ ob[i] });
		continue;
	}

	/* don't hit players, kids, or pets (unless they are attacking us) */
	if(ob[i]->is_player() || ob[i]->is_pet() || ob[i]->is_kid() || ob[i]->query_owner())
		continue;

	/* everything else is fair game */
	targs += ({ ob[i] });
  }
  return targs;
}

