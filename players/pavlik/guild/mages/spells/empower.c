#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("empower");
  set_name("Empower");
  set_color_name(HIM+"Empower"+NORM);
  set_level(2);
  set_school("evocation");
  set_stat("power");
  set_cost_string("special");
  set_descrip(
	"The Empower spell allows a Mage to transfer his " +
	"or her magical power (sp) to another person.\n" +
	"Some spell points may be lost during the transfer.\n"
  );
}


spell(str)
{
  object obj;
  string who;
  int amount;
  int cost;
  int xfer;

  if(!str || sscanf(str, "%s %d", who, amount) != 2)
  {
	notify_fail("Use: 'empower <who> <amt>'.\n");
	return 0;
  }

  if(!spell_cast())
	return 0;

  obj = find_player(who);
  if(!obj) obj = find_living(who);

  if(!obj)
  {
	notify_fail(capitalize(who)+" could not be located.\n");
	return 0;
  }

  if(obj == tp)
  {
	notify_fail("You can't empower yourself.\n");
	return 0;
  }

  if(!present(obj, env) && guild->query_total_guild_stat("evocation") < 50)
  {
	notify_fail(
	  "You are not powerful enough to Empower over distances yet.\n" +
	  "The recipient of your empowerment must be present.\n");
	return 0;
  }

  if((obj->is_player()) && (obj->query_level() > 19))
  {
	notify_fail("Wizard's don't need your help.\n");
	return 0;
  }

  if(amount < 10)
  {
	notify_fail("You must transfer at least 10 spell points.\n");
	return 0;
  }

  if(tp->query_sp() < 10)
  {
	notify_fail("You do not have enough magic to empower anyone.\n");
	return 0;
  }

  if((tp->query_sp() - amount) < -100)
  {
	notify_fail("You do not have enough magic to empower that amount.\n");
	return 0;
  }

  write("You cast an " + query_color_name() + " spell ... \n");

  if(spell_fail(level, school, stat))
  {
	write("You "+HIR+"miscast"+NORM+" the spell!\n");
	write("You suddenly feel "+HIG+"tired and weak"+NORM+".\n");
	say(ME+" "+HIR+"miscasts"+NORM+" a spell and now looks "+HIG+"tired and weak"+NORM+".\n");
	tp->add_spell_point(-(random(amount * 2)));
	return 1;
  }


  /* transfer cost is random 1-10% */
  cost = 10 - random(guild->query_total_guild_stat("power")/10);
  if(cost < 1) cost = 1;
  cost = amount * cost / 100;
  xfer = amount - cost;

  write(
    "You rejuvenate "+capitalize(who)+" with your own magic.\n"+
    "You "+HIM+"empower"+NORM+" "+capitalize(who)+" with "+HIC+xfer+NORM+" spell points.\n");
  tell_object(obj,
    "You feel rejuvenated as new magic runs through your veins!\n"+
    ME+" "+HIM+"empowered"+NORM+" you with "+HIC+xfer+NORM+" spell points.\n");

  obj->add_spell_point(xfer);
  tp->add_spell_point(-(amount + cost));
  return 1;

}
