#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("dalatios");
  set_alt_name("demon");
  set_short(RED+"A Winged Demon"+NORM);
  set_long(
    "Dalatios is a hideously deformed demon.  His dark red skin is\n"+
    "sloughing off in places and calcified bones protrude through it.\n"+
    "Bat-like wings grow from his back.  Beneath his wings grow two\n"+
    "pairs of thin bony arms with dark black claws on the ends.  His\n"+
    "face is a red masque of pain, anger, and madness.  Dalatios is\n"+
    "a servant of the Demon Lord Jal-Hab.\n"
  );
  set_gender(0);
  set_race("demon");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(475);
  set_al(-900);
  set_aggressive(1);
  set_chat_chance(4);
  load_chat("The demon revels in the storm's chaos!\n");
  load_spell(20,20,0,
    BOLD+"\nThe winged demon slashes you with his black talons!\n\n"+NORM,
    BOLD+"\nThe winged demon slashes #ATT# with his black talons!\n\n"+NORM);
  load_spell(15,20,1,
    HIR+"\nThe winged demon breathes a cone of fire at you!\n\n"+NORM,
    HIR+"\nThe winged demon breathes a cone of fire at #ATT#!\n\n"+NORM);
  set_dead_ob(this_object());
}

monster_died() {
  object corpse;
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object(OBJ_PATH+"dclaws.c"),corpse);
  if(environment()->id("sandstorm")) {
    destruct(environment());
    say("\nThe sandstorm stops.  You see something fall to the ground.\n");
    move_object(clone_object(OBJ_PATH+"key-air.c"),this_object());
  }
}
