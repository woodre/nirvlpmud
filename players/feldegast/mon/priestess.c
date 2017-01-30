/*
Name: priestess.c
Author: Feldegast @ nirvana
Date: 8/17/01
Description:
  This is a priestess of Trelos.  She has come to the Jal-hab desert and created
a chapel to serve as a base of operations for the Order of the Wall in the region.
Her ultimate goal is to destroy the demon Jal-hab.  She can heal players if they
ask for it, and she can give players a quest.
  She has a defensive shield that can be used to deflect ONE and only one large 
attack per round, as well as the wrath of god and healing capabilities of all
members of the Order of the Wall.
*/

#include "defs.h"

inherit MONSTER;

int charge;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("priestess");
  set_alias("priestess of trelos");
  set_short("Priestess of Trelos");
  set_long(
"The priestess of Trelos is dressed in a white robe with a blue shawl over\n\
her shoulders.  On the left side of the shawl is the symbol of the blue shield,\n\
and on the right side is the symbolic representation of a wall.  The followers\n\
of Trelos are known for aiding the weak, defending against aggressors, and for\n\
hunting and destroying demons.\n"
  );
  set_level(19);
  set_hp(440);
  set_wc(24);
  set_ac(12);
  set_ac_bonus(5);
  load_spell(80, 2, 3,
    "The Priestess of Trelos summons...\n"+
HIB+"\t*                                 *\n"+
    "\t*                                 *\n"+
    "\t*        "+HIY+"THE WRATH OF GOD"+HIB+"         *\n"+
    "\t*                                 *\n"+
    "\t*                                 *\n"+NORM,
    "");

}

int do_damage(int *dmg, string *types)
{
  int i;
  for(i = 0; i < sizeof(dmg); i++)
  {
    if(charge && dmg[i] > 30)
    {
      say(HIC+"The Priestess of Trelos surrounds herself with a "+NORM+CYN+"S"+HIC+"phere of "+NORM+CYN+"P"+HIC+"rotection!\n"+NORM);
      write("Your attack is deflected.\n");
      charge = 0;
      return 0;
    }
  }
  return (int)::do_damage(dmg, types);
}

/* Note to self: As hit_player is a mask for do_damage, does it need to be rewritten or not? */

void heal_self(int mod)
{
  if(charge && mod < -30)
  {
    say(HIC+"The Priestess of Trelos surrounds herself with a "+NORM+CYN+"S"+HIC+"phere of "+NORM+CYN+"P"+HIC+"rotection!\n"+NORM);
    write("Your attack is deflected.\n");
	charge = 0;
    return 0;
  }
  else (int)::heal_self(mod);
}

void heart_beat()
{
  ::heart_beat();
  charge = 1;
  if(hit_point < (max_hp-50) && !random(40)) {
    tell_room(environment(),HIY+"The Priestess of Trelos presses her holy symbol to her lips and prays\n"+
          "to Trelos for healing.\n"+NORM);
    hit_point+=50;
    hp_bonus+=50;
  }
}

