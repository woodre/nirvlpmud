#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("query");
  set_name("Query Health");
  set_color_name(GRN+"Query Health"+NORM);
  set_level(2);
  set_school("necromancy");
  set_sp_cost(QUERY_COST);
  set_cost_string(QUERY_COST + " sp");
  set_descrip(
        "Call upon the powers of necromancy to determine " +
        "the life force of a living thing.\n"
  );
}


spell(str)
{
  object obj;
  int failed, con;

  if(!str)
	obj = tp->query_attack();
  else
	obj = present(str, env);

  if(!obj)
  {
	notify_fail("That is not here.\n");
	return 0;
  }

  if(!living(obj))
  {
	notify_fail("You can only cast "+query_color_name()+" on living objects.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell ... \n");
  say(ME+" casts a spell.\n");

  if(spell_fail(level, school, stat))
	failed = 1;

  /* report of % health approved by Earwax, 11-2005 */
  con = (obj->query_hp() * 100) / obj->query_mhp();
  if(failed) con = con + (1+random(8));

  tell_room(env,
   "A "+RED+"ghostly apparition"+NORM+" rises from the ground and "+HIBLK+"passes through"+NORM+" "+IT+".\n");
  write("A hollow voice whispers in your ear: "+HIC+con+"%\n"+NORM);

  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
