/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("horax");
set_race("creature");
set_short(HIR+"Horax"+NORM);
set_long(
	"The Horax is an insectoid creature.  It is 2 feet long and\n"+
	"has 12 legs and small powerful mandibles.  Tough chitinous\n"+
	"plates cover it's back.  It's legs end in strong grippers,\n"+
	"able to hold firmly to nearly any surface.  It is very dark\n"+
	"in color, usually a dark blue.\n");

set_level(20);
set_hp(515);
set_al(0);
set_wc(30);
set_ac(20);
set_aggressive(0);

set_chat_chance(15);
  load_chat("The horax hisses.......\n");

set_chance(7);
set_spell_dam(random(35));
set_spell_mess1(
  HIR+"The horax BITES with its strong mandibles.\n"+NORM);
set_spell_mess2(
  HIR+"The horax BITES you with its strong mandibles.\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(4000 + random(500));
move_object(gold,this_object());
}
