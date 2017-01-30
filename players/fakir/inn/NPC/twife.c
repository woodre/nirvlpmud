#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
object treasure;
  ::reset(arg);
  if(arg) return;

set_name("tinkers wife");
set_alias("wife");
set_alt_name("tirsa");
set_race("human");
set_short("Tinkers Wife");
set_long(
  "Impatiently waiting in the room of the inn for her husband, Tirsa is\n"+
  "not at all pleased.  She is anxious to be on the road home and wishes\n"+
  "this journey behind her.\n"); 
set_level(12);
set_hp(150 + random (35));
set_al(-500);
set_wc(13 + random (4));
set_ac(7 + random (3));
set_aggressive(0);
set_dead_ob(this_object());
treasure=clone_object("/players/fakir/inn/OBJ/brooch.c");
move_object(treasure,this_object());

}

