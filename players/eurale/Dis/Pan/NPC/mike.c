#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("michael");
set_alias("mike");
set_alt_name("michael darling");
set_race("human");
set_short("Michael Darling");
set_long(
	"  The youngest of the Darling childen.  Michael is 4 years \n"+
	"old.  He has brown hair, brown eyes and always carries his\n"+
	"teddy bear with him wherever he goes.\n");

set_level(15);
  set_hp(225);
  set_al(100);
  set_wc(20);
  set_ac(12);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Michael sniffs......\n");
  load_chat("Michael grins from ear to ear...\n");
set_a_chat_chance(10);
  load_a_chat("Michael ducks.....\n");
  load_a_chat("Michael spits at you......\n");

gold = clone_object("obj/money");
gold->set_money(875);
move_object(gold,this_object());
}
