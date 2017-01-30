/*  Updated 10/18/01 to conform to /doc/build/RULES/monster.guide  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("disir");
set_alias("disir 3");
set_alt_name("green disir");
set_race("creature");
set_short(HIG+"Green Disir"+NORM);
set_long(
	"This creature stands about 6 feet tall, although it is shorter\n"+
	"because it is hunched over.  Parts of its body are covered\n"+
	"with a natural armor, while other areas show exposed, rubbery\n"+
	"flesh.  Its skin is a pasty green color and its pores exude\n"+
	"a thick coating of slimy gel which is normally polluted with\n"+
	"dirt, debris, and bits of dead flesh.  An aura of stench and\n"+
	"decay hangs around it.\n");

set_level(19);
set_hp(525);
set_al(0);
  set_wc(30 + random(5));
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Disir watches you closely...\n");
  load_chat("A gob of slimy gel drips off the Disir..\n");
  load_chat("The Disir snarls...\n");
set_a_chat_chance(20);
  load_a_chat("\nThe Disir rakes at you with its poisonous claws...\n");
  load_a_chat("\nThe Disir BITES at you....\n");

set_chance(12);
set_spell_dam(25);

set_spell_mess1(
  "\nThe Diser "+BOLD+"* CLAWS *"+NORM+" its target.....\n");
set_spell_mess2(
  "\nThe Diser "+BOLD+"* CLAWS *"+NORM+" you! \n\n");

}

monster_died() {
move_object(clone_object("players/eurale/Keep/OBJ/disir_slime.c"),
  environment(this_object()));
return 0; }
