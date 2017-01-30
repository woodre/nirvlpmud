#include "defs.h"

inherit MONSTER;

object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chimera");
  set_alt_name("statue");
  set_short(BOLD+BLK+"Stone Chimera"+NORM);
  set_long(
"According to legend, the Chimera was a creature with the body of\n"+
"a goat, the head of a lion, and the tail of a dragon.  This stone\n"+
"creature is an artful immitation of that creature, but no less\n"+
"dangerous.\n"
  );
  set_gender(0);
  set_race("statue");
  set_level(20);
  set_wc(33);
  set_ac(18);
  set_hp(550);
  set_al(0);
  set_aggressive(1);
  set_chat_chance(4);
  load_chat(short_desc+" looks around for something to crush.\n");
  set_a_chat_chance();
  load_a_chat("Your blows bounce off of the "+short_desc+"'s stone hide.\n");
  load_spell(40,25,0,
    "\n"+short_desc+" bites down on your arm with unmerciful stone fangs\n"+
    "\t\tand shakes you about like a toy.\n\n",
    "\n"+short_desc+" bites #ATT#'s arm.\n\n"
  );
  load_spell(25,25,0,
    "\n"+short_desc+" spins around with surprising dexterity and strikes you\n"+
    "\t\twith its lizardlike tail!\n\n",
    "\n#ATT# is struck by the "+short_desc+"'s tail!\n");
  load_spell(20,20,0,
    "\n"+short_desc+" charges you headfirst, hitting you like a wall.\n\n",
    "\n"+short_desc+" charges #ATT#.\n");
  set_dead_ob(this_object());
}

void heart_beat() {
  if(attacker_ob)
    target=attacker_ob;
  else
    if(target && environment(target)==environment())
      attack_object(target);    
  ::heart_beat();
}

void monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    short_desc+" shatters into a pile of rubble before your eyes.\n");
  corpse=present("corpse",environment());
  if(corpse) destruct(corpse);
  corpse=clone_object(OBJ_PATH+"rubble.c");
  corpse->set_tablet(OBJ_PATH+"tablet2.c");
  move_object(corpse,environment());
}
  
