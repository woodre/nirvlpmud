#include "/players/laera/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chicobo");
set_alias("chick");
set_alt_name("playful");
set_race("bird");
set_short(HIY+"Playful Chicobo"+OFF);
set_long(
"Happy and energetic, this tiny yellow bird seems to be smiling.  It\n"+
"darts between the trees teasingly and will approach to peck playfully.\n");

set_level(7);
set_hp(105);
set_al(0);
set_wc(11);
set_ac(6);
set_heal(4,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
load_chat("The chicobo jumps out from behind a tree.\n");
set_a_chat_chance(10);
load_a_chat("Playful Chicobo scolds you for being a party-pooper.\n");

}

monster_died() {
move_object(clone_object("/players/laera/cforest/OBJ/feather.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"Playful Chicobo plays no more... \n");
return 0; }
