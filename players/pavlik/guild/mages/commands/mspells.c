#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mspells");
  set_name("Mage Spells ");
  set_color_name(HIC+"Mage Spells"+NORM);
  set_rank(100);
  set_descrip(
	"The command will display a Mage's spell list.\n" +
	"\n" +
	"This command is available only to wizards.\n"
  );
}


cmd(str)
{
  object ob, obj;
  string *spells;
  mapping spell_count;
  int i, x;
  int total;

  if(tp->query_level() < WIZLEVEL && tp->query_guild_rank() <= MAXGUILDRANK)
	return 0;

  if(!str)
	str = tp->query_real_name();

  if(!(obj = find_player(str)))
  {
	notify_fail("Could not find '"+str+"'.\n");
	return 0;
  }

  if(!(ob = present("mageobj", obj)))
  {
	notify_fail(capitalize(str)+" does not have a mage guild object.\n");
	return 0;
  }

  write("\n");
  write(CYN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  write(obj->short()+"\n");
  write(CYN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);

  spells = ob->query_spells();

  if(!spells || !sizeof(spells)) {
	write("No Spells.\n");
  }
  else
  {
	spell_count = ob->query_spell_count();

	i = sizeof(spells);
	while(i--)
	{
		if(spells[i] && spell_count[spells[i]])
			total += spell_count[spells[i]];
	}

	for(i=1; i<=MAXSPELLLEVEL; i++)
	{
		for(x=0; x<sizeof(spells); x++)
			if(file_size(SPELL_DIR+spells[x]+".c") > 0)
				if(call_other(SPELL_DIR+spells[x], "query_level", 0) == i)
				{
					int y;
					write(i+"\t"+spells[x]);
					for(y=20; y>strlen(spells[x]); y--)
						write(" ");
					write(spell_count[spells[x]]+"\t\t");
					if(total > 0)
						write((spell_count[spells[x]]*100/total)+"%\n");
					else
						write("0%\n");
				}
	}
  }

  write(CYN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  write("\n");
  return 1;
}

