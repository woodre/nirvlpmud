#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mvar");
  set_name("Mage Variable");
  set_color_name(HIC+"Mage Variable"+NORM);
  set_rank(100);
  set_descrip(
	"A debug command that allows wizards to set a variable in the GOB.\n" +
	"This command is available only to wizards.\n"
  );
}


cmd(str)
{
  string name;
  int i, value;
  mapping vars;
  string *names;
  mixed what;

  if(tp->query_level() < WIZLEVEL)
	return 0;

  if(!str)
  {
	write(CYN+"Mage Variables:\n"+NORM);
	vars = guild->query_guild_vars();
	names = m_indices(vars);
	for(i=0; i<sizeof(names); i++) {
		write(i+": "+names[i]+"    ");
		write(vars[names[i]]);
		write("\n");
	}
	return 1;
  }

  if(sscanf(str, "%s %s", name, value) != 2)
  {
	notify_fail("Usage: mvar <name> <value>\n");
	return 0;
  }

  present("mageobj", tp)->set_guild_var(name, value);
  write(CYN+"Variable set: "+NORM+name+" = "+value+"\n");

  return 1;

}
