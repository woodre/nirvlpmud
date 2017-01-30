/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("wyndlass");
set_race("creature");
set_short(BOLD+"Wyndlass"+NORM);
set_long(
	"  The wyndlass is a tentacled horror.  It looks something like\n"+
	"a giant, black octopus with no fewer than ten tentacles.  Each\n"+
	"of these whiplike limbs is over 25 feet long and covered with\n"+
	"keen barbs that sink deep into the flesh of prey.  The tendrils\n"+
	"attach to the body in two clusters of 5 limbs each.  Between\n"+
	"the clusters are the creature's three glowing blue eyes and\n"+
	"it's powerful beak.\n");

set_level(19);
set_hp(550);
set_al(0);
set_wc(30);
set_ac(17);
set_aggressive(1);

set_chat_chance(8);
  load_chat("The tentacles search the water carefully in all directions..\n");
  load_chat("The glowing eyes look up at you from the water...\n");
set_a_chat_chance(15);
  load_a_chat("\nThe tentacle barbs DIG into your flesh...\n\n");
  load_a_chat("\nA huge tentacle RAKES your back.....\n\n");

set_chance(10);
set_spell_dam(random(20));
set_spell_mess1("A giant tentacle just misses your face.\n");
set_spell_mess2(BOLD+"A giant tentacle SLAPS you across the face.\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(3800 + random(600));
move_object(gold,this_object());
}
