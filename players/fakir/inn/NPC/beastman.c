#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure, weapon;
  ::reset(arg);
  if(arg) return;

set_name("beastman");
set_alias("beast");
set_alt_name("man");
set_race("creature");
set_short("Beastman");
set_long(
  "Covered in dark curly hair, you quickly see why the village folk call\n"+
  "this race of beings 'beastmen'.  Unwelcome in most villages, this one\n"+
  "has managed to secure a room in the inn somehow.  Perhaps he is ill and\n"+
  "in need of rest and comfort.\n");

set_level(15);
set_hp(225);
set_al(-500);
set_wc(20);
set_ac(12);
set_dead_ob(this_object());
weapon=clone_object("/players/fakir/inn/WEPS/longbow.c");
move_object(weapon,this_object());
treasure=clone_object("/players/fakir/inn/OBJ/quiver.c");
move_object(treasure,this_object());
}

