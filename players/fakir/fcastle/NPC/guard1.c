#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure, weapon;
  ::reset(arg);
  if(arg) return;

set_name("watchman");
set_alt_name("guard");
set_race("human");
set_short("Tower Watchman");
set_long(
  "   Grey hair drops to shoulder length and falls upon the neatly\n"+
  "pressed collar of the tower watchmans vest.  His eyes are dim\n"+
  "with age, but he still knows his duty is to defend the tower to\n"+
  "the death if need be.  He seems to be shaken and out of breath.\n");

move_object(clone_object("/players/fakir/fcastle/WEP/wrapier.c"),
   (this_object()));
   init_command("wield rapier");

set_level(9);
set_hp(135);
set_al(500);
set_wc(13);
set_ac(7);
set_dead_ob(this_object());
}

