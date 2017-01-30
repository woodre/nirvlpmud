/*
 *      File:                   /players/earwax/closed/azorn/mon/acolyte.
 *      Function:              
 *      Author(s):              Earwax@Nirvan
 *      Copyright:              Copyright (c) 2005 Earwax/David Hale
 *                                      All Rights Reserved
 *      Source:                 10/21/200
 *      Notes:                 
 *      Change History
 *
 */
 
#include "../defs.h"
inherit MON;

void reset(status arg)
{
	::reset(arg);

	if (arg)
	  return;

	set_name("acolyte");
	set_race("human");
	set_short(BOLD+"Acolyte"+HIK+" of the Cult of Azorn"+NORM);
  set_long("This is an acolyte of the Cult of Azorn.  The fervor in his eyes\n"
    + "shows his insanity and devotion to his cult.\n");
  set_al(-1000);
  set_level(20);
  set_hp(700+random(100));
  set_wc(25);
  set_ac(15);
  /* Immune to evil damage. */
  set_armor_params("other|evil", 0, 100, "laugh_at_evil");
  /* Double-up on good damage. */
  set_armor_params("other|good", 0, -100, "hurt_from_good");
  set_multi_cast(1); /* Can spell more than once a round. */
  /* The fun stuff, this will make these a little rough :) */
  add_spell("evil_aura1",
    "$HK$You are enveloped in an aura of evil by #CMN#$N$\n",
    "$HK$#CMN# envelops #CTN# in a blast of evil energy!$N$\n",
    20,            /* 20% chance of it hitting main attacker */
    50,            /* Hard hitting spell for a coin mob */
	  "other|evil"); /* Evil dytpe */
  add_spell("evil_aura2",
    "$HK$You are enveloped in an aura of evil by #CMN#$N$\n",
    "$HK$#CMN# envelops #CTN# in a blast of evil energy!$N$\n",
    30,           /* 20% chance of it hitting randomly */
    50,           /* Hard hitting spell for a coin mob */
	  "other|evil", /* Evil dytpe */
	  6);           /* Hit any player attacker at random */
 }









/*
 * Function name
 * Description
 * Arguments
 * Returns
 *
 */
