#include "/players/laera/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chicobo");
set_alias("chick");
set_alt_name("sing");
set_race("bird");
set_short(HIY+"Singing Chicobo"+OFF);
set_long(
"The soft, lilting chirping heard throughout the forest comes from this\n"+
"little yellow bird.  Serene and content, it sings soft harmonic\n"+
"melodies that echo through the forest.\n");

set_level(7);
set_hp(105);
set_al(0);
set_wc(11);
set_ac(6);
set_heal(4,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
load_chat("The chicobo sits happily on a rock and sings.\n");
set_a_chat_chance(10);
load_a_chat("Singing Chicobo looks surprised and stops singing.\n");

}

monster_died() {
move_object(clone_object("/players/laera/cforest/OBJ/feather.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"The fat lady has sung for Shy Chicobo... \n");
return 0; }
