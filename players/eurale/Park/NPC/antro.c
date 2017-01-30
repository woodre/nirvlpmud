/*  Antrodemus  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
reset(arg) {

::reset(arg);
if(arg) return;
set_name("antrodemus");
set_race("creature");
set_short("Antrodemus");
set_alias("antro");
set_long(
	"  Antrodemus walked on his hind legs and resembled tyrannosaurus \n"+
	"rex.  He grew to a length of 30 feet and hunted other animals. \n"+
	"He could open his mouth wide enough to swallow small animals \n"+
	"whole. \n");
set_level(21);
set_hp(675);
set_al(-1);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30);
set_ac(17);


set_chat_chance(15);
  load_chat("Eyes staring at you blankly...... \n");
set_a_chat_chance(15);
  load_a_chat("\n\nThe antromedus SNAPS at you.. \n\n");


set_chance(10);
set_spell_dam(35);
set_spell_mess1(
  "\n\n"+BOLD+"CHOMP"+NORM+".... antromedus bites his prey.\n\n");
set_spell_mess2(
  "\n\n"+BOLD+"CHOMP"+NORM+".... the antromedus bites you.\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "With a "+BOLD+"DEATH CRY"+NORM+" the antrodemus falls....\n"+
  "and you notice the beautiful and rugged skin that you might\n"+
  "be able to strip off and either use or sell....\n\n");
return 0; }
