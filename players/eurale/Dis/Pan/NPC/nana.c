#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("nana");
set_race("human");
set_short("Nana");
set_long(
	"  Nana is the children's nursemaid.  She is a shaggy St. Bernard\n"+
	"with thick fur and a loving personality.  She always knows just\n"+
	"what medicine to give for a cough or cold.\n");

set_level(19);
  set_hp(475);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Nana growls......\n");
  load_chat("Nana sniffs your leg......\n");
set_a_chat_chance(20);
  load_a_chat("Nana barks... WOOF   WOOF.....\n");
  load_a_chat("\nNana BITES you on the leg.....\n\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
