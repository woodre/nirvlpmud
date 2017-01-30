#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("pacify");
  set_name("Pacify");
  set_color_name(YEL+"Pacify"+NORM);
  set_level(2);
  set_school("illusion");
  set_stat("wisdom");
  set_sp_cost(PACIFY_COST);
  set_cost_string(PACIFY_COST + " sp");
  set_type("protection");
  set_descrip(
	"This spell will bring peace to a room and stop all " +
	"combat.  Some monsters may be immune to this spell.\n"
  );
}


spell()
{
  object ob;
  int i, x;

  if(!spell_cast())
	return 0;

  write("You cast a " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"fail"+NORM+" the spell miserably.\n");
	say(ME+" "+HIR+"fails"+NORM+" a spell.\n");
	tp->add_spell_point(-(query_sp_cost()/2));
	return 1;
  }

  /* added by mizan on reports from fakir that this was being abused... */
  if(guild->query_cmd_count() && guild->query_cmd_count() > 1)
  {
/*
      write("DEBUG: Command count is " + guild->query_cmd_count() + "\n");
*/
      write(HIR+"You are too busy fighting!!\n"+NORM);
      say(ME+" "+HIR+"fails"+NORM+" a spell.\n");
      tp->add_spell_point(-(query_sp_cost()/3));
      return 1;
  }

  tell_room(env,
    "\n" +
    HIY+ME+" speaks a word of magic ... \n"+NORM+
    HIM+"Soothing"+NORM+" images float into your mind, "+HIY+"calming"+NORM+" you.\n"+
    "Your need for "+HIR+"bloodlust"+NORM+" temporarily "+HIM+"subsides"+NORM+".\n\n",
    ({tp}));


  ob = all_inventory(env);
  for(i=0; i<sizeof(ob); i++)
  {
	if(living(ob[i]) && ob[i]->query_attack())
	{
		ob[i]->stop_fight();
		ob[i]->stop_fight();
		ob[i]->stop_hunter();
		x++;
		if(ob[i] != tp)
			write(capitalize(ob[i]->query_name())+" falls under your "+query_color_name()+" spell.\n");
	}

  }

  write("Your spell "+HIW+"quiets"+NORM+" the room.\n");
  tp->add_spell_point(-(query_sp_cost()));
  return 1;

}
