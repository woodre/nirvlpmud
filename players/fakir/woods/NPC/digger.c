inherit "obj/monster.c";
#include "/players/fakir/color.h"

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("brown digger");
set_alias("digger");
set_race("creature");
set_short(BROWN+"Brown Digger"+OFF);
set_long(
  "Blind as a bat in the daylight, these small furry animals spend most\n"+
  "of their time in subterranean tunnels.  The soft fur of a digger is\n"+
  "oftain used for boots and hats, so selling them is never a problem.\n");


set_level(4);
set_hp(60);
set_al(600);
set_wc(8);
set_ac(4);
set_aggressive(0);
set_dead_ob(this_object());
}

monster_died(object ob) {
  object corpse;
  tell_room(environment(),
    "The digger jumps out of his skin and dies.\n");
  corpse=present("corpse",environment());
  if(corpse)
    move_object(clone_object("/players/fakir/woods/OBJ/digfur.c"),corpse);
}
