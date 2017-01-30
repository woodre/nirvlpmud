#include "/players/laera/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chicobo");
set_alias("chick");
set_alt_name("chubby");
set_race("bird");
set_short(HIY+"Chubby Chicobo"+OFF);
set_long(
"A plump replica of its siblings, the downy yellow feathers of this \n"+
"chicobo make it look like a big ball of fluff.  It is slightly bigger\n"+
"than the others, spending much of its time munching away on various\n"+
"insects.\n");

set_level(9);
set_hp(135);
set_al(0);
set_wc(13);
set_ac(7);
set_heal(4,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
load_chat("The chicobo spies an ant on the ground and eats it.\n");
set_a_chat_chance(10);
load_a_chat("Chubby pecks at you as though you are a meal.\n");

}

monster_died() {
move_object(clone_object("/players/laera/cforest/OBJ/whistle.c"),
environment(this_object()));
  tell_room(environment(this_object()),
	"Chubby Chicobo has eaten his last worm... \n");
return 0; }
