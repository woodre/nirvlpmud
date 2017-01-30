#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("reveal");
  set_name("Reveal");
  set_color_name(HIM+"Reveal"+NORM);
  set_level(3);
  set_school("evocation");
  set_type("alteration");
  set_combat_spell(0);
  set_sp_cost(REVEAL_COST);
  set_cost_string(REVEAL_COST + " sp");
  set_descrip(
	"Reveal invisible players.\n"
  );
}


spell()
{
  object ob;
  int i, count;

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ...\n");

  if(spell_fail(level, school, stat))
  {
	write("You fail the spell.\n");
	say(ME+" casts a spell but nothing happens.\n");
	tp->add_spell_point(-15);
	return 1;
  }

  write("The air around you begins to waver.\n");
  say(ME+" casts a spell and the air around you begins to waver...\n");

  ob = all_inventory(env);
  count = 0;
  for(i=0; i<sizeof(ob); i++)
  {
	if(living(ob[i]) && ob[i]->query_invis() > 0 && ob[i] != tp &&
	  ob[i]->query_level() < WIZLEVEL)
	{
		ob[i]->visible();
		count++;
	}
  }
 
  if(count == 0)
	tell_room(env, "Nothing special seems to happen.\n");
  else
	write("Your spell revealed "+count+" invisible players.\n");

  tp->add_spell_point(-query_sp_cost());
  return 1;

}

