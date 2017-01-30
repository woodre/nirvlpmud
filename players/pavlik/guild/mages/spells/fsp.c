#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("fsp");
  set_name("Flame Sphere");
  set_color_name(HIR+"Flame "+NORM+HIW+"Sphere"+NORM);
  set_level(2);
  set_school("enchantment");
  set_stat("intelligence");
  set_type("damage");
  set_sp_cost(FSP_COST);
  set_cost_string(FSP_COST + " sp");
  set_combat_spell(1);
  set_descrip(
	"Create a ball of magical fire to damage your enemy.\n" +
	"\n" +
	"This spell is cast in two parts.  The first 'fsp' command will initiate " +
	"the spell and begin the building of the flame sphere.\n" +
	"\n" +
	"The second time the command is used the flame sphere will be released.  The longer you " +
	"let the sphere build the more damage it will do.\n"
  );
}


spell()
{
  object ob;

  if(present("flame_sphere_obj", tp))
  {
	present("flame_sphere_obj", tp)->cast_spell();
	return 1;
  }

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

  write("You begin to gather a sphere of "+RED+"magical fire"+NORM+" in your hands.\n");
  say(ME+" casts a "+HIY+"spell"+NORM+" and begins to gather a sphere of "+RED+"magical fire"+NORM+".\n");

  ob = clone_object(OBJ_DIR + "flame_sphere");
  ob->set_owner(tp);
  ob->init_spell();
  move_object(ob, tp);
  guild->set_casting(1);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
