/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("imp");
set_alias("sea imp");
set_race("creature");
set_short(HIR+"Sea Imp"+NORM);
set_long(
	"This sea imp looks like a bright red humanoid two feet tall\n"+
	"with a protruding pot belly, clawed feet and hands, and a\n"+
	"pointed tail.  It has long ears, curved horns, and a huge nose\n"+
	"that droops over a grinning mouth filled with tiny teeth.  It's\n"+
	"eyes and skin are bright red.\n");

set_level(20);
set_hp(500);
set_al(-200);
set_wc(30);
set_ac(17);
set_aggressive(1);

set_chat_chance(15);
  load_chat("\nThe imp groans....\n");
  load_chat("\nThe imp SCREAMS.....\n");
  load_chat("\nThe imp cackles...\n");

set_chance(15);
set_spell_dam(random(20));
set_spell_mess1("The imp "+HIR+"WICKEDLY SLASHES"+NORM+" out.\n");
set_spell_mess2("The imp "+HIR+"WICKEDLY SLASHES"+NORM+" you.\n");

gold = clone_object("obj/money");
gold->set_money(3000 + random(2000));
move_object(gold,this_object());
}
