#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("cure");
  set_name("Cure Wounds");
  set_color_name(BLU+"Cure Wounds"+NORM);
  set_level(2);
  set_school("necromancy");
  set_stat("wisdom");
  set_sp_cost(CURE_COST);
  set_cost_string(CURE_COST + " sp");
  set_type("heal");
  set_descrip(
        "This spell of light curing can replenish the health " +
	"of the spell caster or another player.\n"
  );
}

query_heal_amount()
{
  if(present("mage_casting_object", tp))
	return 20 + random(100) / 5;
  else
	return CURE_AMOUNT;
}


spell(str)
{
  object ob, obj;
  int amount;

  if(!spell_cast())
	return 0;

  if(!str) obj = tp;
  else obj = present(str, env);

  if(!obj)
  {
	notify_fail(capitalize(str)+" is not present.\n");
	return 0;
  }

  if(obj == tp && (ob = shadow(obj, 0)))
  {
	if(ob->query_spell_name() == "augury")
	{
		notify_fail("You cannot cast a cure spell on yourself while "+HIG+"Augury"+NORM+" is cast.\n");
		return 0;
	}
  }

  write("You cast a " + query_color_name() +" spell ...\n");

  if(obj == tp)
	say(ME+ " speaks a word of magic and a soft "+BLU+"blue aura"+NORM+" encompasses "+PO+" body.\n");
  else
	say(ME+ " speaks a word of magic and a soft "+BLU+"blue aura"+NORM+" encompasses "+IT+".\n");

  tell_object(obj, "A soft blue aura encompasses your body.\n");

  if(spell_fail(level, school, stat))
  {
	say(
	  "Something goes wrong with the spell ... \n" +
	  "The blue aura turns to a "+HIR+"violent red!\n" +
	  IT+"'s body is racked with "+HIY+"agonizing pain"+NORM+"!\n" +
	  HIBLK+"The aura quickly fades away.\n"+NORM,
	  obj);
	tell_object(obj,
	  "Something goes wrong with the spell ... \n" +
	  "The blue aura turns to a "+HIR+"violent red"+NORM+"!\n" +
	  "Your body is racked with "+HIY+"agonizing pain"+NORM+"!\n" +
	  HIBLK+"Finally the aura "+HIBLK+"fades away.\n"+NORM);
	obj->hit_player(random(15));
	command("mon", obj);
	return 1;
  }

  tell_object(obj,
    "Soothing healing magic courses through your body.\n");
  tell_room(env,
    IT+"'s blue aura slowly fades away.\n");
  tell_object(obj, "You feel better.\n");

  amount = query_heal_amount();
  obj->add_hit_point(amount);

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-(query_sp_cost()));

  command("mon", obj);
  return 1;

}
