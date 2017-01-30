#include "/players/laera/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chicobo");
set_alias("chick");
set_alt_name("shy");
set_race("bird");
set_short(HIY+"Shy Chicobo"+OFF);
set_long(
"This tiny yellow bird almost hides when encountered.  Although shy, it \n"+
"knows no danger.  The safe haven of this forest is its home.\n");

set_level(7);
set_hp(105);
set_al(0);
set_wc(11);
set_ac(6);
set_heal(4,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
load_chat("The chicobo peeks out from behind a tree.\n");
set_a_chat_chance(10);
load_a_chat("The shy chicobo looks for a place to hide.\n");

}

monster_died() {
move_object(clone_object("/players/laera/cforest/OBJ/feather.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"Shy Chicobo didn't find a hiding place in time... \n");
return 0; }
