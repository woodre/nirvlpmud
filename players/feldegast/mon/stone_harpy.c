#include "defs.h"

inherit MONSTER;

object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("harpy");
  set_alt_name("statue");
  set_short(BOLD+BLK+"Stone Harpy"+NORM);
  set_long(
"According to legend, the harpy was a foul creature of the\n"+
"underworld with the body of a crone and the wings, beaks,\n"+
"and talons of a vulture.  This is a statue of that legendary\n"+
"creature so fortunately it lacks a harpy's reak.  Unfortunately,\n"+
"it more than makes up for that deficiency with its stone hard\n"+
"hide.\n"
  );
  set_gender("female");
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
  load_a_chat(short_desc+" swoops down from the air.\n");
  load_a_chat(short_desc+" hovers menacingly above your head.\n");
  load_a_chat(short_desc+" screaches without sound.\n");
  load_a_chat(short_desc+" yours blows bounce off of the "+short_desc+"'s wings.\n");
  load_spell(40,33,0,
    "\n"+short_desc+" swoops down and rakes you with stone talons.\n\n",
    "\n"+short_desc+" swoops down and rakes #ATT# with stone talons.\n\n"
  );
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
  corpse->set_tablet(OBJ_PATH+"tablet1.c");
  move_object(corpse,environment());
}
  
