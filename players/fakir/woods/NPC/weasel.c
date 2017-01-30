#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("weasel");
set_race("creature");
set_short("A Brown Weasel");
set_long(
  "The weasel is the thief and sneak of the woods, and his fur is highly\n"+
  "prized in all the trading posts of the realm.  Weasels are very sneaky\n"+
  "and hard to catch most times.\n");

set_level(6);
set_hp(90);
set_al(0);
set_wc(6 +random(5));
set_ac(7);
set_dead_ob(this_object());
}

monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    "The weasel curls into a ball and dies.\n");
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object("/players/fakir/woods/OBJ/weasfur.c"),corpse);
}
