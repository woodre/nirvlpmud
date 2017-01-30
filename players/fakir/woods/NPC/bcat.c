#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("bobcat");
set_alias("cat");
set_alt_name("cub");
set_race("creature");
set_short("Bobcat Cub");
set_long(
  "The bobcat cub has few teeth yet, and its claws are not grown in either...so\n"+
  "it is not a very fearsome creature.  Mostly it just wants to see its mother\n"+
  "so it can get some warm milk.  The baby spots on its fur are very pretty.\n");

set_level(3);
set_hp(30 +random (20));
set_al(0);
set_wc(4 + random (4));
set_ac(2 + random (2));
set_aggressive(0);
set_dead_ob(this_object());
}
monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    "The bobcat cub scratches you a last time and dies.\n");
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object("/players/fakir/woods/OBJ/bfur.c"),corpse);
}


