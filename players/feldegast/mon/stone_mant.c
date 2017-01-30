#include "defs.h"

inherit MONSTER;

object target;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("manticore");
  set_alt_name("statue");
  set_short(BOLD+BLK+"Stone Manticore"+NORM);
  set_long(
"According to legend, the manticore was a creature with the body of\n"+
"a lion, the face of a man, a porcupine's quills, and the tail of\n"+
"a scorpion.  The creators of this monstrous piece of statuary have\n"+
"artfully recreated that monster, but with the strength of a dozen\n"+
"men and a nearly impervious hide.\n"
  );
  set_gender(0);
  set_race("statue");
  set_level(20);
  set_wc(33);
  set_ac(20);
  set_hp(550);
  set_al(0);
  set_aggressive(1);
  set_chat_chance(4);
  load_chat(short_desc+" looks around for something to crush.\n");
  set_a_chat_chance();
  load_a_chat("Your blows bounce off of the "+short_desc+"'s stone hide.\n");
  load_spell(30,25,0,
	"\n"+short_desc+" strikes you with its scorpion tail!\n\n",
	"\n#ATT# is struck by the "+short_desc+"'s scorpion tail.\n\n");
  load_spell(25,20,0,
	"\n"+short_desc+" shoots you with sharp flechettes from its back.\n\n",
	"#ATT# is struck by the "+short_desc+"'s quills.\n");
  load_spell(40,10,0,
	"\n"+short_desc+" pounces upon you, raking your body with its lionclaws.\n\n",
	"\n"+short_desc+" pounces upon #ATT#!\n\n");

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
  corpse->set_tablet(OBJ_PATH+"tablet4.c");
  move_object(corpse,environment());
}
  
