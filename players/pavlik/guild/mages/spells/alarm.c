#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/spell_costs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

reset(arg) {
  if(arg) return;
  set_verb("alarm");
  set_name("Alarm");
  set_color_name(MAG+"Alarm"+NORM);
  set_level(3);
  set_school("enchantment");
  set_sp_cost(ALARM_COST);
  set_cost_string(ALARM_COST +" sp");
  set_descrip(
	"Create a magic glyph that will warn you anytime someone enters the room where the glyph "+
	"has been cast.\n"+
	"Use 'alarm location' to see where your alarm spell has been cast\n"+
	"Use 'alarm dispell' to remove an existing alarm."
  );
}


spell(str)
{
  object obj;

  if(str == "location")
  {
	obj = guild->query_guild_var("alarm");
	if(!obj)
	{
		notify_fail("You do not have an alarm set.\n");
		return 0;
	}
	if(!environment(obj))
	{
		notify_fail("Something has gone amiss with your alarm spell.\n");
		guild->unset_guild_var("alarm");
		destruct(obj);
		return 0;
	}
	write("Alarm Location: "+environment(obj)->short()+"\n");
	return 1;
  }
  else if(str == "dispell" || str == "dismiss")
  {
	obj = guild->query_guild_var("alarm");
	if(!obj)
	{
		notify_fail("You do not have an alarm set.\n");
		return 0;
	}
	write("You end the "+query_color_name()+" spell.\n");
	write("- Your alarm his been dispelled.\n");
	guild->unset_guild_var("alarm");
	destruct(obj);
	return 1;
  }
  else if(guild->query_guild_var("alarm"))
  {
	notify_fail(
	 "You already have an Alarm glyph.\n" +
	 "Use 'alarm dispell' to remove your existing alarm.\n");
	return 0;
  }
  else {
	write(
	 "You cast an " + query_color_name() + " spell ... \n" +
	 "You trace a "+YEL+"magical rune"+NORM+" on the ground.\n" +
	 "The enchanted symbol "+HIY+"glows brightly"+NORM+".\n");
	say(
	 ME + " traces a magical symbol on the ground.\n" +
	 "The magical rune "+HIY+"glows brightly"+NORM+".\n");

	obj = clone_object(OBJ_DIR + "alarm.c");
	obj->set_owner(tp->query_real_name());
	move_object(obj, env);
	guild->set_guild_var("alarm", obj);
	tp->add_spell_point(-(query_sp_cost()));
	return 1;
  }

}
