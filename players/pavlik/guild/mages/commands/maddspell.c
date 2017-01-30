#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("maddspell");
  set_name("Add Mage Spell");
  set_color_name(HIC+"ADd Mage Spell"+NORM);
  set_rank(100);
  set_descrip(
	"A debug command that allows wizards to add spells.\n" +
	"Use maddspell <spell> give yourself a spell, or\n" +
	"Use maddspell <who> <spell>\n" +
	"This command is only available to wizards.\n"
  );
}


cmd(str)
{
  string spell, who;
  string c;
  string *spells;
  object obj;
  int i;

  if(tp->query_level() < WIZLEVEL)
	return 0;

  if(!str || str == "list") {
	write(CYN+"Your Mage Spells:\n"+NORM);
	spells = guild->query_spells();
	for(i=0; i<sizeof(spells); i++) {
		write(i+": "+spells[i]+"\n");
	}
	return 1;
  }

  if(sscanf(str, "%s %s", who, spell) == 2)
  {
	obj = find_player(who);
	if(!obj)
	{
		notify_fail(capitalize(who)+" could not be found.\n");
		return 0;
	}
	if(!present("mageobj", obj))
	{
		notify_fail(capitalize(who)+" does not have a guild object.\n");
		return 0;
	}
  }
  else if(find_player(str))
  {
	obj = present("mageobj", find_player(str));
	if(!obj)
	{
		notify_fail(capitalize(str)+" does not have a guild object.\n");
		return 0;
	}
	write(CYN+capitalize(str)+"'s Mage Spells:\n"+NORM);
	spells = obj->query_spells();
	for(i=0; i<sizeof(spells); i++) {
		write(i+": "+spells[i]+"\n");
	}
	return 1;
  }
  else
  {
	obj = tp;
	spell = str;
  }

  if(spell == "ALL")
  {
	i = sizeof(spells = files(SPELL_DIR + "*.c"));
	while(i--)
	{
		sscanf(spells[i], "%s.c", c);
		if(c[0..1] == "__") continue;
		present("mageobj", obj)->add_spell(c);
		write(CYN+"Spell added: "+NORM+HIY+c+NORM+"\n");
	}
  }
  else if(spell == "CLEAR")
  {
	present("mageobj", obj)->clear_all_spells();
	write(HIC+IT+"'s SPELL LIST CLEARED.\n"+NORM);
  }
  else
  {
	present("mageobj", obj)->add_spell(spell);
	write(CYN+"Spell added: "+NORM+HIY+spell+NORM+"\n");
  }
  return 1;

}
