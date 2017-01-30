#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define ALTERATION_NUM	2

reset(arg) {
  if(arg) return;
  set_verb("ffire");
  set_name("Faerie Fire");
  set_color_name(HIY+"Faerie "+NORM+HIR+"Fire"+NORM);
  set_level(1);
  set_school("conjuration");
  set_stat("power");
  set_type("alteration");
  set_combat_spell(1);
  set_descrip(
	"Surround your enemy with a magical aura of light.  The aura " +
	"will make your enemy easier to see and therefore easier to hit!\n"
  );
}

query_sp_cost()	{ return FFIRE_COST; }
query_cost_string(){ return FFIRE_COST + " sp"; }


spell()
{
  object ob, obj;
  int x;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  /*
   * Don't exceed limit of 'alteration' spells in effect
   * NOTE: only one faerie fire can be in effect at a time
   */
  x = get_alteration_num(obj);

  if( (x >= MAX_ALTERATION_NUM) || (x + ALTERATION_NUM > MAX_ALTERATION_NUM) ||
      (present("faerie_fire", obj)) )
  {
	notify_fail("You cannot cast this spell on "+IT+" right now.\n");
	return 0;
  }

  write("You cast a " + query_color_name() +" spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" "+HIR+" miscasts"+NORM+" a spell.\n");
	tp->add_spell_point(-5);
	return 1;
  }

  write(
    "You conjure a glowing "+HIR+"faerie fire"+NORM+" around "+IT+"'s body!\n" +
    "The magic "+MAG+"aura"+NORM+" "+HIY+" shines brightly"+NORM+".\n" +
    IT+" has become a target that is "+HIW+"hard to miss!"+NORM+"\n");

  say(
    ME+" conjures a glowing "+HIR+"faerie fire"+NORM+" around "+IT+"'s body!\n"+
    "You can't seem to look away from the "+MAG+"magical aura"+NORM+".\n"+
    IT+" has become a target that is "+HIW+"hard to miss!"+NORM+"\n");

  ob = clone_object(OBJ_DIR + "faerie_fire");
  move_object(ob, obj);
  ob->do_spell(tp);
  guild->add_spell_object("ffire", ob);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
