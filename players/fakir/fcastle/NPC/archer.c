#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure, weapon;
  ::reset(arg);
  if(arg) return;

set_name("archer");
set_alt_name("guard");
set_race("human");
set_short("An Archer");
set_long(
  "Wearing only light cotton garments, the archer depends upon the\n"+
  "battlements and other guards to protect him from harm.  He seems\n"+
  "rather surprised at your finding him so open to attack.\n");

set_level(13);
set_hp(225);
set_al(-500);
set_wc(17);
set_ac(8);
set_dead_ob(this_object());
weapon=clone_object("/players/fakir/inn/WEPS/longbow.c");
move_object(weapon,this_object());
treasure=clone_object("/players/fakir/fcastle/OBJ/quiver.c");
move_object(treasure,this_object());
}

