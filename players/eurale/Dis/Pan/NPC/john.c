#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("john");
set_alt_name("john darling");
set_race("human");
set_short("John Darling");
set_long(
	"  John is the middle Darling child.  He wears a white night-\n"+
	"shirt and a black top hat.  He also wear glasses.  His freckled\n"+
	"face is always smiling.\n");

set_level(16);
  set_hp(400);
  set_al(75);
  set_wc(22);
  set_ac(13);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("John coughs......\n");
set_a_chat_chance(10);
  load_a_chat("John THWACKS you on the knee.....\n");

gold = clone_object("obj/money");
gold->set_money(890);
move_object(gold,this_object());
}
