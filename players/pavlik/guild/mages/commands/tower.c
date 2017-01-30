#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

#define SPELL_COST	15

reset(arg) {
  if(arg) return;
  set_verb("tower");
  set_name("Tower");
  set_color_name(HIC+"Tower"+NORM);
  set_rank(1);
  set_sp_cost(SPELL_COST);
  set_cost_string(SPELL_COST + " sp");
  set_descrip(
	"Return to the Mages Tower.  This command cannot be " +
	"used in Wizard areas.\n"
  );
}


cmd()
{

  if(!check_sp())
  {
	notify_fail("");
	return 0;
  }

  if(creator(env) == 0)
  {
	write(
	 "You speak a word of "+MAG+"magic"+NORM+" and disappear with a "+HIY+"POP!"+NORM+"\n" +
	 "You reappear at the top of the Mage's tower.\n");
	say(
	 ME+" whispers a word of "+MAG+"magic"+NORM+".\n" +
	 ME+" disappears with a "+HIY+"POP!"+NORM+"\n");

	move_object(tp, GUILD_HOME);
	tp->add_spell_point(-query_sp_cost());

	say(
	 ME+" steps out of "+HIY+"thin air"+NORM+" and appears before you.\n");

	command("look", tp);
	return 1;
  }
  else
  {
	notify_fail("You cannot do that here.\n");
	return 0;
  }
}

