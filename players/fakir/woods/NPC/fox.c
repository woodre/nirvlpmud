#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("fox");
set_race("creature");
set_short("A Silver Fox");
set_alias("fox");
set_long(
  "The Silver Fox is a silent hunter of the woods, and his fur is highly\n"+
  "prized in all the trading posts of the realm.  Fox are quick and hard\n"+
  "to catch most times.\n");

set_level(9);
set_hp(135);
set_al(0);
set_wc(13);
set_ac(7);
set_dead_ob(this_object());
}
monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    "The fox snaps his jaws and dies.\n");
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object("/players/fakir/woods/OBJ/foxfur.c"),corpse);
}

