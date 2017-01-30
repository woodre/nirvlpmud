#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("zorocos");
  set_alias("mage");
  set_alt_name("brigand");
  set_short("Zorocos the Hedge Mage");
  set_long(
"Zorocos is a hedge mage, which is like a regular mage but\n"+
"without the talent.  Basicly, he can only perform a few wild\n"+
"magics that may or may not work, or may produce some odd\n"+
"side-effects.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(18);
  set_hp(435);
  set_wc(25);
  set_ac(16);
  set_al(-350);
  set_chat_chance(4);
  load_chat("Zorocos says: BEGONE MORTAL.\n");
  load_chat("Zorocos says: Flee, lest ye face my wrath!\n");
  load_chat("Zorocos says: I shall feast on thy bones!\n");
  set_a_chat_chance(35);
  load_a_chat("Zorocos waves his hands about impotently.\n");
  load_a_chat("\nZorocos hits you with a "+HIM+"Magic Mallet"+NORM+" spell!\n\n");
  load_a_chat("\nZorocos casts a "+HIG+"CHROMATIC OX"+NORM+" spell!\n\n");
  load_a_chat("Zorocos dazzles you with "+HIY+"sparks"+NORM+" that set his robes on "+HIR+"fire"+NORM+".\n");  
  move_object(clone_object(OBJ_PATH+"key1.c"),this_object());
  move_object(clone_object(OBJ_PATH+"gorb.c"),this_object());
  set_dead_ob(this_object());
}

monster_died() {
  object corpse;
  tell_room(environment(),
    "Zorocos frantically waves his hands in a final effort to save\n"+
    "himself.  With a puff of smoke, he disappears!\n");
  corpse=present("corpse",environment());
  destruct(corpse);
  move_object(clone_object(MON_PATH+"rabbit.c"),environment());
}
