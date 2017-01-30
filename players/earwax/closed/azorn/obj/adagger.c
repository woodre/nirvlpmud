/*
 *      File:                   /players/earwax/closed/azorn/obj/adagger.c
 *      Function:               Dagger the acolytes carry.
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax
 *                                      All Rights Reserved.
 *      Source:                 10/21/05
 *      Notes:                  13 wc, returns r(10) other|evil vs goods only
 *                              Can only be wielded by evils.
 *                              Barterable to xxx for 2500+r(1000) coins.
 *                              It's found on ~/closed/azorn/mon/acolyte.c
 *                              Acolyte is a 9500 exp mob, and nasty.
 *      Change History:
 */

#include "../defs.h"
inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("sacrificial dagger");
  set_short("An "+BOLD+"Acolyte's"+HIK+" Sacrificial Dagger"+NORM);
  set_long(short()+"\n"+HIK
    + "This is the preferred sacrificial tool for the acolytes of the dread\n"
    + "Cult of Azorn.  An aura of pure evil emanates from this well-crafted\n"
    + "blade.  It is rumored that the hero Tomas has offered a bounty for\n"
    + "these weapons.\n"+NORM);
  set_class(13);
  set_type("knife");
  SetMultipleIds(({
	  "dagger", "knife", "sacrificial dagger", ADAGGER_ID
    }));
  /* Evil damage, base wc 13 */
  set_params("other|good",13,"evil_hit");
  set_weight(1);
  set_value(2500+random(1000));
  /* set_wield_func(this_object()); */
}

/* Only allow evil players to wield this. */
status test_wield(string arg) {
	if (present(arg, this_player()) != this_object())
	  return 0;
	  
	if ((int)this_player()->query_alignment() > -299)
	{
		write("This weapon is too evil for you to use.\n");
		return 1;
	}
	return (int)wield(arg);
}

void init() {
	add_action("test_wield", "wield");
}

int evil_hit(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  if((int)attacker->query_alignment() > 299 
    && (int)wielded_by->query_alignment() < -299) {
    tell_object(wielded_by,HIK
      + "Your sacrificial dagger darkens as it scores a hit.\n"+NORM);
    tell_object(attacker,HIK+ wielded_by->query_name()
      + "'s dagger turns pitch black and you feel a pulse of evil energy\n"+NORM);
    if(environment())
      tell_room(environment(),HIK+wielded_by->query_name()
        + "'s sacrificial dagger briefly turns pitch black as it scores a hit.\n"+NORM, 
      ({wielded_by,attacker}));
    return 10;
  }
  
  /* If they've turned good, unwield this bad boy */
  write("The blade exudes evil, and you hastily unwield it!\n");
  command("unwield "+ADAGGER_ID, wielded_by);
  return 0;
}
  
