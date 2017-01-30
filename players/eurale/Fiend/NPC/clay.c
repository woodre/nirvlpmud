#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("clay");
set_alias("golem");
set_alt_name("clay golem");
set_race("creature");
set_short("Clay Golem");
set_long(
	"  This huge clay golem is given life by making a pact with the\n"+
	"devil.  The orginal film 'The Student of Prague' was shot in \n"+
	"1913 while America was at war with Germany and, thus, did not\n"+
	"show much in the United States.  A remake, 'Der Golem', was \n"+
	"shot in 1920 and a Jewish Rabbi gives the golem life.\n");

set_level(20);
  set_hp(550);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
  "\n\n"+
  "The golem "+BOLD+"GRINDS CLAY"+NORM+" in it's attacker's eyes!!\n\n");
set_spell_mess2(
  "\n\nThe golem "+BOLD+"GRINDS CLAY"+NORM+" in your eyes!!\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe golem TURNS TO DUST and as the dust settles, you see a\n"+
  "glint in the darkness....\n\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/emerald.c"),
    environment(this_object()));
return 0; }
