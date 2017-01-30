#include "/players/pavlik/guild/mages/defs.h"

query_verb()      { return "mhelp"; }
query_name()      { return "Mage Help"; }
query_cname()     { return HIC+"Mage Help"+NORM; }
query_rank()      { return 1; }
query_descrip()
{
  return "  Use mhelp <cmd> to learn about guild commands.\n";
}


cmd(str)
{
  string file;
  string s;
  string lvl;
  string txt;
  string color;
  int i;

  write("\n");

  if(!str) {
	cat("/players/pavlik/guild/mages/helps2/general");
	return 1;
  }

  if(str == "members") {
	DONATOR->guild_members();
	return 1;
  }

  /* check for guild command first */
  file = CMD_DIR + str + ".c";

  /* check for player-only command */
  if(file_size(file) <= 0)
	file = CMD_DIR + "_" + str + ".c";

  /* and if no guild command check for guild spell */
  if(file_size(file) <= 0)
  {
	file = SPELL_DIR + str + ".c";
	s = "spell";
  }

  /* check for player-only spell */
  if(file_size(file) <= 0)
  {
	file = CMD_DIR + "_" + str + ".c";
	s = "spell";
  }

  /* and if still nothing than return zero */
  if(file_size(file) <= 0)
  {
	notify_fail("No Mage help available for: "+HIC+str+NORM+"\n");
	return 0;
  }


  /* if we did find a file print out the help */
  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");

  if(s == "spell")
	write(CYN+"[ Spell     ]: " + NORM + file->query_cname() + "\n");
  else
	write(CYN+"[ Command   ]: " + NORM + file->query_cname() + "\n");

  if(file->query_rank())
  {
	write(CYN+"[ Rank      ]: " + NORM + file->query_rank() + "\n");
  }
  else
  {
	lvl = file->query_level();
	txt = file->query_school();
	if(lvl <= 0) lvl = "N/A";
	else if(lvl == 1) lvl = "1st";
	else if(lvl == 2) lvl = "2nd";
	else if(lvl == 3) lvl = "3rd";
	else if(lvl >= 4) lvl = lvl + "th";

	if(txt == "conjuration") color = RED;
	else if(txt == "enchantment") color = GRN;
	else if(txt == "evocation") color = YEL;
	else if(txt == "illusion") color = BLU;
	else if(txt == "necromancy") color = HIBLK;
	else {
		txt = "";
		color = NORM;
	}
	write(CYN+"[ Level     ]: " + NORM + color + lvl + " lvl " + capitalize(txt) + NORM + "\n");
  }

  if(!file->query_cost_str())
	write(CYN+"[ Cost      ]: " + NORM + "none\n");
  else
	write(CYN+"[ Cost      ]: " + NORM + file->query_cost_str() + "\n");

  if(!file->query_component())
	write(CYN+"[ Component ]: " + NORM + "none\n");
  else
	write(CYN+"[ Component ]: " + NORM + file->query_component() + "\n");

  if(!file->query_delay())
	write(CYN+"[ Delay     ]: "+NORM+"none\n");
  else if(file->query_delay() > 60)
	write(CYN+"[ Delay     ]: " + NORM + file->query_delay()/60 + " minutes\n");
  else if(file->query_delay() == 60)
	write(CYN+"[ Delay     ]: " + NORM + "1 minute\n");
  else
	write(CYN+"[ Delay     ]: " + NORM + file->query_delay() + " seconds\n");

  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");
  write(file->query_descrip());
  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");
 
  return 1;

}

