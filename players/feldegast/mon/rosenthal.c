/*
File: rosenthal.c
Creator: Feldegast @ Nirvana
Date: 1/11/01
Description:
  This is the shopkeeper for Morgar's magic shop,
/players/morgar/magic.c
*/
#include "/players/feldegast/defines.h"

inherit "/players/feldegast/std/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rosenthal");
  set_alias("wizardkind");
  set_alt_name("mage");
  set_short("Rosenthal Wizardkind");
  set_long(
"Rosenthal Wizardkind is an aging prestidigitator and accomplished\n\
magician.  A pair of wire-rimmed glasses are perched upon his long\n\
nose and a long horn-shaped pipe is clenched between his yellowed\n\
teeth. DO NOT ATTACK THIS MAN, UNLESS YOU ARE INSANE.\n"
  );
  set_level(19);
  set_hp(450);
  set_wc(28);
  set_ac(16);
  set_chat_chance(5);
  load_chat("Rosenthal puffs a ring of green smoke into the air.\n");
  load_chat("Rosenthal growls: Watcha want?\n");
  load_spell(10,15,0,
    "Rosenthal waves his hands in the air...\n"+
    "\t\t"+HIC+"LIGHTNING STRIKES"+NORM+" you!\n",
    "Rosenthal waves his hands in the air...\n"+
    "\t\t"+HIC+"LIGHTNING STRIKES"+NORM+" #ATT#!\n");
  load_spell(8,15,0,
    "Rosenthal puffs green smoke into the air...\n"+
    GRN+"\t\tA terrifying green dragon appears before you\n"+
    "\t\tand strikes with illusory claws!\n"+NORM,
    "");
  add_money(3500+(50*random(20)));
}

#if 0 /* Better ways to do this - Gnar */
void heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !attacker_ob->query_ghost())
{
  attacker_ob->death("Rosenthal the Pimp");
 }
}
#endif

do_damage() { return 0; }
