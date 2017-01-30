#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("spells");
  set_name("Spells");
  set_color_name(HIC+"Spells"+NORM);
  set_rank(1);
  set_descrip(
	"Display a list the spells you have learned.\n" +
	"See Also: commands\n"
  );
}


cmd(str)
{
  string *spells;
  string *spell_list;
  string s;
  string m;
  int i;
  int min, max;
  int z;

  print_header();

  spells = guild->query_spells();
  if(!spells || !sizeof(spells))
  {
	print_footer();
	return 1;
  }

  if(str)
  {
	if(str == "c" || str == "conj" || str == "conjuration") m = "conjuration";
	else if(str == "e" || str == "en" || str == "ench" || str == "enchantment") m = "enchantment";
	else if(str == "ev" || str == "evoc" || str == "evocation") m = "evocation";
	else if(str == "i" || str == "illu" || str == "illusion") m = "illusion";
	else if(str == "n" || str == "necr" || str == "necromancy") m = "necromancy";
	else if(sscanf(str, "%d %d", min, max) != 2)
		sscanf(str, "%d", min);
  }

  spell_list = ({});

  /*
   * build a string array of all known spells
   */
  for(i=0; i<sizeof(spells); i++)
  {
	if(spells[i] == "init")
		continue;

	if(file_size(SPELL_DIR + spells[i] + ".c") > 0)
	{
		s = SPELL_DIR + spells[i];

		if(!find_object(s))
		{
			if(catch(s->query_name()))
				continue;
		}
		spell_list += ({ s->query_level() });		/* 0 */
		spell_list += ({ s->query_name() });		/* 1 */
		spell_list += ({ s->query_verb() });		/* 2 */
		spell_list += ({ s->query_school() });		/* 3 */
		spell_list += ({ s->query_cost_string() });	/* 4 */
	}
  }

  /*
   * print all known spells sorted by level
   */
  if(!min)
  {
	for(i=0; i<=MAXSPELLLEVEL; i++)
	{
		for(z=0; z<sizeof(spell_list)-4; z+=5)
		{
			if(spell_list[z] == i)
			   if(!m || m == spell_list[z+3])
				print_spell(spell_list[z],
					    spell_list[z+1],
					    spell_list[z+2],
					    spell_list[z+3],
					    spell_list[z+4]);
		}
	}
  }
  /*
   * print only spells within selected range
   */
  else
  {
	for(i=0; i<sizeof(spell_list)-4; i+=5)
	{
		if(spell_list[i] == min)
			print_spell(spell_list[i],
				    spell_list[i+1],
				    spell_list[i+2],
				    spell_list[i+3],
				    spell_list[i+4]);
	}
  }

  print_footer();
  return 1;

}

print_header()
{
  write(CYN+
   "Lvl:\tSpell Name:\t\tCommand:\t\tSchool:\n" +
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
}

print_footer()
{
  write(CYN+
   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
}

print_spell(level, name, verb, school, cost)
{
  write(" "+level+"\t");
  write(bufstr(name, 18)+"\t");
  write("["+bufstr(verb+"]", 10)+"\t");
  write(school+"\n");
}

bufstr(str, field)
{
  int i, x;
  string buff;

  buff = str;
  x = 20 - strlen(buff);
  for(i=0; i<x; i++){ buff = buff + " "; }
  return buff;
}

