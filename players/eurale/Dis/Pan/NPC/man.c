#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("man");
set_alias("englishman");
set_race("human");
set_short("Englishman");
set_long(
	"  This Englishman is just one of the local blokes.  He's dressed\n"+
	"in comfortable tweed and is home to rest from a hard day at the\n"+
	"job.\n");

set_level(18);
  set_hp(450);
  set_al(50);
  set_wc(26);
  set_ac(14);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("The Englishman relaxes in his chair....\n");
set_a_chat_chance(15);
  load_a_chat("The Englishman bellows: How dare you intrude like this?\n");

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,this_object());
}
