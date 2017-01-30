#include "/players/pavlik/guild/mages/defs.h"

/*
 * Calculate guild exp earned based on regular exp earned
 * This is called at regular intervals from the Daemon
 */

calculate_exp()
{
  object gob;
  int mexp, value, divd;
  int amount;
  int msg;
  int is_at_maxglevel;

  /* Thanks for Teepo's help on this, pointing me to some documentation
     VERY quickly and allowing me to figure out fast what should be done.
     I did not make major structural changes to the code, but I made it
     so that any time a exp change is about to happen, it checks to see
     that the player is at max level or not. Otherwise, this still ranks
     as a quick and dirty fix.
  -miz */

  if(!en) return;

  gob = present("mageobj", en);

  /* first we check if the player is at max guild level or not. */
  if(en->query_guild_rank() >= 71)
  {
	is_at_maxglevel = 1;
/*	tell_object(en, "You are at max guild level.\n"); */
  }
  else
  {
	is_at_maxglevel = 0;
/*	tell_object(en, "You are not at max guild level.\n"); */
  }


  /* find out if the player is idle or not editing. these are who we msg */
  if(!en->query_idle() && !in_editor(en))
	msg = 1;
 
  if(msg) 
	tell_object(en, "MageSoul: calculating experience ... ");

  /* get the last known XP amt */
  mexp = gob->query_my_exp();
  if(mexp < 100)
	mexp = en->query_exp();


  /* See if we've earned any new XP and divide it up */
  /* DIVD is the % of XP that goes to the Guild */
  if(en->query_exp() > mexp)
  {

	value = en->query_exp() - mexp;
	if(value < 1) value = 1;

	/* how much of this goes to the guild? */
	divd = gob->query_divd();
	if(divd < 1) divd = 1;
	if(divd > 100) divd = 100;

	amount = value * divd / 100;

	/* mizan addition - if we are at max level do nothing!*/

	if(!is_at_maxglevel)
 	{
		en->add_guild_exp( value * divd / 100 );
		en->add_exp(-( value * divd / 100 ));
	}


	if(msg)
	{
		if(is_at_maxglevel) 
			tell_object(en, "max guild level. No changes...");
		else if(amount < 1)
			tell_object(en, "no guild xp added.");
		else
			tell_object(en, amount+" guild xp added.");
	}

	/* add on any bonuses for being top donator... */
	if(!is_at_maxglevel && 
	   en->query_real_name() == DONATOR->query_first())
	{
		en->add_guild_exp(amount/10);
		if(msg)
			tell_object(en, " [+10%]");
	}
	else if(!is_at_maxglevel &&
		en->query_real_name() == DONATOR->query_second())
	{
		en->add_guild_exp(amount/20);
		if(msg)
			tell_object(en, " [+5%]");
	}

	if(msg)
		tell_object(en, "\n");

  }
  else
  {
	if(msg)
		tell_object(en, "done.\n");
  }

/* i simply don't do anything here if we are at max level. -mizan */
  if(!is_at_maxglevel) gob->set_my_exp(en->query_exp());
  return 1;

}
