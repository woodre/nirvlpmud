#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define SJ YEL+"Soul "+NORM+CYN+"Jar"+NORM
#define MAX_VALUE	50

reset(arg) {
  if(arg) return;
  set_verb("soultrap");
  set_name("Soul Trap");
  set_color_name(YEL+"Soul "+NORM+CYN+"Trap"+NORM);
  set_level(5);
  set_school("necromancy");
  set_stat("power");
  set_component_id("corpse");
  set_component_string("corpse");
  set_sp_cost(SOULTRAP_COST);
  set_cost_string("None");
  set_descrip(
	"Use this spell to capture the soul of a recently slain enemy.  This spell "+
	"will capture the soul into a special container which can later be used "+
	"to attack another opponent.\n"
  );
}


spell()
{
  object ob, obj;

  if(!spell_cast())
	return 0;

  obj = present(query_component_id(), tp);
  if(!obj) obj = present(query_component_id(), env);
  if(!obj) return 0;    /* this shouldn't happen */

  /* make sure the corpse is still "fresh" */
  if(obj->query_decay() < 75)
  {
	notify_fail("The soul has already "+HIM+"escaped"+NORM+" and only an "+CYN+"empty"+NORM+" corpse remains.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell and the corpse crumbles to dust.\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell and a corpse crumbles to dust.\n");
	destruct(obj);
	return 1;
  }

  if(!(ob = present("mage_soul_jar", tp)))
  {
	ob = clone_object(OBJ_DIR + "soultrap");
	move_object(ob, tp);
  }

  write(
    "You withdraw a plain glass jar from one of your various pouches of spell components.\n" +
    "With a deft movement you unscrew the lid and "+HIR+"ensnare"+NORM+" the "+YEL+"soul of "+IT+NORM+"!\n");
  say(
    ME+" takes a plain glass jar from one of "+PO+" various pouches of spell components.\n" +
    "With a deft movement "+ME+" unscrews the lid and "+HIR+"ensnares"+NORM+" the "+YEL+"soul of "+IT+NORM+"!\n");
  tell_room(env,
    IT+"'s "+YEL+"soul"+NORM+" tries "+RED+"vainly"+NORM+" to escape, but "+ME+" tucks the "+SJ+" safely away.\n");

  ob->add_soul_value(obj->heal_value());
  ob->set_owner(tp->query_real_name());

  if(ob->query_soul_value() >= MAX_VALUE)
	write("The "+YEL+"Soul"+" "+CYN+"Jar"+NORM+" is now full.\n");

  destruct(obj);
  return 1;

}
