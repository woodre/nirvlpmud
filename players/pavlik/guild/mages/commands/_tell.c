#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("tell");
  set_name("Tell");
  set_color_name(HIC+"Tell"+NORM);
  set_rank(1);
  set_descrip(
	"Communicate with other player in the game.  Mage-tells " +
	"are more colorful than the standard tell\n"
  );
}


cmd(str)
{
  object ob;
  string who;
  string msg;

  if(tp->query_ghost())
  {
	notify_fail("You fail.\n");
	return 0;
  }

  if(!str || sscanf(str, "%s %s", who, msg) != 2)
  {
	notify_fail("Tell what?\n");
	return 0;
  }

  ob = find_player(lower_case(who));
  if (!ob) ob = find_living(lower_case(who));

  if(!ob)
  {
	notify_fail("No player with that name.\n");
	return 0;
  }

  if(interactive(ob))
  {
	if(tp->query_level() < ob->query_level() && ob->query_invis() >= 39)
	{
		notify_fail("No player with that name.\n");
		return 0;
	}
	if(tp->query_level() < 21 && in_editor(ob))
	{
		notify_fail("That person is editing. Please try again later.\n");
		return 0;
	}
	if(tp->query_level() < 21 && ob->query_tellblock())
	{
		notify_fail("That person is blocking all tells. Please try again later.\n");
		return 0;
	}
	if(tp->query_tellblock() && ob->query_level() < 21 && tp->query_level() < 21)
	{
		notify_fail("You cannot use tell when tellblock is on.\n");
		return 0;
	}
	if(query_idle(ob) > 120)
	{
		tell_object(tp, who+" is idle at the moment. You may not get a response right away.\n");
	}
  }

  if(!ob->query_npc() && !interactive(ob))
  {
	tell_object(tp, who+" is disconnected.\n");
  }

  if(call_other(tp,"query_invis",0) > 0 && tp->query_level() < 199)
  {
	notify_fail("Don't be annoying.  Become visible before you talk to someone!\n" );
	return 0;
  }

  msg = format(msg, 60);

  ob->Replyer((string)this_player()->query_real_name());
  ob->add_tellhistory(CYN+"~ "+ME+NORM+" told you: "+msg);
  write("You tell "+CYN+ capitalize(who) +NORM+": "+msg+"\n");
  tell_object(ob, CYN+"~ "+ME+NORM+" tells you: "+msg+"\n");

  return 1;

}
