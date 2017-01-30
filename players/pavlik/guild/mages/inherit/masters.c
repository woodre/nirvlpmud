#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/advance.c";

/* -----------------------------------------------------------------
 * advancement/training functions used by guild master NPCs
 * ----------------------------------------------------------------- */


/*
 * display list of spells that master can teach
 */
master_display_spell_list(string *schools)
{
  string *f;
  string *spell_list;
  string c;
  string school;
  int i;
  int x;
  int maxlevel;

  if(tp->query_guild_rank() >= 60) maxlevel = 7;
  else if(tp->query_guild_rank() >= 50) maxlevel = 6;
  else if(tp->query_guild_rank() >= 40) maxlevel = 5;
  else if(tp->query_guild_rank() >= 30) maxlevel = 4;
  else if(tp->query_guild_rank() >= 20) maxlevel = 3;
  else if(tp->query_guild_rank() >= 10) maxlevel = 2;
  else maxlevel = 1;

  spell_list = ({});

  x = sizeof(f = files(SPELL_DIR + "*.c"));
  while(x--)
  {
	sscanf(f[x], "%s.c", c);
	if(!c) continue;

	/* NOTE: files that start with "__" are inactive or disabled */
	if(c[0..1] == "__")
		continue;

	if(!find_object(SPELL_DIR + c))
	{
		/* if catch returns 1 then an error occured and skip this object */
		if(catch(call_other(SPELL_DIR+f[x], "query_name", 0)))
			continue;
	}

	school = call_other(SPELL_DIR+f[x], "query_school", 0);

	if(member_array(school, schools) != -1)
	{
		spell_list += ({ c });
		spell_list += ({ call_other(SPELL_DIR+f[x], "query_level", 0) });
	}
  }

  write(
  CYN+"+=---------------------------------------------------------------------=+\n"+NORM+
  HIC+"  Spell Name          Command        School         Cost to Learn        \n"+NORM+
  CYN+"+=---------------------------------------------------------------------=+\n"+NORM);

  for(x=1; x<=maxlevel; x++)
  {
    for(i=0; i<sizeof(spell_list)-1; i+=2)
    {
	if(spell_list[i+1] == x && !guild->query_spell(spell_list[i]))
	{
		c = call_other(SPELL_DIR+spell_list[i]+".c", "query_name", 0);
		write("  " + c);
		write(pad(" ", 20 - strlen(c)));

		write(spell_list[i]);
		write(pad(" ", 13 - strlen(spell_list[i])));

		c = call_other(SPELL_DIR+spell_list[i]+".c", "query_school", 0);
		write("  " + c);
		write(pad(" ", 20 - strlen(c)));

		write(spell_learn_cost(call_other(SPELL_DIR+spell_list[i]+".c", "query_level", 0)));
		write("\n");
	}
    }
  }

  write(
  CYN+"+=---------------------------------------------------------------------=+\n"+NORM);

}


/*
 * teach a spell
 */
master_teach_spell(string spellname, string mastername, string *schools)
{
  string school;
  int level, maxlevel;
  int learn_cost;

  /* make sure it's a valid spell */
  if(!spellname) return 0;
  if(file_size(SPELL_DIR+spellname+".c") <= 0) return 0;

  /* check for proper school */
  school = call_other(SPELL_DIR+spellname+".c", "query_school", 0);
  if(member_array(school, schools) == -1) return 0;

  if(guild->query_spell(spellname))
  {
	write(mastername+" says: You have already been taught this spell.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  /* check spell level */
  if(tp->query_guild_rank() >= 60) maxlevel = 7;
  else if(tp->query_guild_rank() >= 50) maxlevel = 6;
  else if(tp->query_guild_rank() >= 40) maxlevel = 5;
  else if(tp->query_guild_rank() >= 30) maxlevel = 4;
  else if(tp->query_guild_rank() >= 20) maxlevel = 3;
  else if(tp->query_guild_rank() >= 10) maxlevel = 2;
  else maxlevel = 1;

  level = call_other(SPELL_DIR+spellname+".c", "query_level", 0);
  learn_cost = spell_learn_cost(level);

  if(level > maxlevel)
  {
	write(mastername+" says: You are not ready for a spell such as this.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  if(learn_cost > guild->query_new_spell_chances())
  {
	write(mastername+" says: You are not prepared to learn this spell right now.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  /* success! */
  return learn_cost;

}


/*
 * check various legalities of training a guild stat
 */
master_train_stat(string stat, string mastername, string *stats)
{
  int x;
  int max_pts;

  if(member_array(stat, stats) == -1)
  {
	write(mastername+" says: You ask for something I cannot give.\n");
	say(mastername+" says something to "+ME+".\n", tp);

	write(mastername+" says: I can train you in: "+HIC);
	for(x=0; x<sizeof(stats); x++)
	{
		write(stats[x]);
		if(x == sizeof(stats)-1) write(".\n\n"+NORM);
		else if(x == sizeof(stats)-2) write(" and ");
		else if(x < sizeof(stats)-2) write(", ");
	}
	return 0;
  }

  if(!guild->query_training_sessions())
  {
	write(mastername+" says: You are not ready for more training.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  /*
   * apply some checks to try and keep guild stats in balance with guild rank
   */
  if(tp->query_guild_rank() >= 60) max_pts = 100;
  else if(tp->query_guild_rank() >= 50) max_pts = 85;
  else if(tp->query_guild_rank() >= 40) max_pts = 65;
  else if(tp->query_guild_rank() >= 30) max_pts = 48;
  else if(tp->query_guild_rank() >= 20) max_pts = 36;
  else max_pts = 35;

  if(guild->query_guild_stat(stat) >= 100)
  {
	write(mastername+" says: I have taught you all in can in the ways of "+stat+".\n");
	write(mastername+" says: It is time to look elsewhere for training.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  if(guild->query_guild_stat(stat) >= max_pts)
  {
	write(mastername+" says: You are not ready for more "+stat+" training yet.\n");
	write(mastername+" says: You must advance further in the guild first.\n\n");
	say(mastername+" says something to "+ME+".\n", tp);
	return 0;
  }

  return 1;

}


