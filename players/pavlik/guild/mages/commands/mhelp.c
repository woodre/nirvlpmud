#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/spell";

#define LINE_WIDTH 62

reset(arg) {
  if(arg) return;
  set_verb("mhelp");
  set_name("Mage Help");
  set_color_name(HIC+"Mage Help"+NORM);
  set_rank(1);
  set_descrip(
	"Use mhelp <topic> to learn about the guild.\n"
  );
}


cmd(str)
{
  string file;
  string s;
  string lvl;
  string txt;
  string color;
  string *descrip;
  int i;


  if(!str) {
	cat(HELP_DIR+"general");
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

  /* if nothing else was found check the help directory */
  if(file_size(file) <= 0)
  {
	if(file_size(HELP_DIR+str) > 0)
	{
		write("\n");
		cat(HELP_DIR+str);
		write("\n");
		return 1;
	}
  }

  /* and if still nothing than return zero */
  if(file_size(file) <= 0)
  {
	notify_fail("> No "+HIC+"Mage Help"+NORM+" available for: "+HIM+str+NORM+"\n");
	return 0;
  }

  /* if we did find a file print out the help */
  write("\n");
  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");

  if(s == "spell")
	write(CYN+"[ Spell     ]: " + NORM + file->query_color_name() + "\n");
  else
	write(CYN+"[ Command   ]: " + NORM + file->query_color_name() + "\n");

  if(s != "spell")
  {
	write(CYN+"[ Rank      ]: " + NORM + file->query_rank() + "\n");
  }

  if(s == "spell")
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

  if(file->query_type())
	write(CYN+"[ Type      ]: " + NORM + capitalize(file->query_type()) + "\n");

  if(file->query_stat())
	write(CYN+"[ Stat      ]: " + NORM + capitalize(file->query_stat()) + "\n");
  else
	write(CYN+"[ Stat      ]: " + NORM + "none\n");

  if(!file->query_cost_string())
	write(CYN+"[ Cost      ]: " + NORM + "none\n");
  else
	write(CYN+"[ Cost      ]: " + NORM + file->query_cost_string() + "\n");

  if(!file->query_component_string())
	write(CYN+"[ Component ]: " + NORM + "none\n");
  else
	write(CYN+"[ Component ]: " + NORM + file->query_component_string() + "\n");

 /*
  * spell delays have been (temporarily?) removed
  *
  if(!(i = file->query_delay()))
  {
	write(CYN+"[ Delay     ]: "+NORM+"none\n");
  }
  else
  {
	if(i > 60)
	{
		if(i/60 > 1)
			write(CYN+"[ Delay     ]: " + NORM + i/60 + " minutes");
		else
			write(CYN+"[ Delay     ]: " + NORM + i/60 + " minute");
		i = i - (i/60) * 60;
		if(i > 0)
			write(" and " + i + " seconds.");
	}
	else if(i == 60)
		write(CYN+"[ Delay     ]: " + NORM + "1 minute");
	else
		write(CYN+"[ Delay     ]: " + NORM + i + " seconds");

	if(!file->query_delay_type() ||
	   lower_case(file->query_delay_type()) == lower_case(file->query_type()))
		write(" ("+capitalize(file->query_type())+")");
	else if(lower_case(file->query_delay_type()) == "all")
		write(" (ALL)");
	else if(lower_case(file->query_delay_type()) == lower_case(file->query_verb()))
		write(" ("+file->query_name()+")");

	write("\n");
  }
  *
  */

  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");

  descrip = explode(format(file->query_descrip(), LINE_WIDTH), "\n");
  for(i=0; i<sizeof(descrip); i++)
  {
	write("  "+descrip[i]+"\n");
  }

  write(CYN+"[----------------------------------------------------------------]"+NORM+"\n");
 
  return 1;

}

