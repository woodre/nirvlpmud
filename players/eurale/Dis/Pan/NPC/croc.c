#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("crocodile");
set_alias("croc");
set_race("creature");
set_short("Crocodile");
set_long(
	"  This dark green reptile with the spiney back cruises through\n"+
	"the lagoon looking for prey.  The clock that he swallowed gives\n"+
	"off a warning message..... so beware.\n");

set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(1);

set_chat_chance(15);
  load_chat("tick....tock....tick....tock....tick....tock\n");
set_a_chat_chance(10);
  load_a_chat("Jaws SNAP.......\n");

set_chance(10);
set_spell_dam(60);

set_spell_mess1(
  "\n\nThe crodile bites........\n\n");
set_spell_mess2(
  "\n\nThe crocodile BITES you.......\n\n");

gold = clone_object("obj/money");
gold->set_money(random(250)+4875);
move_object(gold,this_object());
}
