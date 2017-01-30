/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("minion");
set_alias("fire");
set_alt_name("minion 2");
set_race("creature");
set_short(HIR+"Fire Minion"+NORM);
set_long(
	"This is a fearsome creature, apparently from the elemental plane\n"+
	"of fire.  His body is composed of living flame, and although\n"+
	"they can assume any form they wish, the most common is that of a\n"+
	"large humanoid, complete with fangs and horns.\n");

set_level(20);
set_hp(600);
set_al(0);
set_wc(30 + random(8));
set_ac(17);
set_heal(random(10),random(15));
set_aggressive(1);

set_chat_chance(15);
  load_chat("The flames flicker.....\n");
set_a_chat_chance(15);
  load_a_chat("The flames burn your cheek....\n");
  load_a_chat("With a sweep, the hair is burned off your arm...\n");
  load_a_chat("You smell burning flesh....\n");

set_chance(5 + random(5));
set_spell_dam(15 + random(20));
set_spell_mess1(
  HIC+"The elemental minion changes color and LASHES OUT!\n"+NORM);
set_spell_mess2(
  HIC+"The elemental minion changes color and LASHES OUT at you!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(4000 + random(1200));
move_object(gold,this_object());
}

#include "/players/eurale/closed/aggro_hb.h"
