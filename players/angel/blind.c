#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define ALTERATION_NUM	1

reset(arg) {
  if(arg) return;
  set_verb("blind");
  set_name("Blind");
  set_color_name(HIW+"Blind"+NORM);
  set_level(2);
  set_school("illusion");
  set_stat("will power");
  set_sp_cost(BLIND_COST);
  set_cost_string(BLIND_COST + " sp");
  set_combat_spell(1);
  set_type("alteration");
  set_descrip(
	"This spell strikes your enemy blind and reduces their " +
	"effectiveness in combat.  Several Mages can cast this spell " +
	"on the same target to increase effectiveness.\n"
  );
}


spell()
{
  object obj;
  object blind;

  object temp; /* added by mizan */
  int i, max;
  int x;

  if(!spell_cast())
	return 0;

  obj = tp->query_attack();

  if(obj->query_wc() <= 3)
  {
	notify_fail(IT+" is already helpless enough.\n");
	return 0;
  }

  /*
   * Don't exceed limit of 'alteration' spells in effect
   * NOTE: multiple blind spells can be cast on the same target,
   *       but only 1 blind per spell-caster.
   */
  x = get_alteration_num(obj);
  if( (x >= MAX_ALTERATION_NUM) || (x + ALTERATION_NUM > MAX_ALTERATION_NUM) ||
      (present("blind_obj", obj) && present("blind_obj", obj)->query_caster(tp->query_real_name())) )
  {
        notify_fail("You cannot cast this spell on "+IT+" right now.\n");
        return 0;
  }

  if(present("blind_obj", obj))
  {
	/* can't reduce targets wc by more than 17/24ths */
	if(obj->query_wc() <= present("blind_obj", obj)->query_min_wc())
	{
		notify_fail("Your spell would have no further affect on "+IT+".\n");
		return 0;
	}
  }

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" casts a spell, but nothing happens.\n");
	tp->add_spell_point(-10);
	return 1;
  }

  if(present("blind_obj", obj))
  {
	write(
	  "You cast another spell of "+HIW+"Blindness"+NORM+" over "+IT+"\n" +
	  "The "+HIBLK+"shroud of darkness"+NORM+" clouding "+IT+"'s eyes "+HIY+"intensifies!\n"+NORM);
	say(
	  ME+" casts another spell of "+HIW+"Blindess"+NORM+" over "+IT+"\n" +
	  "The "+HIBLK+"shroud of darkness"+NORM+" clouding "+IT+"'s eyes "+HIY+"intensifies!\n"+NORM);

	/* change by mizan, sort of a quick hack since players are dying to this spell repeatedly. */
	temp = present("blind_obj", obj);
	if(temp && is_living(obj)) call_other(temp, "do_spell");

	/* original code */
/*
	present("blind_obj", obj)->do_spell();
*/
  }
  else
  {
	write(
	  "A "+HIBLK+"shroud of darkness"+NORM+" deconds over "+IT+"!\n" +
	  IT+"'s eyes become "+HIW+"clouded"+NORM+" and "+obj->query_pronoun()+" begins to "+
	  HIY+"stumble about blindly"+NORM+"!\n");
	say(
	  ME+" casts a spell of "+HIW+"Blinding"+NORM+" and a "+HIBLK+"shroud of darkness"+NORM+
	  "descends over "+IT+"!\n" +
	  IT+"'s eyes become "+HIW+"clouded"+NORM+" and "+obj->query_pronoun()+" begins to "+
	  HIY+"stumble about blindly"+NORM+"!\n");

	blind = clone_object(OBJ_DIR + "blind");
	move_object(blind, obj);
	blind->do_spell();
  }

  guild->add_spell_object("blind", blind);
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
