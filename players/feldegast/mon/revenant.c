/*
File: revenant.c
Author: Feldegast @ nirvana
Date: 2/14/01
Description:
  A revenant creature for the graveyard in Caladon.  Has an extra
attack, and is aggressive.  It also switches opponents occasionally.
*/
#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"wgauntlets.c"),this_object());
  init_command("wear gauntlet");
  move_object(clone_object(ARM_PATH+"chainmail.c"),this_object());
  init_command("wear chainmail");
  move_object(clone_object(WEP_PATH+"sword.c"),this_object());
  init_command("wield sword");
  move_object(clone_object(WEP_PATH+"sword.c"),this_object());
  init_command("wield sword");
  set_name("revenant");
  set_short(BOLD+"Revenant"+NORM);
  set_long(
/* Have you ever seen such a lame description? */
"This is a large creature with black, leathery flesh beneath its\n"+
"chainmail armor.  The revenant is a powerful undead creature.\n"+
"When it was alive, it was a skilled and cunning warrior.  Now\n"+
"that it is dead, it is ten times as dangerous.\n"
  );
  set_gender("male");
  set_race("undead");
  set_level(21);
  set_wc(24); /* x2 attacks (see hb) */
  set_ac(15); /* +4 ac from armor */
  set_ac_bonus(5); /* +1 for attack switching */
  set_wc_bonus(12); /* For multiple attacks */
  set_hp(600);
  set_al(-600);
  set_aggressive(1);
  load_chat("The revenant hisses!\n");
  load_spell(20,40,1,
    BOLD+"\nThe Revenant drains your lifeforce!\n\n"+NORM,
    BOLD+"\nThe Revenant drains #ATT#'s lifeforce!\n\n"+NORM);
}

void heart_beat() {
  ::heart_beat();
  if(attacker_ob && !attacker_ob->query_ghost() && random(3)) {
    already_fight=0;
    attack();
  }
  if(alt_attacker_ob && alt_attacker_ob!=attacker_ob
     && present(alt_attacker_ob,environment())
     && !random(15)) {
    object temp;
    temp=attacker_ob;
    attacker_ob=alt_attacker_ob;
    alt_attacker_ob=temp;
    tell_room(environment(),HIR+
      "The revenant switches opponents!\n"+NORM);
  }
}

/* So the revenant can appear to wield two swords. */
wield() {
}

query_attrib() {
  return 30;
}
