/*
File: orc1.c
Author: Feldegast
Date: 3/17/02
Description:
  An orc from the orc encampment in Caladon.
*/

#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(WEP_PATH+"spear.c"),this_object());
  init_command("wield spear"); /* Value = 600 */
  set_name("orcish scavenger");
  set_alt_name("scavenger");
  set_short("Orcish Scavenger");
  set_long(
    "Orcs are hideous, humanoid creatures with thick, hairy hides, squat\n"+
    "bodies and teeth protruding from their mouths.  They are intelligent,\n"+
    "but only barely so, having a strong tribal system, and some basic\n"+
    "tool-working ability.  This particular orc is the lowest of the low,\n"+
    "an orc that survives by picking the bones of the enemies defeated by\n"+
    "his stronger brethren.\n"
  );
  set_gender("male");
  set_race("orc");
  set_level(14);
  set_wc(20);
  set_ac(12);
  set_hp(250);
  set_al(-350);
  set_chat_chance(3);
  load_chat("The Orcish Scavenger makes a loud braying noise.\n");
  load_chat("An orc passes gas.\n");
  load_chat("The Orcish Scavenger whimpers.\n");
  load_chat("The Orc Scavenger says: Braak-tuuth d'lak-toth?\n");
  add_money(random(300));
}
