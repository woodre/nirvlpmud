#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("msetstat");
  set_name("Set Mage Stat ");
  set_color_name(HIC+"Set Mage Stat"+NORM);
  set_rank(100);
  set_descrip(
	"The command will set a players guild stat.\n" +
	"Usage: msetstat <player> <stat> <#>\n" +
	"\n" +
	"This command is available only to mage council and wizards.\n" +
	"Use of this command is logged.\n"
  );
}


cmd(str)
{
  string name, stat;
  string *stats;
  int i, value;
  object obj;

  if(tp->query_level() < WIZLEVEL && tp->query_guild_rank() <= MAXGUILDRANK)
	return 0;

  if(!str)
  {
	notify_fail("Usage: msetstat <name> <stat> <#>\n");
	return 0;
  }

  if(sscanf(str, "%s %s %d", name, stat, value) != 3)
  {
	notify_fail("Usage: msetstat <name> <stat> <#>\n");
	return 0;
  }

  if(name == "self")
	obj = tp;
  else
	obj = find_player(name);

  if(!obj)
  {
	notify_fail("Could not find '"+name+"'.\n");
	return 0;
  }

  if(!present("mageobj", obj))
  {
	notify_fail(capitalize(name)+" does not have a mage guild object.\n");
	return 0;
  }

  if(stat == "will")
	stat = "will power";

  if(stat == "stats" || stat == "attribs")
  {
	if(tp->query_level() < WIZLEVEL)
	{
		notify_fail("Sorry, only wizards can do this.\n");
		return 0;
	}

	if(stat == "stats") stats = STATS;
	if(stat == "attribs") stats = SCHOOLS;
	for(i=0; i<sizeof(stats); i++)
	{
		set_stat(present("mageobj", obj), stats[i], value);
		write(CYN+"Mage Stat '"+stat+"' set to: "+value+".\n"+NORM);
	}
	return 1;
  }
  else if(stat == "train" || stat == "trains")
  {
	i = present("mageobj", obj)->query_training_sessions();
	if(i > 0) present("mageobj", obj)->add_training_sessions(-i);
	present("mageobj", obj)->add_training_sessions(value);
	write(CYN+"Training Sessions set to: "+value+".\n"+NORM);
	return 1;
  }
  else if(stat == "spell" || stat == "spells")
  {
	i = present("mageobj", obj)->query_new_spell_chances();
	if(i > 0) present("mageobj", obj)->add_new_spell_chances(-i);
	present("mageobj", obj)->add_new_spell_chances(value);
	write(CYN+"New Spell Chances: "+value+".\n"+NORM);
	return 1;
  }
  else
  {
	if(member_array(stat, STATS) == -1 && member_array(stat, SCHOOLS) == -1)
	{
		notify_fail("Invalid guild stat.\n");
		return 0;
	}

	set_stat(present("mageobj", obj), stat, value);
	write(CYN+"Mage Stat '"+stat+"' set to: "+value+".\n"+NORM);
	return 1;
  }

}


set_stat(obj, stat, value)
{
  int current;
  int delta;

  current = obj->query_guild_stat(stat);

  if(value > current)
	delta = value - current;
  else if(value < current)
	delta = -(current - value);
  else
	return 0;

  obj->raise_guild_stat(stat, delta);
  return 1;
}

