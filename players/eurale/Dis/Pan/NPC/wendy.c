#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("wendy");
set_alt_name("wendy darling");
set_race("human");
set_short("Wendy Darling");
set_long(
	"  Wendy is the oldest of the Darling children and their only\n"+
	"daughter.  She has auburn hair, green eyes and wears a blue\n"+
	"bow in her hair that matches her dress.\n");

set_level(18);
  set_hp(450);
  set_al(100);
  set_wc(26);
  set_ac(15);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Wendy curtseys......\n");
set_a_chat_chance(10);
  load_a_chat("Wendy SCREAMS.....\n");
  load_a_chat("Wendy pokes you in the eye.....\n");

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,this_object());
}
