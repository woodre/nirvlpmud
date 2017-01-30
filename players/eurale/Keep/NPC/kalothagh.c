/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("kalothagh");
set_alias("fish");
set_race("creature");
set_short(GRN+"Kalothagh"+NORM);
set_long(
	"The kalothagh is a plump fish resembling a pin cushion.  It's\n"+
	"body is covered with foot-long poisonous spines.  It's scales\n"+
	"are mottled with dull splotches of green and brown.  It has\n"+
	"small black eyes that bulge from the top of it's head, trans-\n"+
	"lucent fins, a dark, fan-like tail and a smooth pink belly.\n"+
	"It's sharp teeth protrude from it's mouth to form a small beak.\n");

set_level(20);
set_hp(490 + random(100));
set_al(0);
set_wc(30 + random(11));
set_ac(17);
set_aggressive(0);

set_chat_chance(8);
  load_chat("The kalothagh swims slowly in circles.....\n");

set_chance(11);
set_spell_dam(12 + random(15));
set_spell_mess1(
  GRN+"The giant fish attacks in a FRENZY!\n"+NORM);
set_spell_mess2(
  GRN+"The giant fish attacks you in a FRENZY!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(4400 + random(200));
move_object(gold,this_object());
}
