#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("ctouch");
  set_name("Chill Touch");
  set_color_name(BLU+"Chill Touch"+NORM);
  set_level(1);
  set_school("necromancy");
  set_stat("will power");
  set_type("damage");
  set_combat_spell(1);
  set_descrip(
	"Strike your enemies with chilling magic from beyond the grave.\n"
  );
}

query_sp_cost()	{ return CTOUCH_COST; }
query_cost_string(){ return CTOUCH_COST + " sp"; }

query_dmg()
{
  if(present("mage_casting_object", tp))
	return 10 + random(100) / 3;
  else
	return CTOUCH_DAMAGE;
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
	tp->add_spell_point(-5);
	return 1;
  }

  obj = tp->query_attack();

  r = random(3);
  if(r== 0)
  {
	write(
	 "You reach out and "+HIM+"grasp"+NORM+" "+IT+"'s body - "+IT+" "+HIC+"cries in pain"+NORM+"!\n");
	say(
	 ME+" reaches out and "+HIM+"grasps"+NORM+" "+IT+"'s body - "+IT+" "+HIC+"cries in pain"+NORM+"!\n");
  }
  if(r == 1)
  {
	write(
	 "You reach out and "+BLU+"SHOCK"+NORM+" "+IT+" with a "+HIBLK+"deathly touch"+NORM+"!\n" +
	 IT+" trembles in "+BLU+"uncontrollable terror"+NORM+"!\n");
	say(
	 ME+" reaches out and "+BLU+"SHOCKS"+NORM+" "+IT+" with a "+HIBLK+"deathly touch"+NORM+"!\n" +
	 IT+" trembles in "+BLU+"uncontrollable terror"+NORM+"!\n");
  }
  if(r == 2)
  {
	write(
	 "You call upon powers from "+HIBLK+"beyond the grave"+NORM+" and strike "+IT+" with a "+BLU+"Chilling Touch"+NORM+"!\n");
	say(
	 ME+" calls upon powers from "+HIBLK+"beyond the grave"+NORM+" and strikes "+IT+" with a "+BLU+"Chilling Touch"+NORM+"!\n");
  }

  dmg = query_dmg();

  if(!present("mage_casting_object", tp))
	tp->add_spell_point(-(query_sp_cost()));

  tell_damage(dmg, obj);
  obj->do_damage(({dmg}), ({"other|evil"}));
  tp->add_alignment(-(random(5)));
  return 1;

}
