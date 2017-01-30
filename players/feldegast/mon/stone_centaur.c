#include "defs.h"

inherit MONSTER;

object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("centaur");
  set_alt_name("statue");
  set_short(BOLD+BLK+"Stone Centaur"+NORM);
  set_long(
"The centaur is a creature with the body of a horse but the torso and\n"+
"head of a man.  The makers of this creature artfully recreated that\n"+
"legendary creature down to the smallest detail.\n"
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
  load_a_chat(short_desc+" rears back on its hooves.\n");
  load_spell(30,25,0,
"\n"+short_desc+" strikes you with its cold hard forehooves.\n\n",
"\n#ATT# is struck by the "+short_desc+"'s forehooves.\n\n");
  load_spell(25,20,0,
"\n"+short_desc+" punches you with its stone cold fists.\n\n",
"\n#ATT# is struck by the "+short_desc+"'s stone cold fists.\n\n");
  load_spell(40,10,0,
"\n"+short_desc+" grabs you by the arm and slams you into the\n"+
"\t\tground face first!\n\n",
"\n"+short_desc+" slams #ATT# into the ground!\n\n");
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
  corpse->set_tablet(OBJ_PATH+"tablet3.c");
  move_object(corpse,environment());
}
  
