/*  Triceratops  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg) {

::reset(arg);
if(arg) return;
set_name("triceratops");
set_alias("baby");
set_race("creature");
set_short(GRN+"baby triceratops"+NORM);
set_long(
	"  Triceratops was one of the last dinosaurs to appear.  It had \n"+
	"three horns, a smaller one on it's nose and two longer ones on \n"+
	"its head.  The longer horns were almost 3 feet in length. \n"+
	"Triceratops was 30 feet long and had a reputation as a savage \n"+
	"fighter.  This baby is still too young to be too deadly, right?\n");

set_level(18);
set_hp(400);
set_al(0);
set_wc(27);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
set_spell_dam(30);
set_spell_mess1(
  "\nThe baby butts its target hard.....\n\n");
set_spell_mess2(
  "\n\nThe baby butts you hard...\n\n");

}

monster_died() {
  move_object(clone_object("/players/eurale/Park/OBJ/babyrexskin"),
    environment(this_object()));
  return 0; }
