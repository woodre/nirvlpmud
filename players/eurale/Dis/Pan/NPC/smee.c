#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("smee");
set_race("human");
set_short("Smee");
set_long(
	"  Smee is the trusted first mate of Captain Hook.  He is a\n"+
	"short, portly fellow who wears a striped shirt and a stocking\n"+
	"cap with a tassle.  His wire-rimmed spectacles sit way down\n"+
	"on his fat, red nose.\n");

set_level(19);
  set_hp(475);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Smee watches you closely......\n");
set_a_chat_chance(20);
  load_a_chat("Smee WHACKS you with a belaying pin....\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
