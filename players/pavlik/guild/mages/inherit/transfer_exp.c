#include "/players/pavlik/guild/mages/defs.h"

/*
 * This is based on calculate_exp.c and is used to transfer exp for
 * players who are already maxxed out in EXP within the guild.
 * This functionality is separated from calculate_exp because calcxp is
 * called upon automatically, whereas this is a strictly manual process.
 */

transfer_exp(arg)
{
  object gob;
  int mexp;
  int transfer_value; /* how much exp we want to transfer - from arg */
  int max_value; /* how much exp we can transfer */
  int is_at_maxglevel; /* if we are at max level or not. */

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
  }
  else
  {
	is_at_maxglevel = 0;
	tell_object(en, "You are not at max guild level.\n"+
	"This command is meant to be used by players at max level who wish to\n"+
	"transfer experience manually to further their dragon development.\n");
	return 1;
  }


  /* no argument, no service. */
  if(!arg)
  {
	tell_object(en, "You must specify how much experience you wish to transfer to the guild.\n");
	return 1;
  }

  /* do some book keeping, get some values and stuff */
  sscanf(arg, "%d", transfer_value); 

  /* get the last known XP amt */
  mexp = gob->query_my_exp();
  if(mexp < 100)
	mexp = en->query_exp();

  if(en->query_exp() > mexp)
	max_value = en->query_exp() - mexp;
  else max_value = 0;

  /* because i (mizan) am a bastard! */
  if(transfer_value < 1)
  {
	tell_object(en, "Negative vibes are silly and must be punished.\n");
	en->hit_player(50);
	return 1;
  }

  if(transfer_value > max_value)
  {
	tell_object(en, "You are only able to transfer " + max_value + " experience.\n");
	return 1;
  }

  tell_object(en, "You transfer " + transfer_value + " experience to the guild.\n");

  en->add_guild_exp( transfer_value );
  en->add_exp(-(transfer_value));
  return 1;

}
