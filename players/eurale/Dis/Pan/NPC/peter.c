#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("peter pan");
set_alias("peter");
set_alt_name("pan");
set_race("human");
set_short("Peter Pan");
set_long(
	"  Peter Pan is the boy who never grew up.  He has red hair\n"+
	"hazel eyes and is dressed in a brown elf-like suit.  His hat\n"+
	"has a long red feather in it and he carries a short dagger in\n"+
	"belt.\n");

set_level(19);
  set_hp(475);
  set_al(500);
  set_wc(28);
  set_ac(16);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Peter says: I never want to grow up!......\n");
set_a_chat_chance(20);
  load_a_chat("Peter pummels you with his fists.....\n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
