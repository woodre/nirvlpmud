/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("disir");
set_alias("sentry 1");
set_alt_name("sentry");
set_race("creature");
set_short(BOLD+"Disir Sentry"+NORM);
set_long(
	"This is one of the Shaman's personal warriors.  He has been\n"+
	"conditioned to fight to the death.  His darkened flesh and\n"+
	"armor are the result of chemical concoctions made up by the\n"+
	"Shaman and applied repeatedly.  Do not underestimate this \n"+
	"being of the darkness.\n");

set_level(20);
set_hp(600);
set_al(-50);
set_wc(30 + random(7));
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Sentry watches you closely...\n");
  load_chat("A gob of slimy gel drips off the Disir..\n");
  load_chat("The sentry mumbles: Leave at once..\n");
set_a_chat_chance(20);
  load_a_chat("\nThe Sentry rakes at you with it's poisonous claws...\n");
  load_a_chat("\nThe Sentry easily sidesteps your attack...\n");
  load_a_chat("\nThe Sentry SNAPS at you with it's yellow teeth..\n");

set_chance(15);
set_spell_dam(35);
set_spell_mess1(
  "\nThe Disir "+BOLD+"* CLAWS *"+NORM+" it's target.....\n");
set_spell_mess2(
  "\nThe Disir "+BOLD+"* CLAWS *"+NORM+" you! \n\n");

}

monster_died() {
move_object(clone_object("players/eurale/Keep/OBJ/disir_slime.c"),
  environment(this_object()));
return 0; }
