/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("eyewing");
set_race("creature");
set_short(BOLD+"Eyewing"+NORM);
set_long(
	"This supernatural creature exists only to serve their dark\n"+
	"masters.  It's body is a fat, egg-shaped ball covered with\n"+
	"matted black fur.  The five-foot-wide body is supported by\n"+
	"a pair of six-foot-long leathery bat wings.  Each wing is\n"+
	"tipped with a set of 3 razor_sharp talons.  An eight-foot-\n"+
	"long rat's tail dangles from the back of the body and has\n"+
	"a small, sharp spur on the end.  The body is dominated by\n"+
	"a bulging, single, four-foot-wide eyeball which is black\n"+
	"with a blood-red pupil.  A vile, blue, acidic liquid con\n"+
	"tinuously oozes from the eye, soiling it's fur.\n");

set_level(20);
set_hp(500 + random(50));
set_al(-200);
set_wc(30 + random(10));
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The eyewing stares....\n");
  load_chat("The leathery wings flap...\n");
set_a_chat_chance(14);
  load_a_chat("\nThe eyewing slashes at you with it's talons..\n");
  load_a_chat("\nYou feel a sting as the spurred tail just misses your face.\n");
  load_a_chat("\nThe eyewing flys out of reach of your attack..\n");

set_chance(9);
set_spell_dam(30);

set_spell_mess1(
  GRN+"\nThe eyewing BLINKS AN ACID TEAR on it's target..\n\n"+NORM);
set_spell_mess2(
  GRN+"\nThe eyewing BLINKS AN ACID TEAR on you!!\n\n"+NORM);

}

monster_died() {
move_object(clone_object("players/eurale/Keep/OBJ/eyewing_tear.c"),
  environment(this_object()));
return 0; }
